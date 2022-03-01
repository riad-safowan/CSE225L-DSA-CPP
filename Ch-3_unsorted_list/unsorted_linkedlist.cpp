#include <iostream>
#include "item_type.cpp"
using namespace std;

struct NodeType {
    ItemType info;
    NodeType* next;
};

class UnsortedType {
public:
    UnsortedType();
    ~UnsortedType();

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

UnsortedType::UnsortedType() {
    length = 0;
    listData = NULL;
}

void UnsortedType::MakeEmpty() {
    NodeType* tempPtr;
    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

bool UnsortedType::IsFull()const {
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

int UnsortedType::GetLength() const {
    return length;
}

ItemType UnsortedType::GetItem(ItemType& item, bool& found) {
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
void UnsortedType::PutItem(ItemType item) {
    NodeType* location;
    location = new NodeType;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}

void UnsortedType::DeleteItem(ItemType item) {
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

void UnsortedType::ResetList() {
    currentPos = NULL;
}

ItemType UnsortedType::GetNextItem() {
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

UnsortedType::~UnsortedType() {
    NodeType* tempPtr;
    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

int main() {
     UnsortedType list;

    for (int i = 0; i < 20; i++)
    {
        list.PutItem(ItemType(i));
    }

    list.ResetList();
    for (int i = 0; i < list.GetLength(); i++)
    {
        list.GetNextItem().Print();
    }

    for (int i = 0; i < 20; i += 2)
    {
        list.DeleteItem(ItemType(i));
    }

    cout << endl;
    list.ResetList();
    for (int i = 0; i < list.GetLength(); i++)
    {
        list.GetNextItem().Print();
    }
    list.ResetList();
    return 0;
}
