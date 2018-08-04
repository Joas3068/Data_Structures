cmake_minimum_required(VERSION 2.8.9)
project(Data_Structs)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)



file(GLOB SOURCES "src/*.cpp")

#set(input_csv &{CMAKE_CURRENT_SOURCE_DIR}/patientData2270.csv)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/patientData2270.csv
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})



add_executable(Data_Structs ${SOURCES})