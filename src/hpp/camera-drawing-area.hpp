#ifndef CAMERA_DRAWING_AREA_H
#define CAMERA_DRAWING_AREA_H

#include <opencv2/highgui.hpp>
#include <gtkmm.h>

class CameraDrawingArea :
public Gtk::DrawingArea {
public:
    CameraDrawingArea();
    virtual ~CameraDrawingArea();
    
protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
	void on_size_allocate (Gtk::Allocation& allocation) override;
	
	bool everyNowAndThen();

private:
	sigc::connection timeoutConnection;
	cv::VideoCapture videoCapture;
	cv::Mat webcam;
	cv::Mat output;
	int width, height;
};
#endif
