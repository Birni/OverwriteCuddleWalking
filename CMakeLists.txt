cmake_minimum_required (VERSION 3.8)

SET (PATH_ARK_API1 "C:/Users/Matth/Documents/arkplugins/ark-api")


project (OverwriteCuddleWalking CXX)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3")

add_library(OverwriteCuddleWalking SHARED )

set_target_properties( OverwriteCuddleWalking PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_library(ark_api STATIC IMPORTED)
set_target_properties(ark_api PROPERTIES
  IMPORTED_LOCATION ${PATH_ARK_API1}/lib/ArkApi.lib
 # IMPORTED_LOCATION ${PATH_ARK_API1}/lib/MinHook.x64.lib
  INTERFACE_INCLUDE_DIRECTORIES ${PATH_ARK_API1}/version/Core/Public
)

#ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

set_target_properties(OverwriteCuddleWalking PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(OverwriteCuddleWalking ark_api)

add_subdirectory(src)



macro(GroupSources curdir)
   file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)
   foreach(child ${children})
          if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
                  GroupSources(${curdir}/${child})
          else()
                  string(REPLACE "/" "\\" groupname ${curdir})
            source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
          endif()
   endforeach()
endmacro()
   

GroupSources(src)