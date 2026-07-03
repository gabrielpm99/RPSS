cmake_minimum_required(VERSION 3.29)

message(VERBOSE "Executing patch step for harfbuzz")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "C:/Users/Gabri/Downloads/RPSS/build/_deps/harfbuzz-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[C:/MinGW/mingw64/bin/cmake.exe]====] [====[-DHARFBUZZ_DIR=C:/Users/Gabri/Downloads/RPSS/build/_deps/harfbuzz-src]====] [====[-P]====] [====[C:/Users/Gabri/Downloads/RPSS/build/_deps/sfml-src/tools/harfbuzz/PatchHarfBuzz.cmake]====]
)

endblock()
