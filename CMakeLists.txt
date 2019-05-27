cmake_minimum_required(VERSION 3.11.0)
project(bomberman VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

# sources et include
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "include/*.hpp")
include_directories(include)

if(MSVC)
	# Force to always compile with W4
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
	# Update if necessary
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
endif()

# flags de compilation
#set(CMAKE_CXX_FLAGS "-Wall")

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