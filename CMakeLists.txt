cmake_minimum_required(VERSION 3.0.0)
project(BBoxToObj VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()
find_package(Eigen3 CONFIG)

add_executable(BBoxToObj main.cpp include/BBoxCubeGenerator.h)
include_directories(include)
target_link_libraries(BBoxToObj Eigen3::Eigen)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
