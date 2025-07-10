# CMakeLists.txt

#[==[

This file defines what can be built and how, tests that may be run, and packages to create. It is a platform-independent description of the whole project, which CMake then turns into platform-specific build tool project files. CMake reads the CMakeLists.txt file and creates project files in the build directory. 

]==]

cmake_minimum_required(VERSION 4.0)

# Test/check the compilers for each enabled language and ensure they are able to compile and link successfully

project(ProjectName VERSION 1.0 LANGUAGES CXX)

add_executable(Target1 main.cpp)