cmake_minimum_required(VERSION 4.0)
project(gitfetch)

set(CMAKE_CXX_STANDARD 23)

add_executable(gitfetch
        main.cpp
        parse/Parser.cpp
        disp/Display.cpp
        disp/unix/BaseDisplay.cpp
)

target_include_directories(gitfetch
        PUBLIC ${CMAKE_SOURCE_DIR}
)