cmake_minimum_required(VERSION 2.8.9)
project(Data_Structs)

include_directories(include)

#set(SOURCES src/see.c src/LL.c)

file(GLOB SOURCES "src/*.cpp")

set(input_csv &{CMAKE_CURRENT_SOURCE_DIR}/patientData2270.csv)

add_executable(Data_Structs ${SOURCES})