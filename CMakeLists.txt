cmake_minimum_required(VERSION 3.0.0)
project(BouncyBalls VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

find_package(SFML COMPONENTS graphics window system REQUIRED)

add_executable(BouncyBalls src/main.cpp
                            src/core/Core.cpp
                            src/core/Core.h
                            )



target_link_libraries(BouncyBalls PRIVATE sfml-graphics sfml-window sfml-system)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
