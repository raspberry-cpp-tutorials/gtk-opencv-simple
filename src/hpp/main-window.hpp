#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
	MainWindow(int width, int height);
	virtual ~MainWindow() = default;

protected:
	bool on_key_press_event(GdkEventKey* event) override;
    
private:
	void buttonClick();
	bool probablyInFullScreen;
	Gtk::Button m_button;
	Gtk::Box m_box;
	Gtk::Label m_label1, m_label2;
};

#endif
