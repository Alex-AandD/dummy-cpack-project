cmake_minimum_required(VERSION 3.25.1)
project(dummyproj VERSION 0.1)

include(GNUInstallDirs)

set(CMAKE_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR}/dummy)

add_library(dummy src/hello.cc)
set_target_properties(dummy PROPERTIES
                    VERSION ${dummyproj_VERSION_MAJOR}.${dummyproj_VERSION_MINOR}
                    SOVERSION ${dummyproj_VERSION_MAJOR}.${dummyproj_VERSION_MINOR})

target_include_directories(dummy
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

#install the library
# LIBRARY DESTINATION 
install(TARGETS dummy
    EXPORT dummyTarget
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES include/hello.hh DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT dummyTarget
    FILE dummyTarget.cmake
    NAMESPACE dummy::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dummy
)