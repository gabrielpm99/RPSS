# Define a versão mínima para rodar o cmake
cmake_minimum_required(VERSION 3.16)
# Define o nome do projeto
project(Jankenpo)

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
FetchContent_MakeAvailable(SFML)

# Organiza todos os arquivos de implementação (.cpp)
file(GLOB SOURCES "src/*.cpp")
# Cria o arquivo executável, com base nos arquivos do SOURCES definido anteriormente
add_executable(jankenpo ${SOURCES})

# Cola as bibliotecas do C++ dentro do executável
target_link_options(jankenpo PRIVATE -static -static-libgcc -static-libstdc++)

# Define as bibliotecas que devem ser adicionadas ao executável
target_link_libraries(jankenpo PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Main)