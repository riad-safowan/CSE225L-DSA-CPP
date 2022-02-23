
#include<iostream>
#include "class_template.h"
using namespace std;

template<class T>
myClass<T>::myClass() {
}
template<class T>
myClass<T>::myClass(T v) {
    value = v;
}
template<class T>
myClass<T>::~myClass() {
}

template<class T>
void myClass<T>::setValue(T v) {
    value = v;
}

template<class T>
T myClass<T>::getValue() {
    return value;
}





