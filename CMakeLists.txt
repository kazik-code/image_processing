cmake_minimum_required(VERSION 3.20)
project(image_processing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" ON)

add_library(processing_lib INTERFACE)
target_include_directories(processing_lib
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(processing_lib INTERFACE
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
    -Wshadow
)

if(ENABLE_SANITIZERS)
    target_compile_options(processing_lib INTERFACE
      -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(processing_lib INTERFACE -fsanitize=address,undefined)
endif()

add_executable(${PROJECT_NAME}
    source/main.cpp
    source/ppm_P3_generator.cpp
    source/ppm_P3_filter.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE processing_lib)
