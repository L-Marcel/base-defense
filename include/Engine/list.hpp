#pragma once
#include <Engine/math.hpp>
#include <type_traits>
#include <utility>

namespace Game {
  template <typename T> class List {
    protected:
      unsigned int amount = 0;
      T** list = new T*[0];
    public:
      /// @brief Retorna um elemento da lista
      /// @param index o íncide do elemento
      /// @return o elemento encontrado
      inline T* get(unsigned int index) {
        return this->list[index % this->amount];
      };

      /// @brief Permite acessar o tamanho da lista
      /// @return o tamanho da lista
      inline unsigned int length() {
        return this->amount;
      };

      /// @brief Adicona um elemento na lista
      /// @param item o elemento
      inline void add(T* item) {
        this->amount++;

        T** items;
        items = new T*[this->amount];

        for(unsigned int i = 0; i < this->amount - 1; i++)
          items[i] = this->get(i);
      
        items[this->amount-1] = item;

        delete[] this->list;
        this->list = items;
      };

      /// @brief Ordena a lista de acordo com a função de comparação dos elementos
      /// @param compare a função de comparação dos elementos
      inline void sort(bool (*compare)(T* one, T* two)) {
        std::sort(this->list, this->list + this->amount, compare);
      };
  };
};