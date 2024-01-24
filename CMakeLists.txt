cmake_minimum_required(VERSION 3.26)
project(nya C)

include_directories(./include ./helpers)

set(CMAKE_C_STANDARD 23)

file(GLOB NYAN_SRC CONFIGURE_DEPENDS "include/*.h" "src/*.c" "helpers/*.c" "helpers/*.h")

add_executable(nya ${NYAN_SRC})

set(CMAKE_BUILD_TYPE Debug)

install(TARGETS nya DESTINATION bin)