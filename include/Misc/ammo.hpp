#pragma once
#include <Objects.hpp>

namespace Game {
  class Ammo {
    protected:
      Object* object = nullptr;
      float total = 12;
      float limit = 12;
    public:
      /// @brief Retorna a quantia total de munição
      /// @return a quantia
      float get();
      
      /// @brief Reduz o total de munições
      /// @param amount a quantia a ser reduzida
      void shoot(float amount);

      /// @brief Aumenta o total de munições, mantendo o limite
      /// @param amount a quantia a ser incrementada
      void recharge(float amount);

      /// @brief Cria uma instância de munição
      /// @param object o dono da munição
      /// @param limit o limite de munição
      Ammo(Object* object, float limit = 20);
      Ammo();
  };
};