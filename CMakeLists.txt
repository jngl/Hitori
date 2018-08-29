cmake_minimum_required(VERSION 3.9)
project (Hitori)

#Output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Hitori_SOURCE_DIR}/bin)

#Hitori
file(GLOB_RECURSE Hitori_source_files src/*)
add_executable(Hitori ${Hitori_source_files})

#Hitori
target_include_directories(Hitori PUBLIC src)

#SFML
target_link_libraries(Hitori PRIVATE sfml-graphics sfml-window sfml-system)

