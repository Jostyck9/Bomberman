#
# A CMake module to find IrrKlang for the project B-YEP-400 IndieStudio
#
# This CMake module is designed to work on Fedora28 and Windows10. We will not
# provide support for other distributions. We will use this module to compile
# your project during our tests.
#
# You must provide the path to this module to CMake by setting
# CMAKE_MODULE_PATH variable to its location.
#
# Once done this module will define:
#  IrrKlang_FOUND - system has IrrKlang
#  IrrKlang_INCLUDE_DIRS - the IrrKlang include directory
#  IrrKlang_LIBRARIES - Link these to use IrrKlang
#
# Author: Guillaume DEVOILLE <guillaume1.devoille@epitech.eu> (17/05/2019)
#

IF (NOT Irrklang_INCLUDE_DIRS OR NOT Irrklang_LIBRARIES)
  FIND_PATH(Irrklang_INCLUDE_DIRS
    NAMES
      irrKlang.h
    PATHS
      /usr/include/IrrKlang/        # Default Fedora28 system include path
      /usr/local/include/IrrKlang/  # Default Fedora28 local include path
      cmake/Modules/Irrklang/include/    # Expected to contain the path to this file for Windows10
      cmake/Modules/Irrklang/include/     # irrklang root directory (if provided)
  )

  IF (MSVC)     # Windows
    SET(CMAKE_FIND_LIBRARY_PREFIXES "")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
  ELSE (MSVC)   # Linux
    SET(CMAKE_FIND_LIBRARY_PREFIXES "lib")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so")
  ENDIF(MSVC)

  FIND_LIBRARY(Irrklang_LIBRARIES
    NAMES
      IrrKlang
    PATHS
      /usr/lib64/                   # Default Fedora28 library path
      /usr/lib/                     # Some more Linux library path
      /usr/lib/x86_64-linux-gnu/    # Some more Linux library path
      /usr/local/lib/               # Some more Linux library path
      /usr/local/lib64/             # Some more Linux library path
      cmake/Modules/Irrklang/         # Expected to contain the path to this file for Windows10
      cmake/Modules/Irrklang/              # irrklang root directory (if provided)
  )
ENDIF (NOT Irrklang_INCLUDE_DIRS OR NOT Irrklang_LIBRARIES)

IF (Irrklang_INCLUDE_DIRS AND Irrklang_LIBRARIES)
  SET(Irrklang_FOUND TRUE)
ELSE (Irrklang_INCLUDE_DIRS AND Irrklang_LIBRARIES)
  SET(Irrklang_FOUND FALSE)
ENDIF (Irrklang_INCLUDE_DIRS AND Irrklang_LIBRARIES)

IF (Irrklang_FIND_REQUIRED AND NOT Irrklang_FOUND)
  MESSAGE(FATAL_ERROR
    "  Irrklang not found.\n"
    "      Windows: Fill CMake variable CMAKE_MODULE_PATH to the provided directory.\n"
    "      Linux: Install Irrklang using your package manager ($> sudo dnf install irrklang-devel).\n"
  )
ENDIF (Irrklang_FIND_REQUIRED AND NOT Irrklang_FOUND)
