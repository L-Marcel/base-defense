#pragma once
#include <Engine/math.hpp>
#include <vector>

namespace Game {
  template <typename T> class List {
    protected:
      vector<T*> list;
    public:
      /// @brief Retorna um elemento da lista
      /// @param index o íncide do elemento
      /// @return o elemento encontrado
      inline T* get(int index) {
        return this->list[index];
      };

      /// @brief Permite acessar o tamanho da lista
      /// @return o tamanho da lista
      inline unsigned int length() {
        return this->list.size();
      };

      /// @brief Adicona um elemento na lista
      /// @param item o elemento
      inline void add(T* item) {
        this->list.push_back(item);
      };

      /// @brief Remove um elemento na lista pela sua posição
      /// @param index a posição do elemento elemento
      void remove(long unsigned int index) {
        if(index >= this->list.size()) return;
        this->list.erase(this->list.begin() + index);
      };

      /// @brief Remove um elemento na lista
      /// @param item o elemento
      void remove(T* item) {
        for(long unsigned int i = 0; i < this->list.size(); i++) {
          if(this->list[i] == item) {
            this->list.erase(this->list.begin() + i);
            break;
          };
        };
      };

      /// @brief Ordena a lista de acordo com a função de comparação dos elementos
      /// @param compare a função de comparação dos elementos
      inline void sort(bool (*compare)(T* one, T* two)) {
        std::sort(this->list.begin(), this->list.end(), compare);
      };

      inline void clear() {
        for(long unsigned int i = 0; i < this->list.size(); i++) {
          this->remove(i);
        };
      };
  };
};