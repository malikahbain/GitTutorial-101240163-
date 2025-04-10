#include <iostream>
using namespace std;

#include "TAArray.h"

TAArray::TAArray(){
    size = 0;
    this->elements = new TextArea*[MAX_ARR];
    for(int i = 0; i < MAX_ARR; ++i){
        this->elements[i] = nullptr;
    }
}

TAArray::~TAArray(){
    for(int i=0; i < MAX_ARR; ++i){
        if(elements[i] != nullptr){
            delete elements[i];
        }
    }
    delete [] elements;
}

bool TAArray::add(TextArea* t){
    if (size >= MAX_ARR)return false;

    this->elements[size] = t;
    ++size;
    return true;
        
}

bool TAArray::add(TextArea* t, int index){
    if (size >= MAX_ARR) return false;
    if(index < 0 || index > size) return false;

    if(elements[index] == nullptr){
        elements[index] = t;
    }else{
        for(int i = size; i > index; --i){
            elements[i] = elements[i-1];
        }
        elements[index] = t;
    }
    
    ++size;
    return true;
        
}


TextArea* TAArray::get(string id) const{
    for (int i = 0; i < size; ++i){
        if (elements[i]->getText() ==id){
            return elements[i];
        }
    }
    return NULL;
}

TextArea* TAArray::get(int index) const{
    if (index < 0 || index >= size) return NULL;
    return elements[index];

    TextArea* ta = elements[index];
    for (int i = index; i < size - 1; i++)
    {
        elements[i] = elements[i + 1];
    }
    
    elements[size -1] = nullptr;
   
    return ta;
}

TextArea* TAArray::remove(string number){
   
    int index = 0;
    //we want to find the index of the element to remove
    while (elements[index]->getText() != number && index < size){
        ++index;
    }

    if(index == size){
        return nullptr;
    }

    return remove(index); 

}

TextArea* TAArray::remove(int index){

    //did we fall off the end of the TAArray?
    if (index<0 || index >=size) return nullptr;

    //we have found what we wanted to remove,
    //assign the output value
    TextArea *stu = elements[index];

    //copy everything after index left one position
    while (index < size - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    --size;
    return stu;

}

void TAArray::changeSize(int i){
    if(i > 0){
         ++this->size;
    }else{
        --this->size;
    }
}



void TAArray::print()
{
  cout << endl << endl << "TextAreas:" << endl;
  for (int i=0; i<size; ++i)
    elements[i]->print();

  cout << endl;
}