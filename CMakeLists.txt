cmake_minimum_required(VERSION 3.12)

project(monsewn)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_add_remote(NAME bincrafters
                 URL https://api.bintray.com/conan/bincrafters/public-conan)

set(CONAN_REQUIRES_LIST
    REQUIRES boost/1.72.0
    REQUIRES glew/2.1.0@bincrafters/stable
    REQUIRES glfw/3.3.2@bincrafters/stable
    REQUIRES gtest/1.10.0
    REQUIRES imgui/1.76
    REQUIRES libtorrent/1.2.3
    )

set(CONAN_BUILD_LIST
    BUILD MISSING)

if(UNIX AND NOT APPLE)
    list(APPEND ${CONAN_REQUIRES_LIST}
         REQUIRES mesa/20.0.1@bincrafters/stable)
    list(APPEND ${CONAN_BUILD_LIST}
         BUILD mesa)
endif()

conan_cmake_run(${CONAN_REQUIRES_LIST}
                BASIC_SETUP
                ${CONAN_BUILD_LIST}
                )

add_subdirectory(imgui)
add_subdirectory(torrent)

include_directories(".")

add_subdirectory(monsewn)