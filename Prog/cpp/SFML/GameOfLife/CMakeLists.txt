
cmake_minimum_required(VERSION 3.10)

project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "Projecct name: ${PROJECT_NAME}")

set (SRC_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB_RECURSE SOURCES
    ${SRC_DIR}/*.cpp
)

add_executable(GameOfLife ${SOURCES})

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(VCPKG_FILE_DIR ${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-linux)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(VCPKG_FILE_DIR ${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows)
endif()
set(SFML_DIR "${VCPKG_FILE_DIR}/share/sfml")
set(imgui_DIR "${VCPKG_FILE_DIR}/share/imgui")
set(ImGui-SFML_DIR "${VCPKG_FILE_DIR}/share/imgui-sfml")

find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)

target_link_libraries(GameOfLife PRIVATE
    SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System
    ImGui-SFML::ImGui-SFML
)

target_include_directories(GameOfLife PRIVATE 
    ${SRC_DIR}
)

