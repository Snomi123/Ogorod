project(dz2.sort)

target_sources(merge_sort_lib
	PRIVATE
		sort.cpp
	PUBLIC
		sort.hpp
)

target_include_directories(merge_sort_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)

add_executable(dz2.sort main.cpp sort.cpp)