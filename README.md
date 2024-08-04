# Sumário
- [Instruções para compilar e executar](#instruções-para-compilar-e-executar);
- [Lista de comandos](#comandos-gerais);
- [Sobre o jogo](#sobre-o-jogo);
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

[//]: <Comandos de build das libs>
[//]: <cmake -G "MinGW Makefiles" .. -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -D"CMAKE_MAKE_PROGRAM:PATH=C:/MinGW/bin/make.exe" -DCMAKE_C_COMPILER_WORKS=1 -DCMAKE_CXX_COMPILER_WORKS=1 -DGTEST_CREATE_SHARED_LIBRARY=1 -DGTEST_LINKED_AS_SHARED_LIBRARY=1">