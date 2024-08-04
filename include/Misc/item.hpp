#pragma once
#include <Engine/defs.hpp>

namespace Game {
  class Item {
    public:
      string name;
      function<float()> upgrade;
      function<string(Item*)> description;
      function<void(Item*)> action;
      function<unsigned int()> price;
      unsigned short int rarity;
      
      /// @brief Instancia um item
      /// @param name o nome do item, precisa ser único
      /// @param upgrade a função que retorna a quantia que representa a melhoria do item
      /// @param description a função que retorna a descrição do item
      /// @param action a função que aplica o efeito do item
      /// @param price a função que retorna o preço do item
      /// @param rarity a raridade do item
      Item(
        string name,
        function<float()> upgrade,
        function<string(Item*)> description,
        function<void(Item*)> action,
        function<unsigned int()> price,
        unsigned short int rarity
      );
  };
};