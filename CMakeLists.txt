# CMakeLists.txt
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

include_directories(${INSTALL_LIB_DIR})
add_subdirectory(${INSTALL_LIB_DIR}/googletest)
add_subdirectory(${INSTALL_LIB_DIR}/spdlog)


# main target
add_executable(main)
target_sources(main PRIVATE src/main.cpp)
target_link_libraries(main PRIVATE spdlog::spdlog spdlog::spdlog_header_only)

# tests target
add_executable(tests)
target_sources(tests PRIVATE src/test.cpp)
target_link_libraries(tests PRIVATE gtest gtest_main)
enable_testing()
add_test(tests tests)
