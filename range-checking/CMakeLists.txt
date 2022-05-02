cmake_minimum_required(VERSION 3.15)
project( range-checking )
# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)
add_executable( range-checking range-checking.cpp )
add_custom_target(run)
add_custom_command( TARGET run
	POST_BUILD COMMAND ./range-checking)
