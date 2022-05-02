cmake_minimum_required(VERSION 3.15)
project( vector-container )
# Enable C++17
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)
add_executable( vector-container vector-container.cpp )
add_custom_target(run)
add_custom_command( TARGET run
	POST_BUILD COMMAND ./vector-container)
