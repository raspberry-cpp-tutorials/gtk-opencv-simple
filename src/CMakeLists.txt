# src/CMakeLists.txt
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

# Project name and current version
project(rascam VERSION 0.1 LANGUAGES CXX)

# Enable general warnings
# See http://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Use 2014 C++ standard.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Must use GNUInstallDirs to install libraries into correct locations on all platforms:
include(GNUInstallDirs)

# Pkg_config is used to locate header and files for dependency libraries:
find_package(PkgConfig)

# Defines variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES.
pkg_check_modules(GTKMM gtkmm-3.0) 
link_directories( ${GTKMM_LIBRARY_DIRS} )
include_directories( ${GTKMM_INCLUDE_DIRS} )

# OpenCV can be linked in a more standard manner:
find_package( OpenCV REQUIRED )

# Compile files:
add_executable(rascapp
    cpp/main.cpp	
    cpp/main-window.cpp
	cpp/camera-drawing-area.cpp
)

# Add folder with all headers:
target_include_directories(rascapp PRIVATE hpp)

# Link files:
target_link_libraries(rascapp
   ${GTKMM_LIBRARIES}
   ${OpenCV_LIBS}
)

# Apple requires a bundle to add a Info.plist file that contains the required
# permissions to access some restricted resources like the camera:
if (APPLE)
	set_target_properties(rascapp PROPERTIES
	  MACOSX_BUNDLE TRUE
	  MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/res/Info.plist
	)
endif()