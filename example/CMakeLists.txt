cmake_minimum_required(VERSION 3.2)

project(nmea_example)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

file(GLOB SRC
        "${CMAKE_CURRENT_SOURCE_DIR}/../src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(nmea_example ${SRC})