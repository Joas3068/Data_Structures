cmake_minimum_required(VERSION 2.8.9)
project(Data_Structs)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(data)

link_directories(src data)

set(SOURCES src/FinalProject.cpp src/minHeap.cpp src/priorityQ.cpp src/priorityQueueLL.cpp)

file(GLOB SOURCES "src/*.cpp")


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data/patientData2270.csv
     DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/data)

add_executable(Data_Structs ${SOURCES})