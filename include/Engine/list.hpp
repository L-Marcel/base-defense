#include "math.hpp"
#include <type_traits>
#include <utility>

namespace lm {
  template <typename T> class List;

  class Instantiable {
    protected:
      unsigned int id = 0;
    public:
      unsigned int getId();
      template<typename T, class = enable_if<is_base_of<Instantiable, T>::value>> 
        inline void defineId(List<T>* list) {   
          if(this->id <= 0) this->id = list->getFreeId();
        };
  };

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

      /// @brief faz uma busca por uma instância de algum objeto na sala
      /// @param id instância do objeto
      /// @return o ponteiro da instância, se existir, nulo caso contrário
      template<class = enable_if<is_base_of<Instantiable, T>::value>>
        inline T* find(unsigned int id) {
          for(unsigned int i = 0; i < this->length(); i++) {
            Instantiable* instance = this->get(i);
            if(instance->getId() == id) {
              return this->get(i);
            };
          };

          return NULL;
        };

      /// @brief Retorna um id live para ser usado por uma insância
      /// @tparam condition essa função só pode ser chamada por classes que herdam
      /// a classe Instantiable
      /// @return um id livre
      template<class = enable_if<is_base_of<Instantiable, T>::value>>
        inline unsigned int getFreeId() {
          for(unsigned int i = 0; i < this->length(); i++) {
            if(this->find(i + 1) != NULL) {
              return i + 1;
            };
          };

          return this->length() + 1;
        };
      
      /// @brief Permite acessar o tamanho da lista
      /// @return o tamanho da lista
      inline unsigned int length() {
        return this->amount;
      };

      /// @brief Adicona um elemento na lista
      /// @param item o elemento
      inline void push(T* item) {
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