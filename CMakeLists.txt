cmake_minimum_required(VERSION 3.20)
project(image_processing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(processing_lib INTERFACE)
target_include_directories(processing_lib
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)


option(ENABLE_SANITIZERS "Enable AddressSanitizer and
  UndefinedBehaviorSanitizer" ON)

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


include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME}
    source/main.cpp
    source/ppm_P3_generator.cpp
    source/ppm_P3_filter.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE processing_lib)

add_executable(processing_lib_tests tests/ProcessingTests.cpp)

target_link_libraries(processing_lib_tests PRIVATE
    processing_lib
    GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(processing_lib_tests)
