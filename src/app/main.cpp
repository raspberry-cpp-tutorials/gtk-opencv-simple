#include "main-window.hpp"

int main (int argc, char *argv[]) {

	auto app = Gtk::Application::create(argc, argv, "raspberry-cpp-gtk-opencv");

    MainWindow mainWindow;

    return app->run(mainWindow);
}