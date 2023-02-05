cmake_minimum_required(VERSION 3.22)
project(Library_Managment_System C)

set(CMAKE_C_STANDARD 99)
set(Headers app.h LinkedList.h Types.h)

add_executable(Library_Managment_System ${PROJECT_SOURCE_DIR} / main.c app.c LinkedList.c)

