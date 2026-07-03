cmake_minimum_required(VERSION 3.29)

message(VERBOSE "Executing patch step for libssh2")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "C:/Users/Gabri/Downloads/RPSS/build/_deps/libssh2-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[C:/MinGW/mingw64/bin/cmake.exe]====] [====[-DLIBSSH2_DIR=C:/Users/Gabri/Downloads/RPSS/build/_deps/libssh2-src]====] [====[-DMODULES_DIR=C:/Users/Gabri/Downloads/RPSS/build/_deps/sfml-src/src/SFML/Network/../../../cmake/Modules]====] [====[-P]====] [====[C:/Users/Gabri/Downloads/RPSS/build/_deps/sfml-src/tools/libssh2/PatchLibssh2.cmake]====]
)

endblock()
