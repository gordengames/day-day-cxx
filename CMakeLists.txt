cmake_minimum_required(VERSION 3.10)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "")
endif()
message(STATUS "CMAKE_EXPORT_COMPILE_COMMANDS: ${CMAKE_EXPORT_COMPILE_COMMANDS}")
message(STATUS "CMAKE_C_COMPILER: ${CMAKE_C_COMPILER}")

project(day-day-cxx CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENTIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX  /permissive-")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
endif()

# find_package(Catch2 CONFIG REQUIRED)

function(add_problem problemid)
    # 01
    # add_executable(${problemid} src/${problemid}/main.cpp src/${problemid}/KString.cpp)
    # 02
    # add_executable(${problemid} src/${problemid}/main.cpp src/${problemid}/KArray.cpp src/${problemid}/KList.cpp)
    # 03
    add_executable(${problemid} src/${problemid}/main.cpp src/${problemid}/KRingBuffer.cpp)
    
    # add_test(NAME ${problemid} COMMAND ${problemid})
    # target_link_libraries(${problemid} PRIVATE Catch2::Catch2)
    # target_compile_definitions(${problemid} PRIVATE TEST_TAGS="\\\"[${problemid}]\\\"" PRIVATE TEST_NAME="\\\"${linkname}\\\"")
endfunction(add_problem)

#add_problem(01)
#add_problem(02)
add_problem(03)