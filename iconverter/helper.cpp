#include "helper.h"

void LogInit(std::string &name)
{
	name +="_%N.log";
	logging::add_file_log
	(
		keywords::file_name = name,                                        /*< file name pattern >*/
		keywords::rotation_size = 10 * 1024 * 1024,                                   /*< rotate files every 10 MiB... >*/
		keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
		keywords::format = "[%TimeStamp%]: %Message%"                                 /*< log record format >*/
	);

	logging::core::get()->set_filter
	(
		logging::trivial::severity >= logging::trivial::info
	);
}

void slice_image(const fipImage &image, fipImages &images, const vCoord &vX, const vCoord &vY) {
	try {
		UINT x0 = vX.at(0), y0 = vY.at(0);
		auto pos_x = vX.begin();
		pos_x++;
		for (; pos_x != vX.end(); ++pos_x) {
			auto &x1 = *pos_x;
			auto pos_y = vY.begin();
			pos_y++;
			for (; pos_y != vY.end(); ++pos_y) {
				auto &y1 = *pos_y;
				fipImage *pimg = new fipImage();
				image.copySubImage(*pimg, x0, y0, x1, y1);
				images.push_back(pimg);
				y0 = y1;
			}
			y0 = 0;
			x0 = x1;
		}
	}
	catch (std::exception& e) {}
	catch (...) {}
}

void slice_image(const fipImage &image, fipImages &images, UINT h_parts, UINT v_parts, RECT rect) {
	try
	{
		if (!h_parts) return;
		if (!v_parts) return;
		UINT w_p = h_parts, h_p = v_parts;
		UINT w = rect.right ? rect.right : image.getWidth();
		UINT h = rect.bottom ? rect.bottom : image.getHeight();
		UINT w_parts_len = w / h_parts;
		UINT h_parts_len = h / v_parts;
		vCoord vX, vY;
		vX.push_back(rect.left);
		vY.push_back(rect.top);
		UINT i = 1;
		while (--w_p) {
			vX.push_back(i * w_parts_len);
			i++;
		}
		i = 1;
		while (--h_p) {
			vY.push_back(i * h_parts_len);
			i++;
		}
		vX.push_back(w);
		vY.push_back(h);
		slice_image(image, images, vX, vY);
	}
	catch (std::exception& e) {}
	catch (...) {}
}
