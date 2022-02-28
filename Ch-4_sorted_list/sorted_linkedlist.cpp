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

void UnsortedType::MakeEmpty() {
    NodeType* tempPtr;
    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

void UnsortedType::PutItem(ItemType item) {
    NodeType* location;
    location = new NodeType;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
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

void UnsortedType::DeleteItem(ItemType item) {
    NodeType* location = listData;
    NodeType* tempLocation;
    if (item.ComparedTo(listData->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else {
        while (item.ComparedTo((location->next)->info) != EQUAL)
        {
            location = location->next;
            tempLocation = location->next;
            location->next - (location->next)->next;
        }
        delete tempLocation;
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
    list.PutItem(ItemType(8888));

    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        list.GetNextItem().Print();
    }
    list.ResetList();

    return 0;
}
