cmake_minimum_required(VERSION 3.2...3.27.5)

project(study_kmms_2024)

set(CMAKE_CXX_STANDARD 11)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(bubble_sort)
add_subdirectory(bubble_sort_mf)
add_subdirectory(refactoring_and_print)
add_subdirectory(base_theory_p1)
add_subdirectory(base_theory_tasks_p1)
add_subdirectory(obuchaika)
add_subdirectory(quick_sort)
add_subdirectory(unit_test_quick)

set(CMAKE_SUPPRESS_REGENERATION true)
