cmake_minimum_required(VERSION 3.4.0)

project(wheel)
set(WHEEL_VERSION 0.1.0)

# To use cmake modules/functions or FindXXX files:
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(GNUInstallDirs) # Define CMAKE_INSTALL_xxx: LIBDIR, INCLUDEDIR
# set(wheel_export_file "${PROJECT_BINARY_DIR}/wheelTargets.cmake")

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_POSITION_INDEPENDENT_CODE ON CACHE BOOL "Enable position independent code" FORCE)

# Default to static build
set(BUILD_STATIC_LIBS ON CACHE BOOL "enable static build of pysfml11" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "disable shared build of pysfml11" FORCE)

message(STATUS "PYTHON_EXECUTABLE is ${PYTHON_EXECUTABLE}")
message(STATUS "CMAKE_LIBRARY_PATH is ${CMAKE_LIBRARY_PATH}")

# Dependencies
# ============

set(SFML_GIT_TAG        2.5.1)

# Fetch and build cmake dependencies
# ==================================

include(FetchContent)

# SFML
# ----

message(STATUS "SFML")

set(BUILD_SHARED_LIBS OFF CACHE BOOL "enable static link" FORCE)
set(SFML_USE_STATIC_STD_LIBS ON CACHE BOOL "enable static link" FORCE)
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "disable docs build" FORCE)
set(SFML_BUILD_AUDIO ON CACHE BOOL "" FORCE)
set(SFML_BUILD_GRAPHICS ON CACHE BOOL "" FORCE)
set(SFML_BUILD_WINDOW ON CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK ON CACHE BOOL "" FORCE)
set(SFML_USE_SYSTEM_DEPS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML
  GIT_TAG ${SFML_GIT_TAG}
)

FetchContent_GetProperties(sfml)

if(NOT sfml_POPULATED)
  FetchContent_Populate(sfml)
  add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

# pysfml11
# --------
