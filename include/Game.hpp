#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

#define TEMPO_INICIAL 1.5f
#define TEMPO_MINIMO 1.0f
#define TEMPO_TRANSICAO 1.5f
#define TEMPO_SPLASH 4.0f

#define ESTADO_INICIAL EstadoJogo::SplashScreen

// Enum contendo todos os estados do jogo
enum class EstadoJogo {
    SplashScreen,
    TeamSplash,
    Menu,
    Tutorial,
    Round1, 
    Round2, 
    Round3, 
    FimDeJogo
};

class Game {
private:
    // Variável que cria a janela
    sf::RenderWindow window;

    // Variável que armazena o ícone do jogo
    sf::Image icone;

    // Variáveis de controle de estado do jogo
    EstadoJogo estadoAtual;
    EstadoJogo proximoEstado;

    // Variável que armazena a fonte do texto do jogo
    sf::Font fonte;

    // Texturas e sprites do background
    sf::Texture texturaBackground;
    sf::Sprite spriteBackground{texturaBackground};
    // Variável de controle da escolha dos botões do menu
    int opcaoMenu = 1;

    // Texturas e sprites da splash screen
    sf::Texture texturaSplashScreen;
    sf::Sprite spriteSplashScreen{texturaSplashScreen};
    sf::Texture texturaBackSplash;
    sf::Sprite spriteBackSplash{texturaBackSplash};
    sf::Texture texturaTeamSplash;
    sf::Sprite spriteTeamSplash{texturaTeamSplash};

    // Texturas e sprites da tela do menu
    sf::Texture texturaLogoMenu;
    sf::Sprite spriteLogoMenu{texturaLogoMenu};
    sf::Texture texturaScribbled01Menu;
    sf::Texture texturaScribbled02Menu;
    sf::Sprite spriteScribbledMenu{texturaScribbled01Menu};
    sf::Texture texturaSetaMenu;
    sf::Sprite spriteSetaMenu{texturaSetaMenu};
    sf::Texture texturaStartMenu;
    sf::Sprite spriteStartMenu{texturaStartMenu};
    sf::Texture texturaTutorialMenu;
    sf::Sprite spriteTutorialMenu{texturaTutorialMenu};

    // Textura UI do jogo
    sf::Texture UIJogo;
    sf::Sprite spriteUIJogo{UIJogo};

    // Texturas e sprites do jogador
    sf::Texture texturaMaoInt01;
    sf::Texture texturaMaoInt02;
    sf::Texture texturaMaoPapel;
    sf::Texture texturaMaoTesoura;
    sf::Texture texturaMaoPedra;
    sf::Texture texturaMaoCima;
    sf::Texture texturaMaoDireita;
    sf::Texture texturaMaoEsquerda;
    sf::Texture texturaMaoBaixo;
    sf::Sprite spriteMaoJogador{texturaMaoInt01};

    // Texturas e sprites do oponente
    sf::Texture texturaOponenteInt01;
    sf::Texture texturaOponenteInt02;
    sf::Texture texturaOponentePapel;
    sf::Texture texturaOponenteTesoura;
    sf::Texture texturaOponentePedra;
    sf::Texture texturaOponenteCimaFase02;
    sf::Texture texturaOponenteDireitaFase02;
    sf::Texture texturaOponenteEsquerdaFase02;
    sf::Texture texturaOponenteBaixoFase02;
    sf::Texture texturaOponenteCimaFase03;
    sf::Texture texturaOponenteDireitaFase03;
    sf::Texture texturaOponenteEsquerdaFase03;
    sf::Texture texturaOponenteBaixoFase03;
    sf::Texture texturaOponenteVitoria01;
    sf::Texture texturaOponenteVitoria02;
    sf::Texture texturaOponenteDerrota;
    sf::Texture texturaOponenteOlhosCima;
    sf::Texture texturaOponenteOlhosDireita;
    sf::Texture texturaOponenteOlhosEsquerda;
    sf::Texture texturaOponenteOlhosBaixo;

    sf::Texture texturaFinalRodada;
    sf::Sprite spriteOponente{texturaOponenteInt01};

    // Texto da pontuação
    sf::Text textoPlacar{fonte};
    // Cria uma cópia do texto da pontuação para poder utilizá-lo na tela de fim de jogo
    sf::Text textoPlacarFimDeJogo{fonte};
    // Variável que armazena a pontuação do jogador
    int pontuacao = 0;

