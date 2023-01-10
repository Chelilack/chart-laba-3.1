#pragma once
#include <cassert>
#include <iostream>
#include"ArraySequence.h"
#include"LinkedListSequence.h"
#include "Sequence.h"
#include <cassert>
using namespace std;
class SortsTests
{
public:
	void Test_Sorted() 
	{
		int* sorted = new int[] { 0, 2, 4, 7, 9, 13, 14, 14, 17, 19 };
		int* result = new int[] { 0, 2, 4, 7, 9, 13, 14, 14, 17, 19 };
		ArraySequence<int>* shakerExample = new ArraySequence<int>(sorted,10);
		shakerExample=(ArraySequence<int>*)shakerExample->ShakerSort();
		for (int i = 0; i < shakerExample->GetLength(); i++)
		{
			assert(shakerExample->Get(i)==result[i]);
		}
		ArraySequence<int>* shellExample = new ArraySequence<int>(sorted, 10);
		shellExample = (ArraySequence<int>*)shellExample->ShellSort();
		for (int i = 0; i < shellExample->GetLength(); i++)
		{
			assert(shellExample->Get(i) == result[i]);
		}
		ArraySequence<int>* quickExample = new ArraySequence<int>(sorted, 10);
		quickExample = (ArraySequence<int>*)quickExample->QuickSort();
		for (int i = 0; i < quickExample->GetLength(); i++)
		{
			assert(quickExample->Get(i) == result[i]);
		}
		ArraySequence<int>* mergeExample = new ArraySequence<int>(sorted, 10);
		mergeExample = (ArraySequence<int>*)mergeExample->MergeSort();
		for (int i = 0; i < mergeExample->GetLength(); i++)
		{
			assert(mergeExample->Get(i) == result[i]);
		}
	}
	void Test_Random()
	{
		int* random = new int[] { 4, 19, 8, 15, 18, 12, 3, 4, 2, 12 };
		int* result = new int[] { 2, 3, 4, 4, 8, 12, 12, 15, 18, 19 };
		ArraySequence<int>* shakerExample = new ArraySequence<int>(random, 10);
		shakerExample = (ArraySequence<int>*)shakerExample->ShakerSort();
		for (int i = 0; i < shakerExample->GetLength(); i++)
		{
			assert(shakerExample->Get(i) == result[i]);
		}
		ArraySequence<int>* shellExample = new ArraySequence<int>(random, 10);
		shellExample = (ArraySequence<int>*)shellExample->ShellSort();
		for (int i = 0; i < shellExample->GetLength(); i++)
		{
			assert(shellExample->Get(i) == result[i]);
		}
		ArraySequence<int>* quickExample = new ArraySequence<int>(random, 10);
		quickExample = (ArraySequence<int>*)quickExample->QuickSort();
		for (int i = 0; i < quickExample->GetLength(); i++)
		{
			assert(quickExample->Get(i) == result[i]);
		}
		ArraySequence<int>* mergeExample = new ArraySequence<int>(random, 10);
		mergeExample = (ArraySequence<int>*)mergeExample->MergeSort();
		for (int i = 0; i < mergeExample->GetLength(); i++)
		{
			assert(mergeExample->Get(i) == result[i]);
		}
	}
	void Test_ReverseSorted() 
	{
		int* reversed = new int[] { 19, 18, 15, 12, 12, 8, 4, 4, 3, 2 };
		int* result = new int[] { 2, 3, 4, 4, 8, 12, 12, 15, 18, 19 };
		ArraySequence<int>* shakerExample = new ArraySequence<int>(reversed, 10);
		shakerExample = (ArraySequence<int>*)shakerExample->ShakerSort();
		for (int i = 0; i < shakerExample->GetLength(); i++)
		{
			assert(shakerExample->Get(i) == result[i]);
		}
		ArraySequence<int>* shellExample = new ArraySequence<int>(reversed, 10);
		shellExample = (ArraySequence<int>*)shellExample->ShellSort();
		for (int i = 0; i < shellExample->GetLength(); i++)
		{
			assert(shellExample->Get(i) == result[i]);
		}
		ArraySequence<int>* quickExample = new ArraySequence<int>(reversed, 10);
		quickExample = (ArraySequence<int>*)quickExample->QuickSort();
		for (int i = 0; i < quickExample->GetLength(); i++)
		{
			assert(quickExample->Get(i) == result[i]);
		}
		ArraySequence<int>* mergeExample = new ArraySequence<int>(reversed, 10);
		mergeExample = (ArraySequence<int>*)mergeExample->MergeSort();
		for (int i = 0; i < mergeExample->GetLength(); i++)
		{
			assert(mergeExample->Get(i) == result[i]);
		}
	}
	void Test() 
	{
		Test_Sorted();
		Test_Random();
		Test_ReverseSorted();
		cout << "Sorts work correctly" << endl;
	}
};


 