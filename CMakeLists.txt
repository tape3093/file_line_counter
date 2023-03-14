cmake_minimum_required(VERSION 3.16)
project(line_counter CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(line_counter
    main.cpp
    line_counter.cpp
    line_counter.h
)

find_package(Threads REQUIRED)
target_link_libraries(line_counter PRIVATE Threads::Threads)