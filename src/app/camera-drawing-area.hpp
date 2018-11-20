
#ifndef AUTO_VISEUR_H
#define AUTO_VISEUR_H

#include <opencv2/highgui.hpp>
#include <gtkmm.h>
#include <thread>
#include <mutex>

#include "image-capture-service.hpp"
#include "car-service.hpp"
#include "event-bus-service.hpp"
#include "video-stream-writer.hpp"

class CameraDrawingArea :
public Gtk::DrawingArea {
public:
    static const int INITIAL_WIDTH = 480;
    static const int INITIAL_HEIGHT = 320;
    CameraDrawingArea();
    virtual ~CameraDrawingArea() = default;
    
protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
	void on_size_allocate (Gtk::Allocation& allocation) override;
	void on_capture();

private:
	int width;
	int height;
	EventBusService<ImageCapturedEvent> imageCapturedBus;
	EventBusService<MakeVideoStreamEvent> makeVideoStreamBus;
	bool makingVideoStream;
	Pango::FontDescription fontDescription;
	ImageCaptureService* imageCaptureService;
	CarService* carService;
	VideoStreamWriter* videoStreamWriter;
	cv::Mat lastCapture;
	std::chrono::time_point<std::chrono::system_clock> timeOfLastFrame;
	Glib::Dispatcher captureDispatcher;
	Glib::RefPtr<Gdk::Pixbuf> pixbuf;
};