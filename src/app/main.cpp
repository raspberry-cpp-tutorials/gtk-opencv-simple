#include "main-window.hpp"

int main (int argc, char *argv[]) {
	auto app = Gtk::Application::create(argc, argv, "ch.agl-developpement.raspberry-cpp-gtk-opencv");
	MainWindow mainWindow(300, 300);
	return app->run(mainWindow);
}
