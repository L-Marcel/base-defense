#include "objects.hpp"

namespace lm {
  class Room : public Instantiable {
    private:
      unsigned int width;
      unsigned int height;
    public:
      List<Object> objects;
      string title;

      /// @brief Cria uma instância de uma sala
      Room();

      /// @brief Cria uma instância de uma sala
      /// @param title o título da sala
      /// @param width a largura da sala
      /// @param height a altura da sala
      Room(string title, unsigned int width, unsigned int height);

      /// @brief Função a ser chamada a cada frame do jogo
      /// @param gp o processo do jogo
      /// @param window a janela do jogo
      /// @param frame o frame atual do jogo
      void step(GameProcess* gp, Window* window, unsigned short int frame);

      /// @brief Adiciona um objeto na sala com a posição
      /// @param object o objeto
      /// @return o id do objeto na sala
      unsigned int addObject(Object* object);

      /// @brief Remove um objeto da sala
      /// @param id o id do objeto na sala
      void destroyObject(unsigned int id);
  } typedef Room;
};