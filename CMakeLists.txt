cmake_minimum_required(VERSION 3.25)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(ProjectName "emblate")
set(ProjectNamespace "Emblate")

project("${ProjectName}")

set(CMAKE_CXX_STANDARD 11)

add_library(${ProjectName} STATIC ./Emblate/Emblate)
set_target_properties(${ProjectName} PROPERTIES LINKER_LANGUAGE CXX)
