cmake_minimum_required(VERSION 3.15)
project( queue-list-and-deque-benmark )
# Enable C++17
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)
add_executable( queue-list-and-deque-benmark queue-list-and-deque-benmark.cpp )
add_custom_target(run)
add_custom_command( TARGET run
	POST_BUILD COMMAND ./queue-list-and-deque-benmark)
