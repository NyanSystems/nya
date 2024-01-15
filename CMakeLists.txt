cmake_minimum_required(VERSION 3.26)
project(nya C)

include_directories(./includes ./helpers)

set(CMAKE_C_STANDARD 23)

file(GLOB nyan_SRC CONFIGURE_DEPENDS "includes/*.h" "src/*.c" "helpers/*.c" "helpers/*.h")

add_executable(nya ${nyan_SRC})

set(CMAKE_BUILD_TYPE Debug)