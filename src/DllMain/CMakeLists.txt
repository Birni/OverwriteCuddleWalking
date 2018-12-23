cmake_minimum_required (VERSION 3.8)

set( SOURCE_FILES
   ${CMAKE_CURRENT_SOURCE_DIR}/OverwriteCuddleWalking.cpp
)
set( HEADE_FILES
   ${CMAKE_CURRENT_SOURCE_DIR}/OverwriteCuddleWalking.h
)

target_sources(OverwriteCuddleWalking
    PRIVATE
		${SOURCE_FILES}
	PUBLIC
		${HEADE_FILES}
)

source_group("DllMain\\test" ${SOURCE_FILES} ${HEADE_FILES} )
