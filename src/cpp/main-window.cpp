#include <iostream>
#include "main-window.hpp"

MainWindow::MainWindow(int witdh, int height):
m_button("Hello World"),
m_box(Gtk::ORIENTATION_VERTICAL),
m_label1("First Label"),
m_label2("Second Label"){
	// Configure this window:
	this->set_default_size(witdh, height);

	// Connect the 'click' signal and make the button visible:
	m_button.signal_clicked().connect(
		sigc::mem_fun(*this, &MainWindow::buttonClick));
    m_button.show();
	
	// Make the first label visible:
	m_label1.show();

	// Make the second label visible:
	m_label2.show();
	
	// Pack all elements in the box:
	m_box.pack_start(m_button, Gtk::PACK_SHRINK);
	m_box.pack_start(m_label1, Gtk::PACK_SHRINK);
	m_box.pack_start(m_label2, Gtk::PACK_EXPAND_WIDGET);

	// Add the box in this window:
	add(m_box);
	
	// Make the box visible:
	m_box.show();
}

void MainWindow::buttonClick() {
    std::cout << "Hello World" << std::endl;
}
