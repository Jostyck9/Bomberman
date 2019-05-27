cmake_minimum_required(VERSION 3.11.0)
project(bomberman VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

# sources et include
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "include/*.hpp")
include_directories(include)

# flags de compilation
set(CMAKE_CXX_FLAGS " -W -Wall -Wextra -Werror -Wshadow")

# set the cmake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Trouver un package avec find_package
find_package("Irrlicht")
if (Irrlicht_FOUND)
    # executable
    add_executable(bomberman ${SOURCE_FILES})
    include_directories(${Irrlicht_INCLUDE_DIRS})
    target_link_libraries(bomberman ${Irrlicht_LIBRARIES})
else()
    message(FATAL_ERROR "Librairy not found")
endif()