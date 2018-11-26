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

# Pkg_config is used to locate headers and files for dependency libraries:
find_package(PkgConfig)

# Defines variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES.
pkg_check_modules(GTKMM gtkmm-3.0)

# Adds GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS to the list of folders the
# compiler and linker will use to look for dependencies:
link_directories( ${GTKMM_LIBRARY_DIRS} )
include_directories( ${GTKMM_INCLUDE_DIRS} )

# Declares a new executable target called rascapp
# and lists the files to compile for it:
add_executable(rascapp
    cpp/main.cpp	
	
    cpp/main-window.cpp
    hpp/main-window.hpp
)

# Adds the folder with all headers:
target_include_directories(rascapp PRIVATE hpp)

# Link files:
target_link_libraries(rascapp
   ${GTKMM_LIBRARIES}  
)