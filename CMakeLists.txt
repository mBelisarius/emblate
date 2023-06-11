cmake_minimum_required(VERSION 3.25)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(ProjectName "src")
set(ProjectNamespace "src")

project("${ProjectName}")

set(CMAKE_CXX_STANDARD 11)

add_library (${ProjectName} INTERFACE)
add_library (${ProjectName}::${ProjectNamespace} ALIAS ${ProjectName})

target_include_directories(${ProjectName} INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${INCLUDE_INSTALL_DIR}>)

set_target_properties(${ProjectName} PROPERTIES LINKER_LANGUAGE CXX)
