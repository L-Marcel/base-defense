#pragma once
#include <Objects/object.hpp>

namespace Game {
  class Collision;
  class Object2D : public Object {
    public:
      virtual string type();
      virtual void step();
      virtual void collision();
      virtual void draw();
      virtual void free();
      virtual ~Object2D();

      /// @brief Cria uma instância do objeto 2D
      /// @param sprite_sheet página de textura do sprite do objeto 2D
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      static Object2D* create(string sprite_sheet, Box box);

      /// Sprite ==================================
      Sprite* sprite = nullptr;
      unsigned short int frames = 1;
      float fps = 0;
      float image = 0;
      double rotation = 0; 
      bool loop = true;
      bool animation_finished = false;
      /// =========================================

      /// Collision ===============================
      List<Collision> collisions;
      List<Object2D> colliders;

      bool has_rectangle = false;
      Rectangle rectangle = Rectangle();
      float rectangle_height = 0;
      float rectangle_width = 0;

      bool has_circle = false;
      Circle circle = Circle();
      float circle_radius = 0;
      /// =========================================
      
      /// Movement ================================
      Point position;
      double direction = 0;
      mutable float speed = 0;
      /// =========================================
     
      /// @brief Inicia uma das animações disponíveis para o objeto 2D
      /// @param fps o número de frames por segundo
      /// @param texture_row a linha da animação na textura (do sprite)
      /// @param loop se é animação deve ficar se repetindo
      /// @param image o íncide do frame da animação
      void animate(
        float fps,
        unsigned short int frames,
        unsigned short int texture_row, 
        bool loop = true, 
        float image = 0
      );
     
      /// @brief Muda a escala do objeto 2D
      /// @param scale a nova escala
      void scale(float scale);

      /// @brief Muda a escala do objeto 2D
      /// @param x_scale a escala x
      /// @param y_scale a escala y
      void scale(float x_scale, float y_scale);

      /// @brief Cria uma colisão retangular
      /// @param width a largura do retângulo
      /// @param height a altura do retângulo
      void setRectangle(float width, float height);

      /// @brief Cria uma colisão circular
      /// @param radius Raio do círculo
      void setCircle(float radius);
    protected:
      /// @brief Cria uma instância do objeto 2D
      /// @param sprite_sheet página de textura do sprite do objeto 2D
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      Object2D(string sprite_sheet, Box box);
      Object2D();
  };
};