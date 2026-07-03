cmake_minimum_required(VERSION 3.29)

message(VERBOSE "Executing patch step for vorbis")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "C:/Users/Gabri/Downloads/RPSS/build/_deps/vorbis-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[C:/MinGW/mingw64/bin/cmake.exe]====] [====[-DVORBIS_DIR=C:/Users/Gabri/Downloads/RPSS/build/_deps/vorbis-src]====] [====[-P]====] [====[C:/Users/Gabri/Downloads/RPSS/build/_deps/sfml-src/tools/vorbis/PatchVorbis.cmake]====]
)

endblock()
