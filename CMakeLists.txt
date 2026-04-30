cmake_minimum_required(VERSION 3.10)
project(FormatterProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(formatter_lib)
add_subdirectory(formatter_ex_lib)
add_subdirectory(solver_lib)
add_subdirectory(hello_world)
add_subdirectory(solver)

if(BUILD_TESTS)
  enable_testing()

  set(CMAKE_COMPILE_WARNING_AS_ERROR OFF)

  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(
      -Wno-error
      -Wno-error=maybe-uninitialized
      -Wno-maybe-uninitialized
    )
  endif()

  add_subdirectory(third-party/gtest)

  file(GLOB TEST_SOURCES tests/*.cpp)

  add_executable(check ${TEST_SOURCES})

  target_link_libraries(check
   solver_lib
  formatter_ex
  formatter
  gtest_main
  )

  add_test(NAME check COMMAND check)
endif()
