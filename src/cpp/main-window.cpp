#include "main-window.hpp"
#include <syslog.h>

MainWindow::MainWindow(int width, int height):
probablyInFullScreen(false),
m_button("Hello World"),
m_box(Gtk::ORIENTATION_VERTICAL),
m_label1("First Label") {
	// Configure this window:
	this->set_default_size(width, height);

	// Connect the 'click' signal and make the button visible:
	m_button.signal_clicked().connect(
	    sigc::mem_fun(*this, &MainWindow::buttonClick));
	m_button.show();
	
	// Make the first label visible:
	m_label1.show();

	// Make the second label visible:
	cameraDrawingArea.show();
	
	// Pack all elements in the box:
	m_box.pack_start(m_button, Gtk::PACK_SHRINK);
	m_box.pack_start(m_label1, Gtk::PACK_SHRINK);
	m_box.pack_start(cameraDrawingArea, Gtk::PACK_EXPAND_WIDGET);

	// Add the box in this window:
	add(m_box);
	
	// Make the box visible:
	m_box.show();
	
	// Activate Key-Press events
	add_events(Gdk::KEY_PRESS_MASK);
}

void MainWindow::buttonClick() {
	syslog(LOG_NOTICE, "Hello world!");
}

bool MainWindow::on_key_press_event(GdkEventKey* event) {
	switch (event->keyval) {
		// Ctrl + C: Ends the app:
		case GDK_KEY_C:
		case GDK_KEY_c:
			if ((event->state & GDK_CONTROL_MASK) == GDK_CONTROL_MASK) {
				get_application()->quit();
			}
			return true;
			
		// [F] toggles fullscreen mode:
		case GDK_KEY_F:
		case GDK_KEY_f:
			if (probablyInFullScreen) {
				unfullscreen();
				probablyInFullScreen = false;
			} else {
				fullscreen();
				probablyInFullScreen = true;
			}
			return true;
			
		// [esc] exits fullscreen mode:
		case GDK_KEY_Escape:
			unfullscreen();
			probablyInFullScreen = false;
			return true;
	}
	
	return false;
}
