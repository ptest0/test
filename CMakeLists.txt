# CMakeLists.txt
cmake_minimum_required(VERSION 3.5)
project(DeskPoE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

include_directories(${INSTALL_LIB_DIR})
add_subdirectory(${INSTALL_LIB_DIR}/googletest)
add_subdirectory(${INSTALL_LIB_DIR}/spdlog)


set(QT_VERSION 6)
set(CMAKE_PREFIX_PATH "${INSTALL_LIB_DIR}/qtbase/lib/cmake")
set(Qt6_DIR ${INSTALL_LIB_DIR}/qtbase/lib/cmake/Qt6)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# main target
add_executable(main)
target_sources(main PRIVATE src/main.cpp)
target_link_libraries(main PRIVATE spdlog::spdlog spdlog::spdlog_header_only Qt6::Core Qt6::Gui Qt6::Widgets)

# tests target
add_executable(tests)
target_sources(tests PRIVATE src/test.cpp)
target_link_libraries(tests PRIVATE gtest gtest_main)
enable_testing()
add_test(tests tests)
