# Install script for directory: C:/Users/Gabri/Downloads/RPSS/build/_deps/libssh2-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Jankenpo")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/MinGW/mingw64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SFML" TYPE FILE FILES
    "C:/Users/Gabri/Downloads/RPSS/build/_deps/libssh2-src/COPYING"
    "C:/Users/Gabri/Downloads/RPSS/build/_deps/libssh2-src/NEWS"
    "C:/Users/Gabri/Downloads/RPSS/build/_deps/libssh2-src/README"
    "C:/Users/Gabri/Downloads/RPSS/build/_deps/libssh2-src/RELEASE-NOTES"
    "C:/Users/Gabri/Downloads/RPSS/build/_deps/libssh2-src/docs/AUTHORS"
    "C:/Users/Gabri/Downloads/RPSS/build/_deps/libssh2-src/docs/BINDINGS.md"
    "C:/Users/Gabri/Downloads/RPSS/build/_deps/libssh2-src/docs/HACKING.md"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Gabri/Downloads/RPSS/build/_deps/libssh2-build/src/cmake_install.cmake")
endif()

