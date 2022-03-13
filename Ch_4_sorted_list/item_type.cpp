#ifndef MY_LIST1
#define MY_LIST1
#include <iostream>
using namespace std;

enum RelationType { LESS, EQUAL, GREATER };
class ItemType
{
public:
    ItemType() {};
    ItemType(int);
    RelationType ComparedTo(ItemType) const;
    void Print() const;
    void Println() const;
    void Initialize(int number);
    int GetValue();
private:
    int value;

};
#endif


ItemType::ItemType(int v) {
    value = v;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
    if (value < otherItem.value)
        return LESS;
    else if (value > otherItem.value)
        return GREATER;
    else return EQUAL;
}
void ItemType::Print() const
{
    cout << value << " ";
}
void ItemType::Println() const
{
    cout << value << endl;
}
void ItemType::Initialize(int number)
{
    value = number;
}

int ItemType::GetValue() {
    return value;
}