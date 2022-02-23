#include<iostream>
#include"class_template.cpp"

using namespace std;


int main() {
    myClass<int> intObj(10);
    intObj.setValue(10);
    cout << intObj.getValue();
}