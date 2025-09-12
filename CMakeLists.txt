cmake_minimum_required(VERSION 3.10)

project(handmade-penguin)

add_executable(handmade-penguin main.cpp)

install(TARGETS handmade-penguin RUNTIME DESTINATION bin)
