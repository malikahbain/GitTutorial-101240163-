#ifndef TAARRAY_H
#define TAARRAY_H

#define MAX_ARR 64

#include "TextArea.h"

class TAArray
{
  public:
    TAArray();
    ~TAArray();

    bool add(TextArea*);
    bool add(TextArea* t, int index);
    
    TextArea* get(string name) const;
    TextArea* get(int index) const;

    TextArea* remove(string name);
    TextArea* remove(int index);


    bool isFull(){return size == MAX_ARR;}
    int getSize() const{return size;}
    int getSizeNoConst() {return size;}
    void changeSize(int i);
    void print();
    

  private:
    TextArea** elements;
    int size;
   
};

#endif

