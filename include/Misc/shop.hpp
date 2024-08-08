#pragma once
#include <Misc/item.hpp>

namespace Game {
  class Shop {
    protected:
      static map<string, Item> items;
      static map<string, unsigned short int> common_stock;
      static map<string, unsigned short int> rare_stock;
      static map<string, unsigned short int> epic_stock;
    public:
      static string showcase[3];

      /// @brief Compra um item, se puder
      /// @param item o item
      /// @return `true` se conseguiu comprar, `false` caso contrário ou
      static bool purchase(Item* item);
      
      /// @brief Reseta a vitrine da loja
      static void reset();

      /// @brief Retorna o nome das ofertas (items) disponíveis
      /// @param rarity a raridade delas
      /// @return os nomes
      static vector<string> get_available_offers(unsigned short int rarity);

      /// @brief Obtem uma oferta aleatória de um item, com base em sua raridade
      /// @param rarity a raridade
      /// @return o ponteiro de um item
      static Item* get_offer(unsigned short int rarity);
  };
};