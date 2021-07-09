cmake_minimum_required(VERSION 3.20)
project(gtkmm-demo VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-4.0)

link_directories(
    ${GTKMM_LIBRARY_DIRS}
)

include_directories(
    ${GTKMM_INCLUDE_DIRS}
)

add_subdirectory(src)
