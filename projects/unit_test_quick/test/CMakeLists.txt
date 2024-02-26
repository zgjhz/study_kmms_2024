set(SOURCES 
	test_quick.cpp
)

add_executable(test_quick ${SOURCES})
target_link_libraries(test_quick 
	gtest_main 
	gmock_main 
	quick_sort_lib
)

add_test(test_quick test_quick)
