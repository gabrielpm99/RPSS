#include "../include/Game.hpp"

Game::Game()
{
    window.create(sf::VideoMode(sf::Vector2u(1440, 960)), "RPSS", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    estadoAtual = ESTADO_INICIAL;

    if (fonte.openFromFile("../assets/fonte.ttf"))
    {

        sf::Vector2u tamanhoJanela = window.getSize();

        textoPlacar.setCharacterSize(120);
        textoPlacar.setFillColor(sf::Color(167, 0, 0));
        textoPlacar.setLetterSpacing(12.0f);
    }

    carregarTexturas();

    // Ajusta a tela de transição ao tamanho da tela do jogo
    telaTransicao.setSize(sf::Vector2f(1440.0f, 960.0f));
    // Define a cor inicial da tela de transição (branco)
    telaTransicao.setFillColor(sf::Color(255, 255, 255, 0));

    // Carrega o buffer do som da batida a partir do arquivo
    if (bufferSomBatida01.loadFromFile("../assets/som/batida01.mp3") &&
        bufferSomBatida02.loadFromFile("../assets/som/batida02.mp3"))
    {
        // Seta o buffer da variável que armazena o som
        somBatida.setBuffer(bufferSomBatida01);
    }
}

Game::~Game() {}

// Função que carrega e configura as posições pré-definidas de todos os sprites do jogo
void Game::carregarTexturas()
{
    if (texturaBackground.loadFromFile("../assets/fundo001.png"))
    {
        spriteBackground.setTexture(texturaBackground, true);
        sf::Vector2u tamanhoMenuBackground = texturaBackground.getSize();
        spriteBackground.setScale(sf::Vector2f(1440.0f / tamanhoMenuBackground.x, 960.0f / tamanhoMenuBackground.y));
        spriteBackground.setPosition(sf::Vector2f(0.0f, 0.0f));
    }
    if (texturaBackSplash.loadFromFile("../assets/splashrpss/backsplash.png") &&
        texturaSplashScreen.loadFromFile("../assets/splashrpss/splasscreen.png") &&
        texturaTeamSplash.loadFromFile("../assets/splashrpss/teamsplash001.png"))
    {
        spriteBackSplash.setTexture(texturaBackSplash, true);
        spriteBackSplash.setPosition(sf::Vector2f(-50.0f, -75.0f));

        spriteSplashScreen.setTexture(texturaSplashScreen, true);
        spriteTeamSplash.setTexture(texturaTeamSplash, true);
    }
    if (texturaLogoMenu.loadFromFile("../assets/menu/rockpaperscissor.png"))
    {
        spriteLogoMenu.setTexture(texturaLogoMenu, true);
        spriteLogoMenu.setPosition(sf::Vector2f(0.0f, 100.0f));
    }
    if (texturaScribbled01Menu.loadFromFile("../assets/menu/scribbled001.png") && texturaScribbled02Menu.loadFromFile("../assets/menu/scribbled002.png"))
    {
        spriteScribbledMenu.setTexture(texturaScribbled01Menu, true);
        sf::Vector2u tamanhoScribbled = texturaScribbled01Menu.getSize();
        spriteScribbledMenu.setOrigin(sf::Vector2f(tamanhoScribbled.x / 2.0f, tamanhoScribbled.y / 2.0f));
        spriteScribbledMenu.setPosition(sf::Vector2f(720.0f, 650.0f));
    }
    if (texturaSetaMenu.loadFromFile("../assets/menu/arrow001.png"))
    {
        spriteSetaMenu.setTexture(texturaSetaMenu, true);
        sf::Vector2u tamanhoSeta = texturaSetaMenu.getSize();
        spriteSetaMenu.setOrigin(sf::Vector2f(tamanhoSeta.x / 2.0f, tamanhoSeta.y / 2.0f));
        spriteSetaMenu.setPosition(sf::Vector2f(625.0f, 800.0f));
    }
    if (texturaStartMenu.loadFromFile("../assets/menu/start001.png"))
    {
        spriteStartMenu.setTexture(texturaStartMenu, true);
        sf::Vector2u tamanhoStart = texturaStartMenu.getSize();
        spriteStartMenu.setOrigin(sf::Vector2f(0, tamanhoStart.y / 2.0f));
        spriteStartMenu.setPosition(sf::Vector2f(700.0f, 800.0f));
    }
    if (texturaTutorialMenu.loadFromFile("../assets/menu/tutorial001.png"))
    {
        spriteTutorialMenu.setTexture(texturaTutorialMenu, true);
        sf::Vector2u tamanhoTutorial = texturaTutorialMenu.getSize();
        spriteTutorialMenu.setOrigin(sf::Vector2f(0, tamanhoTutorial.y / 2.0f));
        spriteTutorialMenu.setPosition(sf::Vector2f(600.0f, 900.0f));
    }
    if (UIJogo.loadFromFile("../assets/uiplayerrpss/uiplayer001.png"))
    {
        spriteUIJogo.setTexture(UIJogo, true);
        spriteUIJogo.setPosition(sf::Vector2f(0.0f, 0.0f));
    }
    /*if (texturaTutorial.loadFromFile("../assets/tutorialscreennewrpss/tutorialscreennew001.png"))
    {
        spriteTutorial.setTexture(texturaTutorial);
        sf::Vector2u tamanhoTutorial = texturaTutorial.getSize();
        spriteTutorial.setOrigin(sf::Vector2f(tamanhoTutorial.x / 2.0f, 0.0f));
    }*/
    if (texturaMaoInt01.loadFromFile("../assets/jogador/handint001.png") &&
        texturaMaoInt02.loadFromFile("../assets/jogador/handint002.png") &&
        texturaMaoPapel.loadFromFile("../assets/jogador/handpaper001.png") &&
        texturaMaoTesoura.loadFromFile("../assets/jogador/handscissor001.png") &&
        texturaMaoPedra.loadFromFile("../assets/jogador/handrock001.png") &&
        texturaMaoCima.loadFromFile("../assets/jogador/handup001.png") &&
        texturaMaoDireita.loadFromFile("../assets/jogador/handright001.png") &&
        texturaMaoEsquerda.loadFromFile("../assets/jogador/handleft001.png") &&
        texturaMaoBaixo.loadFromFile("../assets/jogador/handdown001.png"))
    {
        spriteMaoJogador.setTexture(texturaMaoInt01, true);
        sf::Vector2u tamanhoMao = texturaMaoInt01.getSize();
        spriteMaoJogador.setOrigin(sf::Vector2f(tamanhoMao.x, tamanhoMao.y));
        spriteMaoJogador.setPosition(sf::Vector2f(1440.0f, 960.0f));
    }

    if (texturaOponenteInt01.loadFromFile("../assets/oponente/girlint001.png") &&
        texturaOponenteInt02.loadFromFile("../assets/oponente/girlint002.png") &&
        texturaOponentePapel.loadFromFile("../assets/oponente/girlpaper001.png") &&
        texturaOponenteTesoura.loadFromFile("../assets/oponente/girlscissor001.png") &&
        texturaOponentePedra.loadFromFile("../assets/oponente/girlrock001.png") &&
        texturaOponenteCimaFase02.loadFromFile("../assets/oponente/girltype002up001.png") &&
        texturaOponenteDireitaFase02.loadFromFile("../assets/oponente/girltype002right001.png") &&
        texturaOponenteEsquerdaFase02.loadFromFile("../assets/oponente/girltype002left001.png") &&
        texturaOponenteBaixoFase02.loadFromFile("../assets/oponente/girltype002down001.png") &&
        texturaOponenteCimaFase03.loadFromFile("../assets/oponente/girltype003up001.png") &&
        texturaOponenteDireitaFase03.loadFromFile("../assets/oponente/girltype003right001.png") &&
        texturaOponenteEsquerdaFase03.loadFromFile("../assets/oponente/girltype003left001.png") &&
        texturaOponenteBaixoFase03.loadFromFile("../assets/oponente/girltype003down001.png") &&
        texturaOponenteVitoria01.loadFromFile("../assets/oponente/girlwin001.png") &&
        texturaOponenteVitoria02.loadFromFile("../assets/oponente/girlwin002.png") &&
        texturaOponenteDerrota.loadFromFile("../assets/oponente/girlloss001.png") &&
        texturaOponenteOlhosCima.loadFromFile("../assets/oponente/girleyesup001.png") &&
        texturaOponenteOlhosDireita.loadFromFile("../assets/oponente/girleyesright001.png") &&
        texturaOponenteOlhosEsquerda.loadFromFile("../assets/oponente/girleyesleft001.png") &&
        texturaOponenteOlhosBaixo.loadFromFile("../assets/oponente/girleyesdown001.png"))
    {
        spriteOponente.setTexture(texturaOponenteInt01, true);
        sf::Vector2u tamanhoOponente = texturaOponenteInt01.getSize();
        spriteOponente.setOrigin(sf::Vector2f(0, 0));
        spriteOponente.setPosition(sf::Vector2f(50.0f, 150.0f));
    }
    if (texturaVidaCheia.loadFromFile("../assets/uiplayerrpss/heartnew001.png") &&
        texturaVidaVazia.loadFromFile("../assets/uiplayerrpss/heartnew002.png"))
    {
        spriteVida001.setTexture(texturaVidaCheia, true);
        spriteVida001.setPosition(sf::Vector2f(100.0f, -10.0f));
        spriteVida002.setTexture(texturaVidaCheia, true);
        spriteVida002.setPosition(sf::Vector2f(200.0f, -5.0f));
        spriteVida003.setTexture(texturaVidaCheia, true);
        spriteVida003.setPosition(sf::Vector2f(300.0f, 0.0f));
    }
    if (texturaBackFimDeJogo.loadFromFile("../assets/retryrpss/backretry.png") &&
        texturaRetry01.loadFromFile("../assets/retryrpss/retry001.png") &&
        texturaRetry02.loadFromFile("../assets/retryrpss/retry002.png") &&
        texturaMenu01.loadFromFile("../assets/retryrpss/retrymenu001.png") &&
        texturaMenu02.loadFromFile("../assets/retryrpss/retrymenu002.png") &&
        texturaArrowFimDeJogo.loadFromFile("../assets/retryrpss/retryarrow002.png") &&
        texturaScore.loadFromFile("../assets/retryrpss/retryscore001.png"))
    {
        spriteBackFimDeJogo.setTexture(texturaBackFimDeJogo, true);
        sf::Vector2u tamanhoBackFim = texturaBackFimDeJogo.getSize();
        spriteBackFimDeJogo.setOrigin(sf::Vector2f(tamanhoBackFim.x, tamanhoBackFim.y));
        spriteBackFimDeJogo.setPosition(sf::Vector2f(1440.0f, 960.0f));

        spriteRetry.setTexture(texturaRetry01, true);
        spriteRetry.setOrigin(sf::Vector2f(0.0f, texturaRetry01.getSize().y / 2.0f));
        spriteRetry.setPosition(sf::Vector2f(950.0f, 600.0f));

        spriteMenu.setTexture(texturaMenu01, true);
        spriteMenu.setOrigin(sf::Vector2f(0.0f, texturaMenu01.getSize().y / 2.0f));
        spriteMenu.setPosition(sf::Vector2f(875.0f, 800.0f));

        spriteArrowFimDeJogo.setTexture(texturaArrowFimDeJogo, true);
        spriteArrowFimDeJogo.setOrigin(sf::Vector2f(0.0f, texturaArrowFimDeJogo.getSize().y / 2.0f));
        spriteArrowFimDeJogo.setPosition(sf::Vector2f(825.0f, 600.0f));

        spriteScore.setTexture(texturaScore, true);
        spriteScore.setPosition(sf::Vector2f(800.0f, 0.0f));
    }
}

// Função que toca a batida apenas uma vez
void Game::tocarBatida(int tipoBatida)
{
    if (ultimaBatida != tipoBatida)
    {
        if (tipoBatida == 4)
        {
            somBatida.setBuffer(bufferSomBatida01);
        }
        else
        {
            somBatida.setBuffer(bufferSomBatida02);
        }

        ultimaBatida = tipoBatida;
        somBatida.play();
    }
}

void Game::moverSprites(sf::Sprite &sprite, float passoPorSegundo)
{
    sprite.move(sf::Vector2f(-passoPorSegundo, 0.0f)); // Move o sprite para a esquerda de acordo com o passo
}

void Game::transicionarTelas(vector<sf::Sprite *> sprites, float passoPorSegundo)
{
    for (int i = 0; i < sprites.size(); i++)
    {
        moverSprites(*sprites[i], passoPorSegundo);
    }
}

// Função que prepara o ínicio de um novo round
void Game::iniciarRound(EstadoJogo novoEstado)
{
    estadoAtual = novoEstado;
    escolhaJogador = 0;         // Zera a sua escolha
    jogadaFinalizada = false;   // Avisa que o tempo tá rolando
    resultadoCalculado = false; // Avisa que o resultado ainda não foi calculado

    // Reseta a última batida tocada
    ultimaBatida = 0;

    // O oponente já faz a escolha dele AQUI, no inicio da rodada
    if (estadoAtual == EstadoJogo::Round1)
    {
        escolhaOponente = (rand() % 3) + 1;
    }
    else
    {
        escolhaOponente = (rand() % 4) + 1;
    }

    clockPrincipal.restart(); // Dispara o cronômetro!
}

void Game::run()
{
    while (window.isOpen())
    {
        processarEventos();
        atualizar();
        renderizar();
    }
}

void Game::processarEventos()
{
    while (const auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }

        const auto *keyPressed = event->getIf<sf::Event::KeyPressed>();

        if (keyPressed)
        {
            if (estadoAtual == EstadoJogo::Menu)
            {
                /*if (keyPressed->code == sf::Keyboard::Key::Up)
                {
                    if (opcaoMenu == 2)
                    {
                        opcaoMenu = 1;

                        spriteTutorialMenu.setPosition(sf::Vector2f(600.0f, 900.0f));
                        spriteStartMenu.setPosition(sf::Vector2f(700.0f, 800.0f));
                        spriteSetaMenu.setPosition(sf::Vector2f(625.0f, 800.0f));

                        window.draw(spriteTutorialMenu);
                        window.draw(spriteStartMenu);
                        window.draw(spriteSetaMenu);
                    }
                }
                if (keyPressed->code == sf::Keyboard::Key::Down)
                {
                    if (opcaoMenu == 1)
                    {
                        opcaoMenu = 2;

                        spriteTutorialMenu.setPosition(sf::Vector2f(675.0f, 900.0f));
                        spriteStartMenu.setPosition(sf::Vector2f(600.0f, 800.0f));
                        spriteSetaMenu.setPosition(sf::Vector2f(625.0f, 900.0f));

                        window.draw(spriteTutorialMenu);
                        window.draw(spriteStartMenu);
                        window.draw(spriteSetaMenu);
                    }
                }*/
                if (keyPressed->code == sf::Keyboard::Key::Enter && !emTransicao)
                {
                    if (opcaoMenu == 1)
                    {
                        // Define o próximo estado como o round 1 (inicia o jogo)
                        proximoEstado = EstadoJogo::Round1;

                        emTransicao = true;
                        ehTransicaoFade = true;

                        tempoLimite = TEMPO_INICIAL;
                        vidas = 3;
                        pontuacao = 0;
                    }
                    /*else if (opcaoMenu == 2)
                    {
                        proximoEstado = EstadoJogo::Tutorial;

                        // Começa a transição entre as telas
                        emTransicao = true;

                        // Insere os sprites que serão movidos na transição
                        listaSpritesProximo.insert(listaSpritesProximo.end(), {&spriteTutorial});

                        // Checa se está em transição
                        if (emTransicao)
                        {
                            // Caso esteja, move todos os sprites para a direita da tela, para que eles possam ser movidos para a esquerda
                            for (int i = 0; i < listaSpritesProximo.size(); i++)
                            {
                                listaSpritesProximo[i]->setPosition(sf::Vector2f(listaSpritesProximo[i]->getPosition().x + 1440, listaSpritesProximo[i]->getPosition().y));
                            }
                        }
                    }*/
                }
            }
            /*else if (estadoAtual == EstadoJogo::Tutorial)
            {
            }*/
            else if (estadoAtual == EstadoJogo::Round1 || estadoAtual == EstadoJogo::Round2 || estadoAtual == EstadoJogo::Round3)
            {

                // Enquanto o tempo não acabar, o jogador pode mudar de ideia à vontade!
                if (!jogadaFinalizada)
                {
                    if (keyPressed->code == sf::Keyboard::Key::Up)
                    {
                        escolhaJogador = 1;
                    }
                    else if (keyPressed->code == sf::Keyboard::Key::Right)
                    {
                        escolhaJogador = 2;
                    }
                    else if (keyPressed->code == sf::Keyboard::Key::Left)
                    {
                        escolhaJogador = 3;
                    }
                    else if (keyPressed->code == sf::Keyboard::Key::Down)
                    {
                        if (estadoAtual != EstadoJogo::Round1)
                        {
                            escolhaJogador = 4;
                        }
                    }
                }
            }
            else if (estadoAtual == EstadoJogo::FimDeJogo)
            {
                if (keyPressed->code == sf::Keyboard::Key::Up)
                {
                    if (opcaoFimDeJogo == 2)
                    {
                        opcaoFimDeJogo = 1;

                        spriteRetry.setPosition(sf::Vector2f(950.0f, 600.0f));
                        spriteMenu.setPosition(sf::Vector2f(875.0f, 800.0f));
                        spriteArrowFimDeJogo.setPosition(sf::Vector2f(825.0f, 600.0f));

                        window.draw(spriteRetry);
                        window.draw(spriteMenu);
                        window.draw(spriteArrowFimDeJogo);
                    }
                }
                else if (keyPressed->code == sf::Keyboard::Key::Down)
                {
                    if (opcaoFimDeJogo == 1)
                    {
                        opcaoFimDeJogo = 2;

                        spriteRetry.setPosition(sf::Vector2f(875.0f, 600.0f));
                        spriteMenu.setPosition(sf::Vector2f(950.0f, 800.0f));
                        spriteArrowFimDeJogo.setPosition(sf::Vector2f(825.0f, 800.0f));

                        window.draw(spriteRetry);
                        window.draw(spriteMenu);
                        window.draw(spriteArrowFimDeJogo);
                    }
                }
                else if (keyPressed->code == sf::Keyboard::Key::Enter)
                {
                    if (opcaoFimDeJogo == 1)
                    {
                        proximoEstado = EstadoJogo::Round1;

                        emTransicao = true;
                        ehTransicaoFade = true;
                        
                        tempoLimite = TEMPO_INICIAL;
                        vidas = 3;
                        pontuacao = 0;
                    }
                    else
                    {
                        proximoEstado = EstadoJogo::Menu;

                        emTransicao = true;
                        ehTransicaoFade = true;
                    }
                }
            }
        }
    }
}

