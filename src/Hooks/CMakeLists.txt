cmake_minimum_required (VERSION 3.8)

target_include_directories(OverwriteCuddleWalking
	PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}
)

set( SOURCE_FILES
   ${CMAKE_CURRENT_SOURCE_DIR}/Hooks.cpp
)
set( HEADE_FILES
   ${CMAKE_CURRENT_SOURCE_DIR}/Hooks.h
)

target_sources(OverwriteCuddleWalking
    PUBLIC
		${SOURCE_FILES}
	PUBLIC
		${HEADE_FILES}
)

