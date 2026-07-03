# Define a versão mínima para rodar o cmake
cmake_minimum_required(VERSION 3.16)
# Define o nome do projeto
project(RPSS)

# Define a versão do c++ a ser usada (no caso, 17)
set(CMAKE_CXX_STANDARD 17)
# Proibe de utilizar uma versão mais antiga
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Habilita a busca na internet
include(FetchContent)
# Declara o que buscar na internet
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
)
# Manda baixar
set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(SFML)

# Organiza todos os arquivos de implementação (.cpp)
file(GLOB SOURCES "src/*.cpp")
# Cria o arquivo executável, com base nos arquivos do SOURCES definido anteriormente
add_executable(RPSS ${SOURCES})

set_target_properties(RPSS PROPERTIES
    LINK_SEARCH_START_STATIC OFF
    LINK_SEARCH_END_STATIC OFF
)

# Cola as bibliotecas do C++ dentro do executável
target_link_options(RPSS PRIVATE "-Bdynamic")

# Define as bibliotecas que devem ser adicionadas ao executável
target_link_libraries(RPSS PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    SFML::Audio
)

set(CMAKE_TLS_VERIFY FALSE)

# Comando para copiar automaticamente os DLLs para a pasta onde o executável foi criado
if(WIN32)
    add_custom_command(TARGET RPSS POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_BINARY_DIR}/_deps/sfml-build/bin"
        "$<TARGET_FILE_DIR:RPSS>"
        COMMENT "Copiando arquivos DLL do SFML da pasta bin para a pasta de build..."
    )
endif()