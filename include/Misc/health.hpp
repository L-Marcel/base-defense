#pragma once
#include <Objects.hpp>

namespace Game {
  class Health {
    protected:
      Object* object = nullptr;
      float total = 100;
      float limit = 100;
    public:
      /// @brief Retorna a quantia total de vida
      /// @return a quantia
      float get();

      /// @brief Retorna a porcentagem de vida total
      /// @return a porcentagem de `0` a `1`
      float percent();
      
      /// @brief Reduz o total de vida
      /// @param amount a quantia a ser reduzida
      void damage(float amount);

      /// @brief Aumenta o total de vida, mantendo o limite
      /// @param amount a quantia a ser incrementada
      void heal(float amount);

      /// @brief Atualiza o limite de vida
      /// @param amount a quantia a ser incrementada
      void upgrade(float amount);

      /// @brief Cria uma instância de vida
      /// @param object o dono da vida
      /// @param limit o limite de vida
      Health(Object* object, float limit = 100);
      Health();
  };
};