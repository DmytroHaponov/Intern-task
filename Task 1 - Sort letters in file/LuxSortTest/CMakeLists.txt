cmake_minimum_required(VERSION 2.8.12)
project (Gtests_for_task1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

INCLUDE_DIRECTORIES(D:\\temp\\Task 1 - Sort letters in file\\LuxSortTest\\gtest-1.7.0\\include\\gtest\\)
INCLUDE_DIRECTORIES(D:\\temp\\Task 1 - Sort letters in file\\LuxSortTest\\gtest-1.7.0\\include\\gtest\\internal\\)

INCLUDE_DIRECTORIES(D:\\temp\\Task 1 - Sort letters in file\\LuxSortTest\\gtest-1.7.0\\src\\)

add_executable (main main.cpp)
