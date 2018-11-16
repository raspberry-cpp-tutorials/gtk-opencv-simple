# src/app
project( fpv )

# GTKMM has to be linked/included via pkg_config:
find_package(PkgConfig)
# Defines variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES.
pkg_check_modules(GTKMM gtkmm-3.0) 
link_directories( ${GTKMM_LIBRARY_DIRS} )
include_directories( ${GTKMM_INCLUDE_DIRS} )

# Compile files:
add_executable(fpv 
    main.cpp
	
    main-window.cpp
    main-window.hpp
)

# Link files:
target_link_libraries(fpv
   ${GTKMM_LIBRARIES}  
)