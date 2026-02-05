#pragma once

#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template<class T>
class clsMyQueue
{

protected:
    clsDblLinkedList<T> _MyList;

public:
    
    void Push(T Item) 
    {
         _MyList.InsertAtEnd(Item);
    }

    void Print() 
    {
        _MyList.PrintList();
    }

    int Size() 
    {
        return _MyList.Size();
    }

    bool IsEmpty() 
    {
        return _MyList.IsEmpty();
    }

    T front() 
    {
       return _MyList.GetItem(0);
    }

    T back()
    {
        return _MyList.GetItem(Size() - 1) ;
    }

    void pop()
    {

        _MyList.DeleteFirstNode();

    }

    T GetItem(T Item) 
    {
       return  _MyList.GetItem(Item);
    }

    void Reverse() 
    {
        _MyList.Reverse();
    }

    void UpdateItem(int index , T NewValue) 
    {
        _MyList.UpdateItem(index , NewValue);
    }

    void InsertAfter(int index, T NewValue)
    {
        _MyList.InsertAfter(index, NewValue);
    }

    void InsertAtFront(T value) 
    {
         _MyList.InsertAtBeginning(value);
    }

    void InsertAtBack(T value)
    {
        _MyList.InsertAtEnd(value);
    }

    void Clear() 
    {
        _MyList.Clear();
    }
};

