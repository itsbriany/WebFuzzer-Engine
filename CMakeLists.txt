cmake_minimum_required(VERSION 3.6)

project(WebFuzzerEngine)

message("Setting Compiler Options...")
set(CMAKE_CXX_STANDARD 14)
#set(COMPILER_WARNING_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_WARNING_FLAGS}")


message("Enabling boost...")
# The runtime also determines how boost will be found.
# find_package Boost is very picky, so if you have not built the
# boost libraries conforming to these runtime configurations,
# it will say that it could not find the libraries.
if (BUILD_SHARED_LIBS OR BOOST_LOG_DYN_LINK)
    set(Boost_USE_STATIC_RUNTIME OFF)
    set(Boost_USE_STATIC_LIBS OFF)
else ()
    set(Boost_USE_STATIC_RUNTIME ON)
    set(Boost_USE_STATIC_LIBS ON)
endif()
set(Boost_USE_MULTITHREADED ON)
if (DEBUG_BOOST)
    set(Boost_DEBUG ON)
endif()
find_package(Boost REQUIRED COMPONENTS system log thread random)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost, please set the BOOST_ROOT environment variable to your boost installation directory")
endif()

message(Setting Runtime...)
set(LIBS ${CMAKE_BINARY_DIR}/archive)

message("Adding Third Party Libraries...")
set(THIRD_PARTY ThirdParty)
set(TEST_ROOT "${THIRD_PARTY}/googletest")
set(GMOCK_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/${TEST_ROOT}/googlemock/include")
set(GMOCK_LIBRARY_DIRS "${TEST_ROOT}/googlemock")
set(GTEST_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/${TEST_ROOT}/googletest/include")
set(GTEST_LIBRARY_DIRS "${GMOCK_LIBRARY_DIRS}/gtest")

set(CPP_NETLIB_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/ThirdParty/cpp-netlib" "${PROJECT_SOURCE_DIR}/ThirdParty/cpp-netlib/deps/uri/include")
set(CPP_NETLIB_LIBRARY_DIRS "${PROJECT_SOURCE_DIR}/build/ThirdParty/cpp-netlib/libs/network/src")

add_subdirectory(${THIRD_PARTY}/cpp-netlib)
#add_subdirectory(${THIRD_PARTY}/googletest)

message("Setting Include and Library Directories...")
set(INCLUDE_DIRS ${Boost_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS} ${CPP_NETLIB_INCLUDE_DIRS})
set(LIBRARY_DIRS ${Boost_LIBRARY_DIRS} ${CPP_NETLIB_LIBRARY_DIRS})

message("Adding Source Code...")
add_subdirectory(src)
