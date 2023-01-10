#pragma once
#include"ArraySequence.h"
#include <iostream>
using namespace std;
template <class TKey, class TElement>
 class HashTable
{
public:
    struct Node
    {
        TElement value;
        TKey key;
        Node* next;
        Node(TKey key_,TElement element) : value(element), next(NULL),key(key_) {}
    };
private:
	ArraySequence<Node*>* items;
    int count;
    int size;
public:
    HashTable(int size) :count(0), size(size)
    { 
        this->items = new ArraySequence<Node*>(this->size);
        for (int i = 0; i < this->size; i++) 
        {
            this->items->InsertAt(NULL, i);
        }
    }
    HashTable(HashTable<TKey,TElement>* oldTable,int Newsize) :count(0), size(Newsize)
    {
        this->items = new ArraySequence<Node*>(this->size);
        for (int i = 0; i < this->size; i++)
        {
            this->items->InsertAt(NULL, i);
        }
        for (int i = 0; i < oldTable->GetSize(); i++) 
        {
            if (oldTable->GetCash()->Get(i) != NULL) 
            {
                this->Add(oldTable->GetCash()->Get(i)->key,oldTable->GetCash()->Get(i)->value);
                Node* temporary = oldTable->GetCash()->Get(i);
                while (temporary->next != NULL)
                {
                    temporary = temporary->next;
                    this->Add(temporary->key, temporary->value);
                }
            }
        }
    }
    ~HashTable()
    {
        delete this->items;
    }
    int GetCount() { return this->count; }
    int GetSize() {return this->size;}
    ArraySequence<Node*>* GetCash() { return this->items; }
    
    int HashFunction(string key)
    {
        int sum = 0;
        for (int k = 0; k <= key.length(); k++)
            sum += (int)key[k];

        return sum % (this->size);
    }
    int HashFunction(int key) 
    {
        return abs(key%this->size);
    }
    void Add(TKey key, TElement element) 
    {
        int index = HashFunction(key);
        Node* elementNode= new Node(key, element);;
        this->count += 1;
        if (this->items->Get(index) == NULL)
        {
            this->items->InsertAt(elementNode, index);
        }
        else if (this->items->Get(index)->key == key) 
        {
            this->items->InsertAt(elementNode, index);
        }
        else 
        {
            Node* temporary = this->items->Get(index);
            while (temporary->next!=NULL) 
            {
                temporary = temporary->next;
            }
            temporary->next = elementNode;
        }
    }
    bool ContainsKey(TKey key)
    {
        int index = HashFunction(key);
        if (this->items->Get(index) == NULL) { return false; }
        Node* element = this->items->Get(index);
        while (element->key != key && element->next != NULL)
        {
            element = element->next;
        }
        if (element->key != key) { return false; }
        else
        {
            return true;
        }
    }
    TElement Get(TKey key) 
    {
        int index = HashFunction(key);
        if (index > this->size)
        {
            errors(IndexOutOfRange, "HashTable->Get()");
        }
        if(!ContainsKey(key)) { errors(ItemDoesNotExist, "HashTable->Get()"); }
        Node* element = this->items->Get(index);
        while(element->key!=key && element->next!=NULL)
        {
            element = element->next;
        } 
        return element->value;

    }
    void Remove(TKey key) 
    {
        int index = HashFunction(key);
        if (index > this->size)
        {
            errors(IndexOutOfRange, "HashTable->Get()");
        }
        if (!ContainsKey(key)) { errors(ItemDoesNotExist, "HashTable->Get()"); }
        if (this->items->Get(index)->key == key)
        {
            if (this->items->Get(index)->next == NULL) 
            {
                this->items->Remove(index);
                return;
            }
            else 
            {
                Node* passElement = this->items->Get(index)->next;
                this->items->Remove(index);
                this->items->InsertAt(passElement, index);
                return;
            }
        }
        Node* element = this->items->Get(index);
        while (element->next->key != key)
        {
            element = element->next;
        }
        Node* forDelete=element->next;
        element->next = element->next->next;
        delete forDelete;
    }
    

};

