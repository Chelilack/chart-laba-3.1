#pragma once
#include "ArraySequence.h"
#include "Errors.h"
#include <typeinfo>

template<class T>
struct arc 
{
	int fromNode, toNode;
	T weight;
};
template<class T>
class Graph
{
private:
	int countNode, countArc;
	bool oriented;
	ArraySequence<ArraySequence<T>*>* matrixAdjacency = new ArraySequence<ArraySequence<T>*>();
public:
	int GetCountNode() { return countNode; }
	int GetCountArc() { return countArc; }
	bool GetOriented() { return oriented; }
	Graph(int countNode_,bool oriented_):countArc(0),oriented(oriented_),countNode(countNode_)
	{
		T* items=new T[countNode];
		for (int i = 0; i < countNode; i++) 
		{
			items[i] = 0;
		}
		for (int i = 0; i < countNode; i++) 
		{
			this->matrixAdjacency->Append(new ArraySequence<T>(items, countNode));
		}
	}
	Graph(ArraySequence<ArraySequence<T>*>* oldMatrixAdjacency,int countNode_, bool oriented_) :oriented(oriented_), countNode(countNode_)
	{
		T* items = new T[countNode];
		for (int i = 0; i < countNode; i++)
		{
			items[i] = 0;
		}
		for (int i = 0; i < countNode; i++)
		{
			this->matrixAdjacency->Append(new ArraySequence<T>(items, countNode));
		}
		for (int i = 0; i < countNode; i++) 
		{
			for (int j = 0; j < countNode; j++) 
			{
				this->matrixAdjacency->Get(i)->Get(j) = oldmatrixAdjacency->Get(i)->Get(j);
			}
		}
	}
public:
	void Insert(arc<T> newArc) 
	{
		if (newArc.fromNode >= countNode || newArc.toNode >= countNode || newArc.fromNode < 0 || newArc.toNode < 0) errors(IndexOutOfRange, "Graph->Insert");
		ArraySequence<T>* pass = this->matrixAdjacency->Get(newArc.fromNode);
		if (pass->Get(newArc.toNode) == 0) countArc += 1;
		pass->Remove(newArc.toNode);
		pass->InsertAt(newArc.weight,newArc.toNode);
		if (oriented != true)
		{
			pass = matrixAdjacency->Get(newArc.toNode);
			pass->Remove(newArc.fromNode);
			pass->InsertAt(newArc.weight, newArc.fromNode);
		}
	}
	void Remove(arc<T> newArc) 
	{
		if (newArc.fromNode >= countNode || newArc.toNode >= countNode || newArc.fromNode < 0 || newArc.toNode < 0) errors(IndexOutOfRange, "Graph->Insert");
		if (matrixAdjacency->Get(newArc.fromNode)->Get(newArc.toNode) != 0) countArc -= 1;
		matrixAdjacency->Get(newArc.fromNode)->Get(newArc.toNode) = 0;
		if (oriented != true) atrixAdjacency->Get(newArc.toNode)->Get(newArc.fromNode) = 0;
	}
	bool ContainsArc(int fromNode, int toNode) 
	{
		return matrixAdjacency->Get(fromNode)->Get(toNode) != 0;
	}
	T Get(int fromNode, int toNode) { return matrixAdjacency->Get(fromNode)->Get(toNode); }
};

