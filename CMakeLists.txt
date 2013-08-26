project (gsTest)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set (gsTest_SRCS
	src/main.cpp
	src/Application.cpp
	src/LevelState.cpp
)

set (gsTest_LIBS
	sfml-graphics
	sfml-window
	sfml-system
)

add_executable(a ${gsTest_SRCS})
target_link_libraries(a ${gsTest_LIBS})