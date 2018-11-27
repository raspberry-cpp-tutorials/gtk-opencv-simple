#include <stdio.h>
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

#include "camera-drawing-area.hpp"

CameraDrawingArea::CameraDrawingArea():
videoCapture(0) {
	// Lets refresh drawing area very now and then.
	timeoutConnection = Glib::signal_timeout().connect(sigc::mem_fun(*this, &CameraDrawingArea::everyNowAndThen), 100);
}

CameraDrawingArea::~CameraDrawingArea() {
	timeoutConnection.disconnect();
}

/**
 * Called every time the widget has its allocation changed.
 */
void CameraDrawingArea::on_size_allocate (Gtk::Allocation& allocation) {
	// Call the parent to do whatever needs to be done:
	DrawingArea::on_size_allocate(allocation);
	
	// Remember the new allocated size for future operations.
	width = allocation.get_width();
	height = allocation.get_height();
}

/**
 * Every now and then, we invalidate the whole Widget rectangle,
 * forcing a complete refresh.
 */
bool CameraDrawingArea::everyNowAndThen() {
	auto win = get_window();
	if (win) {
		Gdk::Rectangle r(0, 0, width, height);
		win->invalidate_rect(r, false);
	}
	
	// Don't stop calling me:
	return true;
}

/**
 * Called every time the widget needs to be redrawn.
 * This happens when the Widget got resized, or obscured by
 * another object, or every now and then.
 */
bool CameraDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
	
	// Prevent the drawing if size is 0:
	if (width == 0 || height == 0) {
		return true;
	}

	// Capture one image from camera:
	videoCapture.read(webcam);
	
	// Resize it to the allocated size of the Widget.
	resize(webcam, output, cv::Size(width, height), 0, 0, cv::INTER_LINEAR);

	// Initializes a pixbuf sharing the same data as the mat:
	Glib::RefPtr<Gdk::Pixbuf> pixbuf =
		Gdk::Pixbuf::create_from_data((guint8*)output.data,
									  Gdk::COLORSPACE_RGB,
									  false,
									  8,
									  output.cols,
									  output.rows,
									  (int) output.step);

	// Display
	Gdk::Cairo::set_source_pixbuf(cr, pixbuf);
	cr->paint();
	
	// Don't stop calling me.
	return true;
}