    // Texturas e sprites da tela de fim de jogo
    sf::Texture texturaBackFimDeJogo;
    sf::Sprite spriteBackFimDeJogo{texturaBackFimDeJogo};
    sf::Texture texturaRetry01;
    sf::Texture texturaRetry02;
    sf::Sprite spriteRetry{texturaRetry01};
    sf::Texture texturaMenu01;
    sf::Texture texturaMenu02;
    sf::Sprite spriteMenu{texturaMenu01};
    sf::Texture texturaArrowFimDeJogo;
    sf::Sprite spriteArrowFimDeJogo{texturaArrowFimDeJogo};
    sf::Texture texturaScore;
    sf::Sprite spriteScore{texturaScore};
    // Variável de controle da escolha dos botões do fim de jogo
    int opcaoFimDeJogo = 1;
    // Variável de controle de visibilidade do placar final
    bool mostrarPlacarFinal = true;

    // Variáveis de escolha de jogadas
    int escolhaJogador = 0;
    int escolhaOponente = 0;

    // Texturas e sprites da vida do jogador
    sf::Texture texturaVidaCheia;
    sf::Texture texturaVidaVazia;
    sf::Sprite spriteVida001{texturaVidaCheia};
    sf::Sprite spriteVida002{texturaVidaCheia};
    sf::Sprite spriteVida003{texturaVidaCheia};
    
    // Variável de controle da vida do jogador
    int vidas = 3; 

    // Texturas e sprites da tela de tutorial
    //sf::Texture texturaTutorial;
    //sf::Sprite spriteTutorial{texturaTutorial};

    // Flag de controle para saber se o resultado da rodada já foi calculado
    bool resultadoCalculado = false;

    // Variáveis que guardam os buffers dos soms das batidas
    sf::SoundBuffer bufferSomBatida01;
    sf::SoundBuffer bufferSomBatida02;
    // Variável que armazena o som da batida
    sf::Sound somBatida{bufferSomBatida01};
    // Variável de controle que checa se o som da batida já foi tocado
    int ultimaBatida = 0;

    // Variáveis de controle da transição entre telas
    bool emTransicao = false; // Flag para checar se está em transição
    float pixeisAndadosX = 0.0f; // Variável que armazena quantos pixels os sprites já andaram
    float pixeisAndadosY = 0.0f;
    vector<sf::Sprite*> listaSpritesProximo; // Lista de sprites que serão movidos durante a transição
    vector<sf::Sprite*> listaSpritesAtual; // Lista de sprites que estão na tela atual e serão movidos durante a transição

    sf::RectangleShape telaTransicao;
    float opacidadeTransicao = 0.0f; // Controle de opacidade da tela branca da transição
    bool fade = false; // Define se a tela está em fade in ou fade out
    bool ehTransicaoFade = false; // Checa se a transição a ser utilizada é o fade


    // Variável de controle de tempo de espera entre as jogadas
    sf::Clock clockJogadaFinalizada;
    bool jogadaFinalizada = false;

    // Variável de controle de tempo de rodada do jogo
    sf::Clock clockPrincipal;
    float tempoLimite = TEMPO_INICIAL;

    // Variável de controle de tempo da animação do texto "Scribbled"
    sf::Clock clockAnimacaoScribbled;
    bool ehFrameScribbled01 = true;

    // Variável de controle de tempo da animação da mão do jogador
    sf::Clock clockAnimacaoMaoIntermediaria;
    bool ehFrameMao01 = true;

    // Variável de controle de tempo da animação do oponente
    sf::Clock clockAnimacaoOponente;
    bool ehFrameOponente01 = true;

    // Variável de controle de tempo da animação da tela de fim de jogo
    sf::Clock clockAnimacaoFimDeJogo;
    bool ehFrameFimDeJogo01 = true;

    // Variáveis de controle de tempo da splash screen
    sf::Clock clockSplashScreen;
    sf::Clock clockTeamSplash;


    // Função que mapeia as teclas às funcionalidades do jogo
    void processarEventos();
    // Função que atualiza os estados e as animações do jogo
    void atualizar();
    // Função que desenha os elementos na tela
    void renderizar();
    
    // Função que organiza o início de cada round
    void iniciarRound(EstadoJogo novoEstado);

    // Função que carrega todas as texturas do jogo
    void carregarTexturas();

    // Função que faz a transição das telas
    void transicionarTelas(vector<sf::Sprite*> sprites, float passoPorSegundo);
    // Função que move os sprites
    void moverSprites(sf::Sprite &sprite, float passoPorSegundo);

    // Função que toca a batida apenas uma vez
    void tocarBatida(int tipoBatida);

public:
    Game();
    ~Game();

    void run();
};
