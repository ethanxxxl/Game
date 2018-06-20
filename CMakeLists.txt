cmake_minimum_required( VERSION 3.8 )

project( Tokenizer )

set( sources
	main.cpp
	ParseCmd.cpp
	Game.cpp
	)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable( run ${sources} )
target_compile_options( run PUBLIC -std=c++17 -g -Wall -Wextra )
target_link_libraries( run -lncurses )
