#pragma once
#include "HashTable.h"
using namespace std;
template <class TKey, class TElement >
class Dictionary
{
private:
	HashTable<TKey, TElement>* hashTable;
	int count;
	int capacity;
public:
	Dictionary(int capacity_) : count(0), capacity(capacity_)
	{ 
		this->hashTable = new HashTable<TKey, TElement>(capacity_); 
	}
	~Dictionary() 
	{
		delete this->hashTable;
	}
	int GetCount() 
	{
		return this->count;
	}
	int GetCapacity() 
	{
		return this->capacity;
	}
	TElement Get(TKey key)
	{
		return this->hashTable->Get(key);
	}
	bool ContainsKey(TKey key)
	{
		return this->hashTable->ContainsKey(key);
	}
	void Add(TKey key, TElement element) 
	{
		if ((float)count / capacity > 0.75) 
		{
			this->hashTable = new HashTable<TKey, TElement>(this->hashTable, capacity * 2);
		}
		this->hashTable->Add(key, element);
		count++;
	}
	void Remove(TKey key) 
	{
		if (this->count < (float)this->capacity / 2) 
		{
			this->hashTable = new HashTable<TKey, TElement>(this->hashTable, capacity / 2);
		}
		this->hashTable->Remove(key);
	}

};

