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

set(OGG_GIT_TAG         v1.3.5)
set(OPENAL_GIT_TAG      1.21.1)
# set(VORBIS_GIT_TAG      v1.3.7)
set(VORBIS_GIT_TAG      master) # master contains a fix
# set(SFML_GIT_TAG        2.5.1)
set(SFML_GIT_TAG        debug_2)

# Fetch and build cmake dependencies
# ==================================

include(FetchContent)

# TODO
# libogg ?
# freetype ?
# libflac ?

# ogg
# ---

# TODO Use conda-forge patch for the OSX 64 compilation failure?

message(STATUS "Building ogg")

set(INSTALL_DOCS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  ogg
  GIT_REPOSITORY https://github.com/xiph/ogg
  GIT_TAG ${OGG_GIT_TAG}
)

FetchContent_GetProperties(ogg)

if(NOT ogg_POPULATED)
  FetchContent_Populate(ogg)
  add_subdirectory(${ogg_SOURCE_DIR} ${ogg_BINARY_DIR})
endif()

# OPENAL
# ------

message(STATUS "Building OpenAL")

set(LIBTYPE "STATIC" CACHE BOOL "" FORCE)
set(ALSOFT_STATIC_LIBGCC ON CACHE BOOL "" FORCE)
set(ALSOFT_STATIC_STDCXX ON CACHE BOOL "" FORCE)
set(ALSOFT_STATIC_WINPTHREAD ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  OpenAL
  GIT_REPOSITORY https://github.com/kcat/openal-soft
  GIT_TAG ${OPENAL_GIT_TAG}
)

FetchContent_GetProperties(OpenAL)

if(NOT OpenAL_POPULATED)
  FetchContent_Populate(OpenAL)
  add_subdirectory(${openal_SOURCE_DIR} ${openal_BINARY_DIR})
endif()

# VORBIS
# ------

message(STATUS "Building libvorbis")

FetchContent_Declare(
  vorbis
  GIT_REPOSITORY https://github.com/xiph/vorbis
  GIT_TAG ${VORBIS_GIT_TAG}
)

FetchContent_GetProperties(vorbis)

if(NOT vorbis_POPULATED)
  FetchContent_Populate(vorbis)
  add_subdirectory(${vorbis_SOURCE_DIR} ${vorbis_BINARY_DIR})
endif()

# SFML
# ----

message(STATUS "Building SFML")

set(BUILD_SHARED_LIBS FALSE CACHE BOOL "" FORCE)
set(SFML_USE_STATIC_STD_LIBS TRUE CACHE BOOL "" FORCE)
set(SFML_INSTALL_XCODE_TEMPLATES FALSE CACHE BOOL "" FORCE)
# set(SFML_USE_SYSTEM_DEPS FALSE CACHE BOOL "" FORCE) SHOULD WE TRY TO USE BUNDLED DEPS ?

FetchContent_Declare(
  SFML
  # GIT_REPOSITORY https://github.com/SFML/SFML
  GIT_REPOSITORY https://github.com/martinRenou/SFML
  GIT_TAG ${SFML_GIT_TAG}
)

FetchContent_GetProperties(SFML)

if(NOT SFML_POPULATED)
  FetchContent_Populate(SFML)
  add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

# pysfml11
# --------
