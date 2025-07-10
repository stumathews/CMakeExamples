# CMakeLists.txt

#[==[

This file defines what can be built and how, tests that may be run, and packages to create. It is a platform-independent description of the whole project, which CMake then turns into platform-specific build tool project files. CMake reads the CMakeLists.txt file and creates project files in the build directory. 

]==]

cmake_minimum_required(VERSION 4.0)

# Test/check the compilers for each enabled language and ensure they are able to compile and link successfully

project(ProjectName VERSION 1.0 LANGUAGES CXX)

add_executable(MyApp myapp.cpp)

add_library(MyFunctions functions.cpp)
add_library(Collector collector.cpp)
add_library(Algorithm algorithm.cpp)
add_library(Engine engine.cpp)
add_library(UI ui.cpp)

# for Collector, link to the UI library and make it a dependency for the users also (UI's types is used in collector library's exposed interface)
target_link_libraries(Collector
 PUBLIC UI
 # Link Algorithm and Engine directly into Collector but don't require the user needing them also
 PRIVATE Algorithm Engine 
)

target_link_libraries(MyApp
 PRIVATE Collector # We'll link in collector lib to myApp but my App but users of my app wont need Collector
)

# Define a file set so that it can be installed

target_sources(Collector
 PUBLIC
  FILE_SET api
  TYPE HEADERS
  BASE_DIRS headers
  FILES
   headers/myheader.h
)

# No destinations are given, install below the base install location.
# binaries are stored in bin/ libraries are stored in /lib etc.
install(TARGETS MyApp Collector UI FILE_SET api)

# These are project-specific
set(CPACK_PACKAGE_NAME ProjectName)
set(CPACK_PACKAGE_VENDOR MyCompany)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An example project")

# These lines tend to be the same for every project
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
set(CPACK_VERBATIM_VARIABLES TRUE)

# This is what writes out the input file for cpack
include(CPack)
