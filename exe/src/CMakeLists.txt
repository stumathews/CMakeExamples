# CMakeLists.txt

#[==[

This file defines what can be built and how, tests that may be run, and packages to create. It is a platform-independent description of the whole project, which CMake then turns into platform-specific build tool project files. CMake reads the CMakeLists.txt file and creates project files in the build directory. 

]==]

cmake_minimum_required(VERSION 4.0)

# Test/check the compilers for each enabled language and ensure they are able to compile and link successfully

project(ProjectName VERSION 1.0 LANGUAGES CXX)

# Ask cmake to produce a ctest input file
enable_testing()

# example of setting a user-defined 'normal' variables
set(myName Stuart)
set(mySurname Mathews)
set(myMiddleName1 Robert)
set(myMiddleName2 Charles)
set(myFullName "${myName} ${myMiddleName1} ${myMiddleName2} ${mySurname}")
set(myAge 38)
set(myVar a b c) # myVar = "a;b;c" - see how it concatenates the arguments into a semi-colon delimited string

# example of setting 'cache' variables that are persited in he cmakecache.txt file (FORCE will always write the value)
set(favColour Green CACHE STRING "my favourite colour" [FORCE])

# without FORCE, the cache variable can be considered a set-if-not-set cache variable and it will persist once its it set for the first time and not change on subsequent runs.

set(windowsBuild YES CACHE BOOL "If running window build")
option(LinuxBuild "if running Linux build" NO) # This is the same as the above BOOL type for a cache variable

# Creating a list of just creating a string
set(myList one two three) # one;two;three

# We can ise some list operations
list(APPEND myList four)
list(LENGTH myList countElements)


# Example of printing 

message("My full name is ${myFullName}\nGood hey?. MyList is ${myList} which as ${countElements} elements")

add_executable(Target1 main.cpp)

add_executable(AFewTests tests.cpp)

add_test(NAME BasicTests COMMAND AFewTests)