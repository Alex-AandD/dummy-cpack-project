cmake_minimum_required(VERSION 3.25.1)
project(dummy VERSION 0.1)

add_library(dummylib src/hello.cc)
set_target_properties(dummylib PROPERTIES
                    VERSION ${dummy_VERSION_MAJOR}.${dummy_VERSION_MINOR}
                    SOVERSION ${dummy_VERSION_MAJOR}.${dummy_VERSION_MINOR})

target_include_directories(dummylib PRIVATE ${CMAKE_SOURCE_DIR}/include)
install(TARGETS dummylib DESTINATION lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include TYPE INCLUDE)