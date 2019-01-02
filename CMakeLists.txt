cmake_minimum_required(VERSION 3.13)
project(network_test C)

set(CMAKE_C_STANDARD 99)

add_executable(server server.c csapp.c csapp.h)
add_executable(client client.c csapp.c csapp.h)
find_package(Threads REQUIRED)
target_link_libraries(server Threads::Threads)
target_link_libraries(client Threads::Threads)