void Game::atualizar()
{
    // Condicional que checa se está em transição entre telas
    if (emTransicao)
    {
        float tempoPorQuadro = 1.0f / 60.0f;    // Tempo por quadro (FPS)
        float tempoTransicao = TEMPO_TRANSICAO; // Tempo em segundos da transição por slide
        float velocidadeFade = 600.0f;          // Velocidade do fade in e fade out da transição

        if (ehTransicaoFade)
        {
            if (fade)
            {
                opacidadeTransicao += velocidadeFade * tempoPorQuadro;

                if (opacidadeTransicao >= 255.0f)
                {
                    opacidadeTransicao = 255.0f;
                    fade = false;

                    // Passa para o próximo estado do jogo
                    iniciarRound(proximoEstado);
                }
            }
            else
            {
                opacidadeTransicao -= velocidadeFade * tempoPorQuadro;

                if (opacidadeTransicao <= 0.0f)
                {
                    opacidadeTransicao = 0.0f;
                    emTransicao = false;
                    fade = true;
                    ehTransicaoFade = false;
                }
            }

            telaTransicao.setFillColor(sf::Color(255, 255, 255, static_cast<uint8_t>(opacidadeTransicao)));
        }
        else
        {
            float pixeisPorSegundo = 1440 / tempoTransicao;            // Calcula os pixeis a serem andados por segundo
            float passoPorSegundo = pixeisPorSegundo * tempoPorQuadro; // Calcula os pixeis a serem andados por quadro

            pixeisAndadosX += passoPorSegundo; // Atualiza a quantidade de pixels andados

            if (listaSpritesAtual.size() > 0)
            {
                transicionarTelas(listaSpritesAtual, passoPorSegundo);
            }
            transicionarTelas(listaSpritesProximo, passoPorSegundo);

            // Checa se os sprites já andaram a distância total da tela
            if (pixeisAndadosX >= 1440.0f)
            {
                // Passa para o próximo estado do jogo
                iniciarRound(proximoEstado);

                // Reseta as variáveis de controle da transição
                emTransicao = false;
                pixeisAndadosX = 0.0f;
                listaSpritesProximo.clear();
                listaSpritesAtual.clear();
            }
        }
    }

    if (estadoAtual == EstadoJogo::SplashScreen)
    {
        if (clockSplashScreen.getElapsedTime().asSeconds() >= TEMPO_SPLASH && !emTransicao)
        {
            // Define o próximo estado após a transição
            proximoEstado = EstadoJogo::TeamSplash;

            // Começa a transição entre as telas
            emTransicao = true;

            // Insere os sprites que serão movidos na transição
            listaSpritesProximo.insert(listaSpritesProximo.end(), {&spriteBackSplash,
                                                                   &spriteTeamSplash});

            // Caso esteja, move todos os sprites para a direita da tela, para que eles possam ser movidos para a esquerda
            for (int i = 0; i < listaSpritesProximo.size(); i++)
            {
                listaSpritesProximo[i]->setPosition(sf::Vector2f(listaSpritesProximo[i]->getPosition().x + 1440, listaSpritesProximo[i]->getPosition().y));
            }

            clockSplashScreen.restart();
        }
    }

    if (estadoAtual == EstadoJogo::TeamSplash)
    {
        if (clockSplashScreen.getElapsedTime().asSeconds() >= TEMPO_SPLASH && !emTransicao)
        {
            // Define a próxima tela a ser mostrada
            proximoEstado = EstadoJogo::Menu;

            // Flags que ativam a transição por fade
            emTransicao = true;
            ehTransicaoFade = true;

            clockSplashScreen.restart();
        }
    }

    if (estadoAtual == EstadoJogo::Menu)
    {
        // Checa se o clock da animação contou 0,5 segundos
        if (clockAnimacaoScribbled.getElapsedTime().asSeconds() >= 0.5f)
        {
            // Checa qual frame está sendo exibido nesse momento
            if (ehFrameScribbled01)
            {
                // Muda os frames
                spriteScribbledMenu.setTexture(texturaScribbled02Menu, true);
                ehFrameScribbled01 = false;
            }
            else
            {
                // Muda os frames
                spriteScribbledMenu.setTexture(texturaScribbled01Menu, true);
                ehFrameScribbled01 = true;
            }

            clockAnimacaoScribbled.restart();
        }
    }

    if (estadoAtual == EstadoJogo::FimDeJogo)
    {
        // Checa se o clock da animação contou 0,5 segundos
        if (clockAnimacaoFimDeJogo.getElapsedTime().asSeconds() >= 0.5f)
        {
            // Checa qual frame está sendo exibido nesse momento
            if (ehFrameFimDeJogo01)
            {
                // Muda os frames
                spriteRetry.setTexture(texturaRetry02, true);
                spriteMenu.setTexture(texturaMenu02, true);
                // Define se o placar final deve aparecer
                mostrarPlacarFinal = false;
                ehFrameFimDeJogo01 = false;
            }
            else
            {
                // Muda os frames
                spriteRetry.setTexture(texturaRetry01, true);
                spriteMenu.setTexture(texturaMenu01, true);
                // Define se o placar final deve aparecer
                mostrarPlacarFinal = true;
                ehFrameFimDeJogo01 = true;
            }

            // Checa se o clock da animação contou 0,5 segundos
            if (clockAnimacaoOponente.getElapsedTime().asSeconds() >= 0.5f)
            {
                // Checa qual frame está sendo exibido nesse momento
                if (ehFrameOponente01)
                {
                    // Muda os frames
                    spriteOponente.setTexture(texturaOponenteVitoria02, true);
                    ehFrameOponente01 = false;
                }
                else
                {
                    // Muda os frames
                    spriteOponente.setTexture(texturaOponenteVitoria01, true);
                    ehFrameOponente01 = true;
                }
            }

            textoPlacarFimDeJogo = textoPlacar;

            textoPlacarFimDeJogo.setCharacterSize(200);
            textoPlacarFimDeJogo.setLetterSpacing(2.0f);
            textoPlacarFimDeJogo.setPosition(sf::Vector2f(1460, 235));

            clockAnimacaoFimDeJogo.restart();
            clockAnimacaoOponente.restart();
        }
    }

    if (estadoAtual == EstadoJogo::Round1 || estadoAtual == EstadoJogo::Round2 || estadoAtual == EstadoJogo::Round3)
    {
        if (vidas >= 1)
            spriteVida001.setTexture(texturaVidaCheia, true);
        else
            spriteVida001.setTexture(texturaVidaVazia, true);

        if (vidas >= 2)
            spriteVida002.setTexture(texturaVidaCheia, true);
        else
            spriteVida002.setTexture(texturaVidaVazia, true);

        if (vidas >= 3)
            spriteVida003.setTexture(texturaVidaCheia, true);
        else
            spriteVida003.setTexture(texturaVidaVazia, true);

        sf::Vector2u tamanhoJanela = window.getSize();

        // Arrays de ponteiros para as texturas do jogador
        sf::Texture *opcoesJankenpoJogador[] = {&texturaMaoPapel, &texturaMaoTesoura, &texturaMaoPedra};
        sf::Texture *opcoesDirecaoJogador[] = {&texturaMaoCima, &texturaMaoDireita, &texturaMaoEsquerda, &texturaMaoBaixo};

        // Arrays de ponteiros para as texturas do oponente
        sf::Texture *opcoesJankenpoOponente[] = {&texturaOponentePapel, &texturaOponenteTesoura, &texturaOponentePedra};
        sf::Texture *opcoesDirecaoOponenteFase02[] = {&texturaOponenteCimaFase02, &texturaOponenteDireitaFase02, &texturaOponenteEsquerdaFase02, &texturaOponenteBaixoFase02};
        sf::Texture *opcoesDirecaoOponenteFase03[] = {&texturaOponenteCimaFase03, &texturaOponenteDireitaFase03, &texturaOponenteEsquerdaFase03, &texturaOponenteBaixoFase03};
        sf::Texture *opcoesDirecaoOponenteOlhos[] = {&texturaOponenteOlhosCima, &texturaOponenteOlhosDireita, &texturaOponenteOlhosEsquerda, &texturaOponenteOlhosBaixo};

        // ========================================================
        // 1. O TEMPO ESTÁ ROLANDO (A MESA ESTÁ ABERTA)
        // ========================================================
        if (!jogadaFinalizada)
        {
            float tempoRestante = tempoLimite - clockPrincipal.getElapsedTime().asSeconds();
            float tempoPassado = clockPrincipal.getElapsedTime().asSeconds();

            // Mostra o cronômetro descendo na tela
            if (tempoRestante > 0.0f)
            {
                // Mostra o que você selecionou até agora
                if (estadoAtual == EstadoJogo::Round1)
                {
                    if (tempoPassado > tempoLimite * 0.8f)
                    {
                        spriteMaoJogador.setTexture(texturaMaoInt02, true);
                        spriteOponente.setTexture(texturaOponenteInt02, true);
                        tocarBatida(1);
                    }
                    else if (tempoPassado > tempoLimite * 0.6f)
                    {
                        spriteMaoJogador.setTexture(texturaMaoInt01, true);
                        spriteOponente.setTexture(texturaOponenteInt01, true);
                        tocarBatida(2);
                    }
                    else if (tempoPassado > tempoLimite * 0.4f)
                    {
                        spriteMaoJogador.setTexture(texturaMaoInt02, true);
                        spriteOponente.setTexture(texturaOponenteInt02, true);
                        tocarBatida(3);
                    }
                    else if (tempoPassado >= 0.0f)
                    {
                        spriteMaoJogador.setTexture(texturaMaoInt01, true);
                        spriteOponente.setTexture(texturaOponenteInt01, true);
                    }
                }
                else if (estadoAtual == EstadoJogo::Round2)
                {
                    if (tempoPassado > tempoLimite * 0.5f)
                    {
                        spriteOponente.setTexture(*opcoesDirecaoOponenteOlhos[escolhaOponente - 1], true);
                        tocarBatida(1);
                    }
                    else if (tempoPassado >= 0.0f)
                    {
                        spriteOponente.setTexture(texturaOponenteInt01, true);
                    }

                    if (tempoPassado > tempoLimite * 0.8f)
                    {
                        spriteMaoJogador.setTexture(texturaMaoInt02, true);
                    }
                    else if (tempoPassado >= 0.0f)
                    {
                        spriteMaoJogador.setTexture(texturaMaoInt01, true);
                    }
                }
                else if (estadoAtual == EstadoJogo::Round3)
                {
                    if (tempoPassado > tempoLimite * 0.5f)
                    {
                        spriteOponente.setTexture(*opcoesDirecaoOponenteOlhos[escolhaOponente - 1], true);
                        tocarBatida(2);
                    }
                    else if (tempoPassado >= 0.0f)
                    {
                        spriteOponente.setTexture(texturaOponenteInt01, true);
                    }

                    if (tempoPassado > tempoLimite * 0.8f)
                    {
                        spriteMaoJogador.setTexture(texturaMaoInt02, true);
                    }
                    else if (tempoPassado >= 0.0f)
                    {
                        spriteMaoJogador.setTexture(texturaMaoInt01, true);
                    }
                }
            }
            // O TEMPO ACABOU! TRAVA A JOGADA.
            else
            {
                if (escolhaJogador == 0)
                    escolhaJogador = -1; // Se não escolheu nada, perdeu por tempo
                jogadaFinalizada = true;
                clockJogadaFinalizada.restart();
            }

            wstringstream ss;
            ss << setfill(L'0') << setw(4) << pontuacao;
            textoPlacar.setString(ss.str());
            // textoVidas.setString(L"Vidas: " + std::to_wstring(vidas));
        }

        // ========================================================
        // 2. O TEMPO ACABOU (MOSTRA O RESULTADO)
        // ========================================================
        else
        {
            // Se o resultado ainda não foi calculado, calcula o resultado da rodada
            if (!resultadoCalculado)
            {
                resultadoCalculado = true; // Marca que o resultado já foi calculado

                if (estadoAtual == EstadoJogo::Round1)
                {
                    if (escolhaJogador != -1)
                    {
                        spriteMaoJogador.setTexture(*opcoesJankenpoJogador[escolhaJogador - 1], true);
                    }
                }
                else if (estadoAtual == EstadoJogo::Round2)
                {
                    if (escolhaJogador != -1)
                    {
                        spriteMaoJogador.setTexture(*opcoesDirecaoJogador[escolhaJogador - 1], true);
                    }
                }
                else if (estadoAtual == EstadoJogo::Round3)
                {
                    if (escolhaJogador != -1)
                    {
                        spriteMaoJogador.setTexture(*opcoesDirecaoJogador[escolhaJogador - 1], true);
                    }
                }

                // REGRAS DO ROUND 1
                if (estadoAtual == EstadoJogo::Round1)
                {
                    if (escolhaJogador == -1)
                    {
                        texturaFinalRodada = texturaOponenteVitoria01;

                        proximoEstado = EstadoJogo::Round3;
                    }
                    else if (escolhaJogador == escolhaOponente)
                    {
                        proximoEstado = EstadoJogo::Round1;
                    }
                    // CONDICIONAL DE VITÓRIA
                    else if ((escolhaJogador == 1 && escolhaOponente == 3) ||
                             (escolhaJogador == 2 && escolhaOponente == 1) ||
                             (escolhaJogador == 3 && escolhaOponente == 2))
                    {
                        texturaFinalRodada = texturaOponenteDerrota;
                        proximoEstado = EstadoJogo::Round2;
                    }
                    // CONDICIONAL DE DERROTA
                    else
                    {
                        texturaFinalRodada = texturaOponenteVitoria01;

                        proximoEstado = EstadoJogo::Round3;
                    }
                }

                // REGRAS DO ROUND 2
                else if (estadoAtual == EstadoJogo::Round2)
                {
                    if (escolhaJogador == escolhaOponente && escolhaJogador != -1)
                    {
                        pontuacao++;
                        texturaFinalRodada = texturaOponenteDerrota;
                        proximoEstado = EstadoJogo::Round1;
                    }
                    else
                    {
                        texturaFinalRodada = texturaOponenteVitoria01;
                        proximoEstado = EstadoJogo::Round1;
                    }

                    if (tempoLimite > TEMPO_MINIMO)
                    {
                        tempoLimite -= 0.1f;
                    }
                }

                // REGRAS DO ROUND 3
                else if (estadoAtual == EstadoJogo::Round3)
                {
                    if (escolhaJogador != escolhaOponente && escolhaJogador != -1)
                    {
                        texturaFinalRodada = texturaOponenteDerrota;
                        proximoEstado = EstadoJogo::Round1;
                    }
                    else
                    {
                        texturaFinalRodada = texturaOponenteVitoria01;
                        vidas--;
                        if (vidas <= 0)
                        {
                            proximoEstado = EstadoJogo::FimDeJogo;

                            // Começa a transição entre as telas
                            emTransicao = true;

                            // Insere os sprites que serão movidos na transição
                            listaSpritesProximo.insert(listaSpritesProximo.end(), {&spriteBackFimDeJogo,
                                                                                   &spriteRetry,
                                                                                   &spriteMenu,
                                                                                   &spriteArrowFimDeJogo,
                                                                                   &spriteScore});

                            // Checa se está em transição
                            if (emTransicao)
                            {
                                // Caso esteja, move todos os sprites para a direita da tela, para que eles possam ser movidos para a esquerda
                                for (int i = 0; i < listaSpritesProximo.size(); i++)
                                {
                                    listaSpritesProximo[i]->setPosition(sf::Vector2f(listaSpritesProximo[i]->getPosition().x + 1440, listaSpritesProximo[i]->getPosition().y));
                                }
                            }
                        }
                        else
                        {
                            proximoEstado = EstadoJogo::Round1;
                        }
                    }

                    if (tempoLimite > TEMPO_MINIMO)
                    {
                        tempoLimite -= 0.1f;
                    }
                }
            }
        }

        // ========================================================
        // 3. TRANSIÇÃO DE TELAS (O RESET APÓS 3 SEGUNDOS)
        // ========================================================
        if (jogadaFinalizada)
        {
            tocarBatida(4); // Toca a batida final da rodada

            float tempoEspera = clockJogadaFinalizada.getElapsedTime().asSeconds();

            if (tempoEspera < tempoLimite * 0.7f)
            {
                if (estadoAtual == EstadoJogo::Round1)
                {
                    spriteOponente.setTexture(*opcoesJankenpoOponente[escolhaOponente - 1], true);
                }
                else if (estadoAtual == EstadoJogo::Round2)
                {
                    spriteOponente.setTexture(*opcoesDirecaoOponenteFase02[escolhaOponente - 1], true);
                }
                else if (estadoAtual == EstadoJogo::Round3)
                {
                    spriteOponente.setTexture(*opcoesDirecaoOponenteFase03[escolhaOponente - 1], true);
                }
            }
            else if (tempoEspera < tempoLimite * 1.4f)
            {
                spriteOponente.setTexture(texturaFinalRodada, true);
            }
            else
            {
                texturaFinalRodada = texturaOponenteInt01; // Reseta a textura do oponente para a próxima rodada
                spriteMaoJogador.setTexture(texturaMaoInt01, true);

                if (!emTransicao)
                {
                    // Passa para o próximo estado do jogo (round)
                    iniciarRound(proximoEstado);
                }
            }
        }

        // ALINHAMENTOS NA TELA (Inalterado)
        textoPlacar.setOrigin(sf::Vector2f(textoPlacar.getLocalBounds().size.x, 0.0f));
        textoPlacar.setPosition(sf::Vector2f(1200, -15));
    }
}

