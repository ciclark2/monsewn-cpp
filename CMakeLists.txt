cmake_minimum_required(VERSION 3.12)

project(monsewn)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(REQUIRES boost/1.72.0
                REQUIRES glew/2.1.0@bincrafters/stable
                REQUIRES glfw/3.3.2@bincrafters/stable
                REQUIRES gtest/1.10.0
                REQUIRES imgui/1.76
                REQUIRES libtorrent/1.2.3
                BASIC_SETUP
                BUILD missing)

add_subdirectory(imgui)
add_subdirectory(torrent)

include_directories(".")

add_subdirectory(monsewn)