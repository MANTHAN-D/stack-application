#include "stackArrayTPT.h"
#include<iostream>
using namespace std;
template <class Type>
stackArrayTPT<Type>::stackArrayTPT(int max){
    size = max;
    top=0;
    list = new Type(max);
}

template <class Type>
stackArrayTPT<Type>::~stackArrayTPT(){
    delete list;
}

template <class Type>
bool stackArrayTPT<Type>::isEmptyStack(){
    if(top > 0){
        return 0;
    }
    else{
        return 1;
    }
}

template <class Type>
void stackArrayTPT<Type>::push(Type item){
    if(top < size)
        list[top++] = item;
    else
        // do soething to display error message as stack is full
        cout << "Error: Stack full" << endl;
}

template <class Type>
Type stackArrayTPT<Type>::pop(){
    if(top > 0){
        return list[--top];
    }
    else{
        cout<<"Error : Stack empty" << endl;
        return NULL;
    }
}
