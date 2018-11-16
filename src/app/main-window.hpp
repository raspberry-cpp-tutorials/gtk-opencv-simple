#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow();
    virtual ~MainWindow() = default;
    
protected:
    void on_button_clicked();
    Gtk::Button m_button;
    Gtk::Box m_box;
	Gtk::Label m_label1, m_label2;
};

#endif
