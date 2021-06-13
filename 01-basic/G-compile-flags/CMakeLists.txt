cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEX2" CACHE STRING "Set C++ Compiler Flags" FORCE)

project(compile_flags)

add_library(MY_LIB_1 INTERFACE)
target_include_directories(MY_LIB_1 INTERFACE .)
target_compile_definitions(MY_LIB_1
    INTERFACE FLAG_1
)

add_library(MY_LIB_2 INTERFACE)
target_include_directories(MY_LIB_2 INTERFACE .)
target_compile_definitions(MY_LIB_2
    INTERFACE FLAG_2
)

add_executable(compile_flags_1 main.cpp)
add_executable(compile_flags_2 main.cpp)
add_executable(compile_flags_3 main.cpp)
target_compile_definitions(compile_flags_3
    PRIVATE FLAG_1
)

target_link_libraries(compile_flags_1 MY_LIB_1) # lib and source both FLAG_1
target_link_libraries(compile_flags_2 MY_LIB_2) # lib and source both FLAG_2
target_link_libraries(compile_flags_3 MY_LIB_2) # lib and source both FLAG_1 and FLAG_2, 
                                                # because FLAG_2 is given by MY_LIB_2, FLAG_1 is given by compile_flags_3

# compile_flags_1 result:
# Hello Compile Flags!
# The Main is FLAG_2 !
# Hello Compile Lib Flags!
# The lib is FLAG_2 !

# compile_flags_2 result:
# Hello Compile Flags!
# The Main is FLAG_2 !
# Hello Compile Lib Flags!
# The lib is FLAG_2 !

# compile_flags_3 result:
# Hello Compile Flags!
# The Main is FLAG_1 !
# The Main is FLAG_2 !
# The lib is FLAG_1 !
# The lib is FLAG_2 !