cmake_minimum_required(VERSION 3.5)

project(hello_install)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

add_library(hello_library SHARED
    src/Hello.cpp
)
add_library(hello::library ALIAS hello_library)

target_include_directories(hello_library
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(hello_binary src/main.cpp)

target_link_libraries(hello_binary 
    PRIVATE
        hello::library
)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install")

install(TARGETS hello_binary hello_library
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static
    )

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION include)

install(FILES "content.txt"
    DESTINATION res)