# Sumário
- [Instruções para compilar e executar](#instruções-para-compilar-e-executar);
- [Lista de comandos](#comandos-gerais);
- [Sobre o jogo](#sobre-o-jogo);
- [Recursos implementados](#recursos-implementados);
- [Recursos do c++ usados](#recursos-do-c-usados);
- [Recursos de bibliotecas externas usados](#recursos-de-bibliotecas-externas-usados).

# Instruções para compilar e executar
- Instale o `Make`, no caso do `Windows`, use esse [aqui](_windows/winlibs-x86_64-posix-seh-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5.7z) (que é o compatível);
- Instale o `OpenAl`, disponível [aqui](https://www.openal.org/downloads/):
    - No `Linux` talvez não precise, mas, por garantia, basta instalar o pacote `libopenal-dev`;
    - No `Ubuntu`, por exemplo, basta executar o comando abaixo para instalar o pacote:
        ```
        sudo apt install libopenal-dev
        ```
- Dentro da raíz do projeto, execute `make dev` e vai compilar e executar o jogo.

# Lista de comandos
- `make` - vai compilar tanto o jogo como os testes;
- `make test` - vai compilar e executar os testes;
- `make dev` - vai compilar e executar o jogo;
- `make run` - vai executar o jogo (se compilado);
- `make compile` - vai compilar o jogo;
- `make clean` - vai limpar o `_build`.

# Sobre o jogo
...

# Recursos implementados
...

# Recursos do C++ usados
- `vector`:
    - O `vector`, uma implementação da `TAD sequência` é usada no [`list.hpp`](include/Engine/list.hpp) para armazenar um template de uma lista de ponteiros.
- `cmath`:
    - As funções `sinf`, `cosf`, `atan2` e `fmod` são utilizadas no [`math.cpp`](src/Engine//math.cpp) para implementar as funções `Game::Math::pointInRadius` e `Game::Math::pointDirection`, responsáveis por relacionar ângulos e pontos.

# Recursos de bibliotecas externas usados
- `SFML/Graphics` - recursos da gráficos do `SFML`;
- `SFML/Audio.hpp` - recursos da sonoros do `SFML`;
- `gtest` e `gmock` - biblitecas do `googletest` usadas nos [`tests`](tests).