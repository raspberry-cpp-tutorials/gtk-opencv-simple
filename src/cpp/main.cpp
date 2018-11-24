#include <iostream>

#include "main-window.hpp"

int main (int argc, char *argv[]) {
	std::cout << "01" << std::endl;
	auto app = Gtk::Application::create(argc, argv, "ch.agl-developpement.cpp-tutorial.raspberry-cpp-gtk-opencv");
	MainWindow mainWindow(300, 300);
	return app->run(mainWindow);
}
