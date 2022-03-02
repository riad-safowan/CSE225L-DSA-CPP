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
    item = currentPos->info;
    currentPos = currentPos->next;
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

    for (int i = 0; i < 20; i++)
    {
        list.PutItem(ItemType(i));
    }

    list.PutItem(ItemType(100));
    list.PutItem(ItemType(101));

    list.ResetList();
    for (int i = 0; i < list.GetLength(); i++)
    {
        list.GetNextItem().Print();
    }

    for (int i = 0; i < 20; i += 2)
    {
        list.DeleteItem(ItemType(i));
    }

    list.DeleteItem(ItemType(100));
    list.DeleteItem(ItemType(102));
    list.DeleteItem(ItemType(102));
    list.DeleteItem(ItemType(102));
    list.DeleteItem(ItemType(20));
    cout << endl;
    list.ResetList();
    for (int i = 0; i < list.GetLength(); i++)
    {
        list.GetNextItem().Print();
    }
    list.ResetList();

    return 0;
}
