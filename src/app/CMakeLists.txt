# src/app
project( fpv )

# GTKMM has to be linked/included via pkg_config:
find_package(PkgConfig)
# Defines variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES.
pkg_check_modules(GTKMM gtkmm-3.0) 
link_directories( ${GTKMM_LIBRARY_DIRS} )
include_directories( ${GTKMM_INCLUDE_DIRS} )

# OpenCV can be linked in a more standard manner:
find_package( OpenCV REQUIRED )

# Compile files:
add_executable(fpv 
    main.cpp
	
    main-window.cpp
    main-window.hpp
	
	camera-drawing-area.cpp
	camera-drawing-area.hpp
)

# Link files:
target_link_libraries(fpv
   ${GTKMM_LIBRARIES}
   ${OpenCV_LIBS}  
)

# Apple requires a bundle to add a Info.plist file that contains the required
# permissions to access some restricted resources like the camera:
if (APPLE)
	set_target_properties(fpv PROPERTIES
	  MACOSX_BUNDLE TRUE
	  MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist
	)
endif()