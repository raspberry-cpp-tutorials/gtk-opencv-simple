#include <iostream>

#include "main-window.hpp"

int main (int argc, char *argv[]) {
	// https://stackoverflow.com/questions/16818427/write-to-mac-os-x-console-logs-from-shell-script-or-command-line
	/*
	setlogmask (LOG_UPTO (LOG_NOTICE));
	openlog ("rascapp", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
	syslog (LOG_NOTICE, "rascapp started by user %d", getuid ());
	std::cout << "Hello world" << std::endl;
	*/
	auto app = Gtk::Application::create(argc, argv, "ch.agl-developpement.cpp-tutorial.raspberry-cpp-gtk-opencv");
	MainWindow mainWindow(300, 300);
	return app->run(mainWindow);	
}
