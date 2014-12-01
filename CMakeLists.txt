cmake_minimum_required(VERSION 2.8.12)

# guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()



project(IRITTEST C CXX)

find_package(VTK 6.1 REQUIRED NO_MODULE)
include(${VTK_USE_FILE})

# IRIT
include_directories( $ENV{IRIT_DIR}/include 
${CMAKE_CURRENT_SOURCE_DIR})

#link_directories($ENV{IRIT_DIR}/lib/)
set(IRIT_LIBRARIES $ENV{IRIT_DIR}/lib/irit.lib)

add_definitions(-D__WINNT__)
add_executable(irittest main.cpp areaFunction.cpp)



target_link_libraries(irittest ${VTK_LIBRARIES} ${IRIT_LIBRARIES})







