cmake_minimum_required(VERSION 3.31)

project(CWillem VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} 
    src/main.c
    src/chunk.c
    src/memory.c
    src/debug.c
    src/value.c
    src/vm.c
)

target_include_directories(${PROJECT_NAME} PUBLIC include)