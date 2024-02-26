target_sources(quick_sort_lib 
	PRIVATE
		quick_sort.cpp
	PUBLIC
		quick_sort.hpp
)

target_include_directories(quick_sort_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)
