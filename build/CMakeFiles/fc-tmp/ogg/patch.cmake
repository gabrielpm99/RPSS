cmake_minimum_required(VERSION 3.29)

message(VERBOSE "Executing patch step for ogg")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "C:/Users/Gabri/Downloads/RPSS/build/_deps/ogg-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[C:/MinGW/mingw64/bin/cmake.exe]====] [====[-DOGG_DIR=C:/Users/Gabri/Downloads/RPSS/build/_deps/ogg-src]====] [====[-P]====] [====[C:/Users/Gabri/Downloads/RPSS/build/_deps/sfml-src/tools/ogg/PatchOgg.cmake]====]
)

endblock()
