# Base Defense
[![THUMBNAIL](/assets/thumbnail.png)](https://www.youtube.com/watch?v=HMqWopFdOXg)

# Sumário
- [Instruções para compilar e executar](#instruções-para-compilar-e-executar):
  - [Lista de comandos](#comandos-gerais);
- [Sobre o jogo](#sobre-o-jogo):
  - [Autores](#autores);
  - [Como jogar](#como-jogar):
    - [Controles](#controles).
  - [Melhorias e ofertas da loja](#melhorias-e-ofertas-da-loja):
    - [Sempre vem uma](#sempre-vem-uma);
    - [Comuns](#comuns);
    - [Raras](#raras);
    - [Épicas](#épicas).
- [Recursos implementados](#recursos-implementados);
- [Recursos do c++ usados](#recursos-do-c-usados);
- [Recursos de bibliotecas externas usados](#recursos-de-bibliotecas-externas-usados).

# Instruções para compilar e executar
- Instale o `Make`, no caso do `Windows`, use esse [aqui](_windows/winlibs-x86_64-posix-seh-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5.7z) (que é o compatível);
- Em algumas máquinas `Linux` pode ser necessário instalar o [sfml](https://www.sfml-dev.org/download/sfml/2.6.1/), mas nós utilizamos a biblioteca já compilada no `Ubuntu` para não precisar instalar o `sfml` nele;
- Instale o `OpenAl`, disponível [aqui](https://www.openal.org/downloads/):
    - No `Ubuntu` talvez não precise, mas, por garantia, basta instalar o pacote `libopenal-dev` executando o comando:
        ```
        sudo apt install libopenal-dev
        ```
- Dentro da raíz do projeto, execute `make dev` e vai compilar e executar o jogo.

## Lista de comandos
- `make` - vai compilar tanto o jogo como os testes;
- `make test` - vai compilar e executar os testes;
- `make dev` - vai compilar e executar o jogo;
- `make run` - vai executar o jogo (se compilado);
- `make compile` - vai compilar o jogo;
- `make clean` - vai limpar o `_build`;
- `make valgrind` - vai compilar e executar o jogo usando o `valgrind` (fica bem mais lento e precisa ter o `valgrind` instalado).

# Sobre o jogo
Defenda sua base para sobreviver e passar por hordas inteiras de inimigos que querem sua cabeça nesse jogo produzido como projeto da disciplina de `Linguagem de Programação` ofertada na `UFRN`.

## Autores
- [`Antonio Henrique Barbosa Lima`](https://github.com/HenriqueeeBL);
- [`Arthur Queiroz Pires de Farias`](https://github.com/MisterR2);
- [`Lucas Marcel Silva de Brito`](https://github.com/L-Marcel);
- [`Pedro Paulo Galvão Galindo de Oliveira`](https://github.com/Pedr0P4).

Exceto pela música, sons e fontes, todos os `assets` utilizados no jogo foram feitos por nós. Quanto ao restante do material, agradecemos:

- Pixeloid: pelas fontes;
- Jdsherbert: por alguns sons;
- Shapeforms: pela música e por alguns sons.

Esperamos não ter esquecido ninguém. Deixamos as licenças dentro do repositório.

## Como jogar
Proteja sua base, saia para coletar munição e vida quando necessário, junte moedas derrotando inimigos e faça a melhor sequência de melhorias que conseguir; evite atirar em direção a própria base quando estiver fora dela, pois suas balas também causaram dano a elas; evite o máximo de dano que puder fora da base e saiba tirar proveito das suas sentinelas.

### Controles
- `Botão direito do mouse`: andar;
- `Q` / `Botão esquerdo do mouse`: atirar;
- `R`: recarregar;
- `Esc`: pausar.

## Melhorias e ofertas da loja
### Sempre vem uma
Observação: podem ser compradas mais de uma vez na mesma oferta, mas o preço aumenta.
- Cura imediatamente `25%` de vida;
- Repara imediatamente `25%` da base;
- Restaura imediatamente `25%` da munição.
### Comuns
- Aumenta a vida em:
  - `+10` / `+10` / `+20` / `+30` / `+40` / `+40` pontos.
- Aumenta a vida da base em:
  - `+10` / `+10` / `+20` / `+30` / `+40` / `+40` / `+50` pontos.
- Aumenta a munição do pente em:
  - `+2` / `+2` / `+2` / `+2` balas.
- Aumenta a munição em:
  - `+2` / `+2` / `+4` / `+4` / `+6` / `+6` balas.
- Aumenta a velocidade de disparo em:
  - `+10%` / `+20%` / `+30%` / `+40%`.
### Raras
- O reparo da base fica:
  - `+10%` / `+15%` / `+20%` / `+25%` / `+30%` / `+35%` / `+40%` / `+45%` / `+50%` rápido.
- A recuperação de vida fica:
  - `+10%` / `+15%` / `+20%` / `+25%` / `+30%` / `+35%` / `+40%` rápida.
- Aumenta a velocidade de disparo das sentinelas em:
  - `+20%` / `+20%` / `+30%` / `+40%`.
### Épicas
- Ganha `20%` de chance de não consumir bala do pente (inclui sentinelas);
- Disparos contra a própria base não causam mais dano;
- Balas ricocheteadas causam dano aos inimigos.

# Recursos implementados
- `Vida`: o jogador, a base e os inimigos começam com `100` pontos de vida que são destruídos/mortos quando a vida chega 0;
- `Munição`: o jogador tem uma quantidade limitada de munição no pente. Quando a munição do pente acaba ele pode recarregar apertando `R` e usando a munição armazenada na base, que também é limitada. Enquanto recarregar ele não pode atirar;
- `Movimentação`: o jogador pode se movimentar definindo um destino clicando com o `botão direito do mouse`. Os inimigos por padrão seguem o jogador quando ele está fora da base, quando ele está dentro eles priorizam atacar a base;
- `Desbravador (pathfinding)`: as torres localizadas no vértices da base são consideradas obstáculos para a movimentação do jogador, assim como a base é considerada um obstáculo para os inimigos;
- `Base`: a base é uma área segura para o jogador, os muros dela refletem as balas vindas de fora, mas sem deixar de tomar dano. O jogador pode sair e entrar livremente dela e nenhum inimigo pode entrar nela. As torres da base recebem dano reduzido;
- `Disparo`: o jogador pode disparar uma bala na direção do mouse ao custo de sua munição apertando/segurando a tecla `Q` ou o `botão esquerdo do mouse`. Os inimigos também disparam, mas não possuem limite de munição;
- `Otimização`: balas fora do mapa são destruídas e as páginas de texturas só são carregadas uma única vez;
- `Sentinelas`: a base acompanha um total de 4 sentinelas que atacam os inimigos que se aproximam delas automaticamente. Elas são extremamente lentas e consomente a munição do jogador que não está no pente da arma dele, mas causam bastante dano e podem receber melhorias na loja;
- `Hordas`: o jogo é dividido 15 hordas, cada uma mais difícil que a anterior. O jogador vence o jogo se sobreviver a todas elas. Durante uma horda uma quantidade fixa de inimigos surgem nas borda do mapa aleatoriamente, quando todos são derrotados a horda termina;
- `Reparo da base`: o jogador repara a base automaticamente enquanto estiver dentro dela, mas é uma ação lenta. Se ele estiver em movimento a velocidade do reparo é diminuída;
- `Espólios`: ao derrotar um inimigo, ele tem chance de deixa cair um kits de `vida` ou `munição`. Os kits somem após um tempo;
- `Loja`: no final de cada horda o jogador pode comprar melhorias e/ou benefícios usando moedas. O jogador recebe uma quantidade de moedas quando derrota um inimigo e que pode variar um pouco;
- `Pausa`: o jogo pode ser pausado apertando `Esc`. Um menu aparecerá dando algumas opçãoes, entre elas a de fechar o jogo;
- `Resoluções`: no menu de pausa há um botão de opções que leva a um menu de configuração de resolução. Há três resolução configuradas e a opção de tela cheia.

# Recursos do C++ usados
- `vector`:
  - O `vector`, uma implementação da `TAD sequência`, é usado no [`list.hpp`](include/Engine/list.hpp) para armazenar um template de uma lista de ponteiros.
- `map`:
  - O `map`, uma implementação da `TAD dicionário`, é usado no [`shop.hpp`](include/Misc/shop.hpp) para armazenar as informações dos itens da loja através dos seus nomes.
- `stack`:
  - O `stack`, uma implementação da `TAD sequência`, é usado no [`pathfinder.hpp`](include/Misc/pathfinder.hpp) para traçar os pontos de destino.
- `cmath`:
  - As funções `sinf`, `cosf`, `atan2` e `fmod` são utilizadas no [`math.cpp`](src/Engine//math.cpp) para implementar funções como `Game::Math::pointInRadius` e `Game::Math::pointDirection`, responsáveis por relacionar ângulos e pontos.
- `iomanip`;
- `sstream`;
- `functional`:
  - Fornece recursos para passar funções como parâmetros ou atributos, útil em alguns casos. Usamos principalmente para construir os itens da loja do jogo sem precisar usar muia herança no [`items.cpp`](src/Misc/items.cpp).
- `locale` e `codecvt`:
  - Usadas para utilizarmos textos armazenados no formato de UTF-8.
- `stdexcept`:
  - Usada para adicionar erros customizados.
- `time.h`:
  - Usada para gerar uma `seed` em [`local.cpp`](src/Process/local.cpp) a ser usada no `srand`.

# Recursos de bibliotecas externas usados
- `SFML` - recursos da gráficos e sonoros do `SFML`;
- `gtest` e `gmock` - biblitecas do `googletest` usadas nos [`tests`](tests).