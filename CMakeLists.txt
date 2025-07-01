cmake_minimum_required(VERSION 3.10)

project(VESSS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(vesss ${SOURCES})

target_include_directories(vesss PRIVATE src)
target_include_directories(vesss PRIVATE include)

if(MSVC)
    target_compile_options(vesss PRIVATE /W4 /WX)
else()
    target_compile_options(vesss PRIVATE -Wall -Wextra -Werror -pedantic)
endif()