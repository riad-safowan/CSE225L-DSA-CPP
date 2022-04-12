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
    ItemType GetItem(ItemType item, bool& found);
    void PutItem(ItemType item);
    void Insert(ItemType item);
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

ItemType SortedType::GetItem(ItemType item, bool& found) {
    bool moreToSearch;
    NodeType* location;
    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found) {
        switch (item.ComparedTo(location->info))
        {
        case LESS: moreToSearch = false;
            break;
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
    NodeType* location = listData;
    NodeType* previous = NULL;
    NodeType* newNode = new NodeType;
    newNode->info = item;

    bool moreToSearch = (location != NULL);

// 0 1 3 5 7 10
// 7 10
    while (moreToSearch) {
        switch (item.ComparedTo(location->info))
        {
        case GREATER:
            previous = location;
            location = location->next;
            moreToSearch = (location != NULL);
            break;

        case LESS:moreToSearch = false;
            break;
        }
    }

    if (previous == NULL)
    {
        newNode->next = listData;
        listData = newNode;
    }
    else {
        newNode->next = location;
        previous->next = newNode;
    }
    length++;
}

// void SortedType::Insert(ItemType item) {

//     NodeType* temp = new NodeType();
//     temp->info = item;
//     temp->next = NULL;

//     NodeType* index = listData;

//     while ((index->next)->info.ComparedTo(temp->info) == LESS)
//     {
//         index = index->next;
//     }
//     temp->next = index->next;
//     index->next = temp;
// }

void SortedType::DeleteItem(ItemType item) {
    NodeType* location = listData;
    NodeType* previous;

    if (item.ComparedTo(listData->info) == EQUAL)
    {
        listData = location->next;
        delete location;
        length--;
    }
    else {
        while (location->next != NULL)
        {
            if (item.ComparedTo(location->info) == EQUAL)
            {
                previous->next = location->next;
                delete location;
                length--;
                return;
            }
            previous = location;
            location = location->next;
        }
        if (item.ComparedTo(location->info) == EQUAL)
        {
            previous->next = NULL;
            delete location;
        }
    }
}

void SortedType::ResetList() {
    currentPos = NULL;
}

ItemType SortedType::GetNextItem() {
    ItemType item;
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
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

void printList(SortedType list) {
    for (int i = 0; i < list.GetLength(); i++)
    {
        list.GetNextItem().Print();
    }
    cout << endl;
    list.ResetList();
}


int main() {
    SortedType list;

    list.PutItem(ItemType(5));
    list.PutItem(ItemType(15));
    list.PutItem(ItemType(10));
    cout << list.GetLength() << endl;
    printList(list);
    list.DeleteItem(ItemType(10));
    cout << list.GetLength() << endl;

    printList(list);
    return 0;
}
