# Introdução
RPSS é um jogo arcade de jankenpon desenhado à mão e desenvolvido em C++ com a biblioteca SFML. Os rounds são jogados contra um NPC até que o player perca 3 vidas.

# Loop do jogo

## Round tipo 1
O round segue as regras de jankenpon(pedra, papel e tesoura) tradicionais.

## Round tipo 2
O round 2 consiste em tentar prever em que posição o NPC olha e acontece quando o jogador ganha no round tipo 1.
Se o player ganha este tipo de round é adicionado um ponto ao seu score.

## Round tipo 3
O round 3 consiste em tentar evitar que o NPC adivinhe para que posição o player vai apontar e acontece quando o jogador perde no round tipo 1.
Se o player perde este tipo de round ele perde uma vida.

# Requisitos
- Compilador C++;
* Biblioteca sfml;
+ Cmake.

# Setup
## Como rodar

Após a instalação dos pré-requisitos, siga o passo a passo abaixo:

### Windows

1. Dentro do CMD, navegue até o diretório raíz do jogo.

2. Agora, utilize os seguintes comandos:

```bash
    cmake -B build -G "MinGW Makefiles"
```

3. Espere até o fim da configuração do CMake. Após sua finalização, execute:

```bash
    cmake --build build
```

4. Por fim, abra o executável na pasta build.

### Linux

1. Dentro do terminal, navegue até o diretório raíz do jogo.

2. Agora, utilize os seguintes comandos:

```bash
    mkdir build

    cd build
```

3. Já dentro da pasta build, execute:

```bash
    cmake ..
```

4. Espere até o fim da configuração do CMake. Após sua finalização, execute:

```bash
    cmake --build .
```

5. Por fim, abra o executável na pasta build.

# integrantes:
- Gabriel Pinheiro Maia;
* Pedro Augusto Carvalho de Freitas Gouveia Fidalgo;
+ Vitor Cavalcante Borges.
