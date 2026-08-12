cmake_minimum_required(VERSION 3.20)
project(LeetCodePractice VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>")

# Auto-discover problem files like: "src/problem/1.TwoSum.cpp", "src/problem/2.AddTwoNumbers.cpp", ...
file(GLOB PROBLEM_SOURCES "${CMAKE_SOURCE_DIR}/src/problem/[0-9]*.cpp")

list(SORT PROBLEM_SOURCES)

if(NOT PROBLEM_SOURCES)
  message(WARNING "No problem source files found.")
endif()

add_executable(leetcode_app
  src/main.cpp
  src/ProblemRegistry.cpp
  ${PROBLEM_SOURCES}
 "src/problem/88.merge.cpp" "src/problem/121.maxProfit.cpp")

target_link_libraries(leetcode_app
  PRIVATE
)

target_include_directories(leetcode_app
  PRIVATE
    src
)

set_target_properties(leetcode_app PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:leetcode_app>"
)
