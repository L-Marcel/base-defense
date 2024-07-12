# Instruções para compilar e executar
- Instale o "Make", no caso do windows, use esse [aqui](https://gnuwin32.sourceforge.net/packages/make.htm) (que é o compatível);
- Dentro da raíz do projeto, execute "make dev" e vai compilar e executar o jogo.

# Comandos gerais
- `make` - vai compilar tanto o jogo como os testes;
- `make test` - vai compilar e executar os testes;
- `make dev` - vai compilar e executar o jogo;
- `make run` - vai executar o jogo (se compilado);
- `make compile` - vai compilar o jogo;
- `make valgrind` - vai executar o jogo usando o `valgrind` (requer o valgrind instalado na maquina);
- `make clean` - vai limpar o `_build`.

# Testes
Os testes estão contidos na pasta `tests` e são realizados usando o `googletest`. O ideal é: para cada classe, um arquivo; e para cada arquivo, um arquivo de teste.