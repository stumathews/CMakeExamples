REM Passing in -DBUILD_SHARED_LIBS= allows us not to have to specify the type of library we are building in the CmakeLists.txt
cmake -DBUILD_SHARED_LIBS=YES -B build
cmake --build build