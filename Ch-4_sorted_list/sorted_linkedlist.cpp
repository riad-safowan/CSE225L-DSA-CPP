#include <iostream>
#include "item_type.cpp"
using namespace std;

struct NodeType {
    ItemType info;
    NodeType* next;
};

class SortedType {
public:
    SortedType();
    ~SortedType();

    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType& item, bool& found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();

private:
    NodeType* listData;
    int length;
    NodeType* currentPos;
};

SortedType::SortedType() {
    length = 0;
    listData = NULL;
}

void SortedType::MakeEmpty() {
    NodeType* tempPtr;
    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

bool SortedType::IsFull()const {
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (const std::exception& e)
    {
        return true;
    }
}

int SortedType::GetLength() const {
    return length;
}

ItemType SortedType::GetItem(ItemType& item, bool& found) {
    bool moreToSearch;
    NodeType* location;
    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found) {
        switch (item.ComparedTo(location->info))
        {
        case LESS:
        case GREATER:
            location = location->next;
            moreToSearch = (location != NULL);
            break;
        case EQUAL:
            found = true;
            item = location->info;
            break;
        }
    }
    return item;
}
// void SortedType::PutItem(ItemType item) {
//     NodeType* location;
//     location = new NodeType;
//     location->info = item;
//     location->next = listData;
//     listData = location;
//     length++;
// }
void SortedType::PutItem(ItemType item) {
    NodeType* location;
    location = listData;
    NodeType* newP = new NodeType;
    newP->info = item;
    while (location->next != NULL && item.ComparedTo(location->next->info) == GREATER)
    {
        location = location->next;
    }
    newP->next = location->next;
    location->next = newP;
    length++;

    cout << "#list: ";
    for (int i = 0; i < length; i++)
    {
        GetNextItem().Print();
    }
    cout << endl;
    cout << endl;
    ResetList();
}

void SortedType::DeleteItem(ItemType item) {
    NodeType* location = listData;
    NodeType* previous;
    if (item.ComparedTo(location->info) == EQUAL)
    {
        listData = location->next;
        delete location;
        length--;
    }
    else {
        while (item.ComparedTo(location->info) != EQUAL)
        {
            previous = location;
            location = location->next;
        }

        previous->next = location->next;
        delete location;
        length--;
    }
}

void SortedType::ResetList() {
    currentPos = NULL;
}

ItemType SortedType::GetNextItem() {
    ItemType item;
    if (currentPos == NULL) {
        currentPos = listData;
    }
    else {
        currentPos = currentPos->next;
    }
    item = currentPos->info;
    return item;
}

SortedType::~SortedType() {
    NodeType* tempPtr;
    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

int main() {
    SortedType list;

    ItemType i1(5);
    list.PutItem(i1);
    list.PutItem(ItemType(10));
    list.PutItem(ItemType(15));
    list.PutItem(ItemType(20));
    list.PutItem(ItemType(25));

    for (int i = 0; i < 5; i++)
    {
        list.GetNextItem().Print();
    }
    list.ResetList();

    list.DeleteItem(ItemType(10));
    list.DeleteItem(ItemType(25));
    // list.PutItem(ItemType(55));
    // list.PutItem(ItemType(77));

    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        list.GetNextItem().Print();
    }
    list.ResetList();

    return 0;
}