void Game::renderizar()
{
    window.clear();

    window.draw(spriteBackground);

    if (estadoAtual == EstadoJogo::SplashScreen)
    {
        window.draw(spriteSplashScreen);
    }

    if (estadoAtual == EstadoJogo::TeamSplash)
    {
        window.draw(spriteBackSplash);
        window.draw(spriteTeamSplash);
    }

    if (estadoAtual == EstadoJogo::Menu || estadoAtual == EstadoJogo::Tutorial)
    {
        window.draw(spriteLogoMenu);
        window.draw(spriteScribbledMenu);
        window.draw(spriteStartMenu);
        window.draw(spriteSetaMenu);
    }
    else if (estadoAtual == EstadoJogo::Round1 || estadoAtual == EstadoJogo::Round2 || estadoAtual == EstadoJogo::Round3 || estadoAtual == EstadoJogo::FimDeJogo)
    {
        window.draw(spriteUIJogo);
        window.draw(textoPlacar);
        window.draw(spriteMaoJogador);
        window.draw(spriteOponente);
        window.draw(spriteVida001);
        window.draw(spriteVida002);
        window.draw(spriteVida003);

        if (estadoAtual == EstadoJogo::FimDeJogo)
        {
            window.draw(spriteBackFimDeJogo);
            window.draw(spriteRetry);
            window.draw(spriteMenu);
            window.draw(spriteArrowFimDeJogo);
            window.draw(spriteScore);
            if (mostrarPlacarFinal)
            {
                window.draw(textoPlacarFimDeJogo);
            }
        }
    }

    if (emTransicao)
    {
        window.draw(telaTransicao);

        for (int i = 0; i < listaSpritesProximo.size(); i++)
        {
            window.draw(*listaSpritesProximo[i]);
        }
    }

    window.display();
}