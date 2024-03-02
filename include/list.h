#include "math.h"
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

      template<class = enable_if<is_base_of<Instantiable, T>::value>>
        inline unsigned int getFreeId() {
          for(unsigned int i = 0; i < this->length(); i++) {
            if(this->find(i + 1) != NULL) {
              return i + 1;
            };
          };

          return this->length() + 1;
        };
      
      inline unsigned int length() {
        return this->amount;
      };

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

  };
};