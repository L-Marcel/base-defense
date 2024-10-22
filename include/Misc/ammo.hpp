#pragma once
#include <Objects/object.hpp>

namespace Game {
  class Ammo {
    protected:
      Object* object = nullptr;
      unsigned int total = 12;
      unsigned int limit = 12;
    public:
      /// @brief Retorna a quantia total de munição
      /// @return a quantia
      unsigned int get();

      /// @brief Retorna o limite da quantia de munição
      /// @return o limite
      unsigned int getLimit();

      /// @brief Retorna a porcentagem de munição
      /// @return a porcentagem de `0` a `1`
      float percent();
      
      /// @brief Reduz o total de munições
      /// @param amount a quantia a ser reduzida
      void consume(unsigned int amount);

      /// @brief Aumenta o total de munições, mantendo o limite
      /// @param amount a quantia a ser incrementada
      void recharge(unsigned int amount);

      /// @brief Aumenta o limite de munição
      /// @param amount a quantia a ser incrementada
      void upgrade(unsigned int amount);

      /// @brief Cria uma instância de munição
      /// @param object o dono da munição
      /// @param limit o limite de munição
      Ammo(Object* object, unsigned int limit = 20);
      Ammo();
  };
};