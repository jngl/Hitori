cmake_minimum_required(VERSION 3.9)
project (Hitori)

#Google Test
enable_testing()
find_package(GTest REQUIRED)

#Output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Hitori_SOURCE_DIR}/bin)

#libHitori
file(GLOB_RECURSE lib_hitori_source_files lib/src/*)
add_library(libHitori ${lib_hitori_source_files})
target_include_directories(libHitori PUBLIC lib/includes)


#Test
file(GLOB_RECURSE test_source_files test/*)
add_executable(HitoriTest ${test_source_files})
target_include_directories(HitoriTest PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(HitoriTest ${GTEST_LIBRARIES} pthread libHitori)
gtest_discover_tests(HitoriTest)

#Hitori
file(GLOB_RECURSE Hitori_source_files src/*)
add_executable(Hitori ${Hitori_source_files})

target_include_directories(Hitori PUBLIC src)

target_link_libraries(Hitori 
    libHitori
    sfml-graphics 
    sfml-window 
    sfml-system
)

