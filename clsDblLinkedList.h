#pragma once

#include <iostream>

using namespace std;



template <class T>

class clsDblLinkedList
{
protected:
    int _Size = 0;

public:

    class Node
    {
    public:
        T value;
        Node* Next;
        Node* Prev;
    };


    Node* head = NULL;

    void InsertAtBeginning(T value)
    {

        Node* new_node = new Node();

        new_node->value = value;

        new_node->Prev = NULL;
        new_node->Next = head;

        if (head != NULL)
        {
            head->Prev = new_node;
        }

        head = new_node;

        _Size++;
    }

    Node* Find(int Value)
    {
        Node* Current = head;

        while (Current != NULL)
        {
            if (Current->value == Value)
            {
                return Current;
            }

            Current = Current->Next;
        }

        return NULL;
    }

    void InsertAfter(Node* current, int value)
    {
        Node* new_node = new Node();

        new_node->value = value;

        new_node->Next = current->Next;
        new_node->Prev = current;

        if (current->Next != NULL) {

            current->Next->Prev = new_node;

        }

        current->Next = new_node;

        _Size++;
    }


    void InsertAtEnd(int value)
    {
        Node* new_node = new Node();

        new_node->value = value;
        new_node->Next = NULL;

        if (head == NULL)
        {
            new_node->Prev = NULL;
            head = new_node;
        }
        else
        {
            Node* current = head;

            while (current->Next != NULL) {
                current = current->Next;
            }

            new_node->Prev = current;
            current->Next = new_node;
        }

        _Size++;

    }

    void DeleteNode(Node*& NodeToDelete)
    {
        if (head == NULL || NodeToDelete == NULL)
        {
            return;
        }

        if (head == NodeToDelete)
        {
            head = NodeToDelete->Next;
        }

        if (NodeToDelete->Prev != NULL)
        {
            NodeToDelete->Prev->Next = NodeToDelete->Next;
        }

        if (NodeToDelete->Next != NULL)
        {
            NodeToDelete->Next->Prev = NodeToDelete->Prev;
        }

        delete NodeToDelete;

        _Size--;
    }

    void DeleteFirstNode()
    {
        if (head == NULL)
        {
            return;
        }

        Node* temp = head;

        head = head->Next;

        if (head != NULL)
        {
            head->Prev = NULL;
        }

        delete temp;

        _Size--;
    }

    void DeleteLastNode()
    {
        if (head == NULL)
        {
            return;
        }

        if (head->Next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;

        while (current->Next->Next != NULL)
        {
            current = current->Next;
        }

        Node* temp = current->Next;
        current->Next = NULL;
        delete temp;

        _Size--;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);
    }



    void Reverse()
    {
        Node* Current = head;

        Node* temp = nullptr;

        while (Current != nullptr)
        {
            temp = Current->Prev;
            Current->Prev = Current->Next;
            Current->Next = temp;

            Current = Current->Prev;

        }

        if (temp != nullptr)
        {
            head = temp->Prev;
        }

    }

    Node* GetNode(int Index)
    {

        int Counter = 0;

        if (Index > _Size - 1 || Index < 0)
            return NULL;

        Node* Current = head;

        while (Current != NULL)
        {
            if (Counter == Index)
            {
                break;
            }

            Counter++;
            Current = Current->Next;
        }

        return Current;
    }

    T GetItem(int Index)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return NULL;
        else
            return ItemNode->value;
    }

    bool UpdateItem(int Index, T NewValue)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            ItemNode->value = NewValue;
            return true;
        }
        else {
            return false;
        }

    }

    bool InsertAfter(int Index, int value)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, value);
            return true;
        }
        else
        {
            return false;
        }



        _Size++;
    }

    void PrintList()
    {
        Node* Current = head;


        while (Current != NULL)
        {
            cout << Current->value << "  ";
            Current = Current->Next;
        }

    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

};

