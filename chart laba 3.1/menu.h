#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include "ArraySequenceTests.h"
#include "DynamicArrayTests.h"
#include "LinkedListTests.h"
#include "LinkedListSequenceTests.h"
#include "SortsTests.h"
#include"ArraySequence.h"
#include"LinkedListSequence.h"
#include "Sequence.h"
#include "ComplexNumber.h"
#include "Student.h"
#include "Teacher.h"
#include "Errors.h"
#include "Input.h"
#include "Comparators.h"
#include "MyForm.h"
#include "Gistogramma.h"
#include "HashTable.h"
#include "IDictionary.h"
#include "graph.h"
#include <string>



using namespace System;
using namespace System::Windows::Forms;
using namespace chartlaba31;


[STAThread]
void chart(int begin,int end, int step,float* items1, float* items2, float* items3, float* items4)
{
	int i = 0;
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm(begin, end, step, items1, items2, items3, items4));
	
	
}
[STAThread]
void OpenGistogramma()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Gistogramma());
	
	
}

using namespace std;
using namespace std::chrono;
extern int ID=1;
enum SequenseType 
{
	SEQUENCE_INT,
	SEQUENCE_FLOAT,
	SEQUENCE_CHAR_PTR,
	SEQUENCE_COMPLEX_NUMBER,
	SEQUENCE_STUDENT,
	SEQUENCE_TEACHER,
};

Sequence<Sequence<int>*>* sequenceInt = new ArraySequence<Sequence<int>*>();
Sequence<Sequence<float>*>* sequenceFloat = new ArraySequence<Sequence<float>*>();
Sequence<Sequence<char*>*>* sequenceCharPtr = new ArraySequence<Sequence<char*>*>();
Sequence<Sequence<ComplexNumber>*>* sequenceComplexNumber = new ArraySequence<Sequence<ComplexNumber>*>();
Sequence<Sequence<Student>*>* sequenceStudent = new ArraySequence<Sequence<Student>*>();
Sequence<Sequence<Teacher>*>* sequenceTeacher = new ArraySequence<Sequence<Teacher>*>();
Sequence<Sequence<string>*>* sequenceNames = new ArraySequence<Sequence<string>*>();

void menu()
{
	int page = -1;
	for (int i=0; i < 6; i++)
	{
		sequenceNames->Append(new LinkedListSequence<string>());
	}
	
	auto menuExistSequence = [&]()
	{
		if (sequenceCharPtr == 0 && sequenceComplexNumber == 0 && sequenceFloat == 0 && sequenceInt == 0 && sequenceStudent == 0 && sequenceTeacher == 0)
		{
			cout << "all queue empty!" << endl;
			system("pause");
			page = -1;
			menu();
		}
		int j = 0;
		int i = 1;
		int choice;
		int* data = new int[6];
		cout <<                                                        "-----------------------------" << endl;
		if (sequenceInt->GetLength() != 0) {	       cout << '|' << i << ". Sequence<int>           |" << endl; i++; data[j++] = 1; }
		if (sequenceFloat->GetLength() != 0) {         cout << '|' << i << ". Sequence<float>         |" << endl; i++; data[j++] = 2; }
		if (sequenceComplexNumber->GetLength() != 0) { cout << '|' << i << ". Sequence<ComplexNumber> |" << endl; i++; data[j++] = 3; }
		if (sequenceCharPtr->GetLength() != 0) {       cout << '|' << i << ". Sequence<char*>         |" << endl; i++; data[j++] = 4; }
		if (sequenceStudent->GetLength() != 0) {       cout << '|' << i << ". Sequence<Student>       |" << endl; i++; data[j++] = 5; }
		if (sequenceTeacher->GetLength() != 0) {       cout << '|' << i << ". Sequence<Teacher>       |" << endl; i++; data[j++] = 6; }
		cout <<                                                        "-----------------------------" << endl;
		cin >> choice;

		for (int n = 0; n < sequenceNames->Get(data[choice - 1]-1)->GetLength(); n++) 
		{
			cout << n+1 <<')' << sequenceNames->Get(data[choice - 1] - 1)->Get(n) << endl;
		}
		int secondChoice;
		cin >> secondChoice;
		int * result = new int[]{ data[choice-1]-1, secondChoice-1 }; //{тип данных,номер последовательности этого типа данных}
		return result;
	};

	while (page != 0)
	{
		system("cls");
		if (page == -1)
		{
			cout << "----------------------------------" << endl;
			cout << "|1.Create Sequence               |" << endl;
			cout << "|2.Do smth with sequence         |" << endl;
			cout << "|3.Run Tests                     |" << endl;
			cout << "|4.Chart                         |" << endl;
			cout << "|5.Gistogramm                    |" << endl;
			cout << "|6.Graph                         |" << endl;
			cout << "|0.Exit                          |" << endl;
			cout << "----------------------------------" << endl;
			cin >> page;
			while (page != 1 && page != 2 && page != 3 && page != 4 && page != 5&& page != 6 && page != 0)
			{
				cout << "try again!" << endl;
				cin >> page;
			}
		}
		else if (page == 1)
		{
			system("cls");
			cout << "----------------------" << endl;
			cout << "|1. Integers         |" << endl;
			cout << "|2. Floats           |" << endl;
			cout << "|3. Complex numbers  |" << endl;
			cout << "|4. Strings          |" << endl;
			cout << "|5. Students         |" << endl;
			cout << "|6. Teachers         |" << endl;
			cout << "|0. Exit             |" << endl;
			cout << "----------------------" << endl;
			int miniPage;
			int decision;
			cin >> miniPage;
			while (miniPage != 1 && miniPage != 2 && miniPage != 3 && miniPage != 4 && miniPage != 5 && miniPage != 6 && miniPage != 0)
			{
				cout << "try again!" << endl;
				cin >> miniPage;
			}
			cout << "Enter name of sequence:" << endl;
			string name;
			cin >> name;
			sequenceNames->Get(miniPage- 1)->Append(name);
			if (miniPage != 0)
			{
				system("cls");
				cout << "----------------------" << endl;
				cout << "|1.ArraySequence     |" << endl;
				cout << "|2.LinkedListSequence|" << endl;
				cout << "----------------------" << endl;
				cin >> decision;
			}

			if (miniPage == 1)
			{
				auto inputedArray = InputIntArray();
				if (decision == 1)
				{
					sequenceInt->Append(new ArraySequence<int>(inputedArray.items, inputedArray.count));
				}
				else if (decision == 2)
				{
					sequenceInt->Append(new LinkedListSequence<int>(inputedArray.items, inputedArray.count));
				}
			}
			else if (miniPage == 2)
			{
				auto inputedArray = InputFloatArray();
				if (decision == 1)
				{
					sequenceFloat->Append(new ArraySequence<float>(inputedArray.items, inputedArray.count));
				}
				else if (decision == 2)
				{
					sequenceFloat->Append(new LinkedListSequence<float>(inputedArray.items, inputedArray.count));
				}
			}
			else if (miniPage == 3)
			{
				auto inputedArray = InputComplexNumberArray();
				if (decision == 1)
				{
					sequenceComplexNumber->Append(new ArraySequence<ComplexNumber>(inputedArray.items, inputedArray.count));
				}
				else if (decision == 2)
				{
					sequenceComplexNumber->Append(new LinkedListSequence<ComplexNumber>(inputedArray.items, inputedArray.count));
				}
			}
			else if (miniPage == 4)
			{
				auto inputedArray = InputCharPtrArray();
				if (decision == 1) 
				{
					sequenceCharPtr->Append(new ArraySequence<char*>(inputedArray.items, inputedArray.count));
				}
				else if (decision == 2)
				{
					sequenceCharPtr->Append(new LinkedListSequence<char*>(inputedArray.items, inputedArray.count));
				}
			}
			else if (miniPage == 5)
			{
				auto inputedArray = InputStudentArray();
				if (decision == 1)
				{
					sequenceStudent->Append(new ArraySequence<Student>(inputedArray.items, inputedArray.count));
				}
				else if (decision == 2)
				{
					sequenceStudent->Append(new LinkedListSequence<Student>(inputedArray.items, inputedArray.count));
				}
			}
			else if (miniPage == 6)
			{
				auto inputedArray = InputTeacherArray();
				if (decision == 1)
				{
					sequenceTeacher->Append(new ArraySequence<Teacher>(inputedArray.items, inputedArray.count));
				}
				else if (decision == 2)
				{
					sequenceTeacher->Append(new LinkedListSequence<Teacher>(inputedArray.items, inputedArray.count));
				}
			}
			cout << endl;
			system("pause");
			page = -1;
		}
		else if (page == 2)
		{
			cout << "----------------------" << endl;
			cout << "|1. Sort             |" << endl;
			cout << "|2. Print            |" << endl;
			cout << "|3. Sort compare     |" << endl;
			cout << "|0. Quit             |" << endl;
			cout << "----------------------" << endl;
			int miniPage2;
			cin >> miniPage2;
			while (miniPage2 != 1 && miniPage2 != 2 && miniPage2 != 3  && miniPage2 != 0)
			{
				cout << "try again!" << endl;
				cin >> miniPage2;
			}
			int* choice = menuExistSequence();
			string name;
			string sorted= "(sorted)";
			steady_clock::time_point start;
			steady_clock::time_point end;


			switch (miniPage2)
			{
				case 1:
					name = sequenceNames->Get(choice[0])->Get(choice[1]) + sorted;
					sequenceNames->Get(choice[0])->Append(name);
					int typeSort;
					int typeCmp;
					cout << "--------------" << endl;
					cout << "|1.QuickSort |" << endl;
					cout << "|2.ShellSort |" << endl;
					cout << "|3.MergeSort |" << endl;
					cout << "|4.ShakerSort|" << endl;
					cout << "--------------" << endl;
					cin >> typeSort;
					switch (choice[0]) 
					{
						case 0:
							if (typeSort == 1)
							{
								sequenceInt->Append(sequenceInt->Get(choice[1])->QuickSort());
							}
							else if (typeSort == 2) 
							{
								sequenceInt->Append(sequenceInt->Get(choice[1])->ShellSort());
							}
							else if (typeSort == 3)
							{
								sequenceInt->Append(sequenceInt->Get(choice[1])->MergeSort());
							}
							else if (typeSort == 4)
							{
								sequenceInt->Append(sequenceInt->Get(choice[1])->ShakerSort());
							}
							printf("sequenceInt sorted");
							break;
						case 1:
							if (typeSort == 1)
							{
								sequenceFloat->Append(sequenceFloat->Get(choice[1])->QuickSort());
							}
							else if (typeSort == 2)
							{
								sequenceFloat->Append(sequenceFloat->Get(choice[1])->ShellSort());
							}
							else if (typeSort == 3)
							{
								sequenceFloat->Append(sequenceFloat->Get(choice[1])->MergeSort());
							}
							else if (typeSort == 4)
							{
								sequenceFloat->Append(sequenceFloat->Get(choice[1])->ShakerSort());
							}
							printf("sequenceFloat sorted");
							break;
						case 2:

							cout << "-------------" << endl;
							cout << "|1.Real     |" << endl;
							cout << "|2.Imaginary|" << endl;
							cout << "-------------" << endl;
							cin >> typeCmp;
							if (typeSort == 1)
							{
								sequenceComplexNumber->Append(sequenceComplexNumber->Get(choice[1])->QuickSort(cmpComplexNumber[typeCmp-1]));
							}
							else if (typeSort == 2)
							{
								sequenceComplexNumber->Append(sequenceComplexNumber->Get(choice[1])->ShellSort(cmpComplexNumber[typeCmp - 1]));
							}
							else if (typeSort == 3)
							{
								sequenceComplexNumber->Append(sequenceComplexNumber->Get(choice[1])->MergeSort(cmpComplexNumber[typeCmp - 1]));
							}
							else if (typeSort == 4)
							{
								sequenceComplexNumber->Append(sequenceComplexNumber->Get(choice[1])->ShakerSort(cmpComplexNumber[typeCmp - 1]));
							}
							printf("sequenceComplexNumber sorted");
							break;
						case 3:
							if (typeSort == 1)
							{
								sequenceCharPtr->Append(sequenceCharPtr->Get(choice[1])->QuickSort(cmpStr));
							}
							else if (typeSort == 2)
							{
								sequenceCharPtr->Append(sequenceCharPtr->Get(choice[1])->ShellSort(cmpStr));
							}
							else if (typeSort == 3)
							{
								sequenceCharPtr->Append(sequenceCharPtr->Get(choice[1])->MergeSort(cmpStr));
							}
							else if (typeSort == 4)
							{
								sequenceCharPtr->Append(sequenceCharPtr->Get(choice[1])->ShakerSort(cmpStr));
							}
							printf("sequenceCharPtr sorted");
							break;
						case 4:
							cout << "-------------" << endl;
							cout << "|1.FirstName|" << endl;
							cout << "|2.LastName |" << endl;
							cout << "|3.ID       |" << endl;
							cout << "-------------" << endl;
							cin >> typeCmp;
							if (typeSort == 1)
							{
								sequenceStudent->Append(sequenceStudent->Get(choice[1])->QuickSort(cmpStudent[typeCmp - 1]));
							}
							else if (typeSort == 2)
							{
								sequenceStudent->Append(sequenceStudent->Get(choice[1])->ShellSort(cmpStudent[typeCmp - 1]));
							}
							else if (typeSort == 3)
							{
								sequenceStudent->Append(sequenceStudent->Get(choice[1])->MergeSort(cmpStudent[typeCmp - 1]));
							}
							else if (typeSort == 4)
							{
								sequenceStudent->Append(sequenceStudent->Get(choice[1])->ShakerSort(cmpStudent[typeCmp - 1]));
							}
							printf("sequenceStudent sorted");
							break;
						case 5:
							cout << "-------------" << endl;
							cout << "|1.FirstName|" << endl;
							cout << "|2.LastName |" << endl;
							cout << "|3.ID       |" << endl;
							cout << "|4.Subject  |" << endl;
							cout << "-------------" << endl;
							cin >> typeCmp;
							if (typeSort == 1)
							{
								sequenceTeacher->Append(sequenceTeacher->Get(choice[1])->QuickSort(cmpTeacher[typeCmp - 1]));
							}
							else if (typeSort == 2)
							{
								sequenceTeacher->Append(sequenceTeacher->Get(choice[1])->ShellSort(cmpTeacher[typeCmp - 1]));
							}
							else if (typeSort == 3)
							{
								sequenceTeacher->Append(sequenceTeacher->Get(choice[1])->MergeSort(cmpTeacher[typeCmp - 1]));
							}
							else if (typeSort == 4)
							{
								sequenceTeacher->Append(sequenceTeacher->Get(choice[1])->ShakerSort(cmpTeacher[typeCmp - 1]));
							}
							printf("sequenceTeacher sorted");
							break;
					}
					
					break;

				case 2:
					switch (choice[0]) 
					{
						case 0:
							cout << "[ ";
							for (int i = 0; i < sequenceInt->Get(choice[1])->GetLength(); i++) 
							{
								cout << sequenceInt->Get(choice[1])->Get(i) << ' ';
							}
							cout << ']';
							break;
						case 1:
							cout << "[ ";
							 for (int i = 0; i < sequenceFloat->Get(choice[1])->GetLength(); i++)
							 {
								 cout << sequenceFloat->Get(choice[1])->Get(i) << ' ';
							 }
							 cout << ']';
							break;
						case 2:
							 for (int i = 0; i < sequenceComplexNumber->Get(choice[1])->GetLength(); i++)
							 {
								 cout << sequenceComplexNumber->Get(choice[1])->Get(i) << endl;
							 }
							 break;
						case 3:
							for (int i = 0; i < sequenceCharPtr->Get(choice[1])->GetLength(); i++)
							 {
								 cout << sequenceCharPtr->Get(choice[1])->Get(i) << ' ';
							 }
							 break;
				
						case 4:
							for (int i = 0; i < sequenceStudent->Get(choice[1])->GetLength(); i++)
							{
								cout << sequenceStudent->Get(choice[1])->Get(i) << endl;
								cout << "---------------" << endl;
							}
							break;
						case 5:
							for (int i = 0; i < sequenceTeacher->Get(choice[1])->GetLength(); i++)
							{
								cout << sequenceTeacher->Get(choice[1])->Get(i) << endl;
								cout << "---------------" << endl;
							}
							break;
					}
					break;
				case 3:
					start = steady_clock::now();
					end = steady_clock::now();
					Sequence<int>* passInt;
					Sequence<float>* passFloat;
					Sequence<ComplexNumber>* passComplexNumber;
					Sequence<char*>* passCharPtr;
					Sequence<Student>* passStudent;
					Sequence<Teacher>* passTeacher;
					switch (choice[0])
					{
						case 0:
							start = steady_clock::now();
							passInt = sequenceInt->Get(choice[1])->QuickSort();
							end = steady_clock::now();
							delete passInt;
							cout <<"QuickSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passInt = sequenceInt->Get(choice[1])->ShellSort();
						    end = steady_clock::now();
							delete passInt;
							cout << "ShellSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passInt = sequenceInt->Get(choice[1])->MergeSort();
							end = steady_clock::now();
							delete passInt;
							cout << "MergeSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passInt = sequenceInt->Get(choice[1])->ShakerSort();
							end = steady_clock::now();
							delete passInt;
							cout << "ShakerSort - " << duration<float>(end - start).count() << " sec" << endl;

							printf("sequenceInt sorted");
							break;
						case 1:
							start = steady_clock::now();
							passFloat = sequenceFloat->Get(choice[1])->QuickSort();
							end = steady_clock::now();
							delete passFloat;
							cout << "QuickSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passFloat = sequenceFloat->Get(choice[1])->ShellSort();
							end = steady_clock::now();
							delete passFloat;
							cout << "ShellSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passFloat = sequenceFloat->Get(choice[1])->MergeSort();
							end = steady_clock::now();
							delete passFloat;
							cout << "MergeSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passFloat = sequenceFloat->Get(choice[1])->ShakerSort();
							end = steady_clock::now();
							delete passFloat;
							cout << "ShakerSort - " << duration<float>(end - start).count() << " sec" << endl;

							printf("sequenceFloat sorted");
							break;
						case 2:
							cout << "-------------" << endl;
							cout << "|1.Real     |" << endl;
							cout << "|2.Imaginary|" << endl;
							cout << "-------------" << endl;
							cin >> typeCmp;
							start = steady_clock::now();
							passComplexNumber = sequenceComplexNumber->Get(choice[1])->QuickSort(cmpComplexNumber[typeCmp - 1]);
							end = steady_clock::now();
							delete passComplexNumber;
							cout << "QuickSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passComplexNumber = sequenceComplexNumber->Get(choice[1])->ShellSort(cmpComplexNumber[typeCmp - 1]);
							end = steady_clock::now();
							delete passComplexNumber;
							cout << "ShellSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passComplexNumber = sequenceComplexNumber->Get(choice[1])->MergeSort(cmpComplexNumber[typeCmp - 1]);
							end = steady_clock::now();
							delete passComplexNumber;
							cout << "MergeSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passComplexNumber = sequenceComplexNumber->Get(choice[1])->ShakerSort(cmpComplexNumber[typeCmp - 1]);
							end = steady_clock::now();
							delete passComplexNumber;
							cout << "ShakerSort - " << duration<float>(end - start).count() << " sec" << endl;

							printf("sequenceComplexNumber sorted");
							break;
						case 3:
							start = steady_clock::now();
							passCharPtr =sequenceCharPtr->Get(choice[1])->QuickSort();
							end = steady_clock::now();
							delete passCharPtr ;
							cout << "QuickSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passCharPtr =sequenceCharPtr->Get(choice[1])->ShellSort();
							end = steady_clock::now();
							delete passCharPtr ;
							cout << "ShellSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passCharPtr = sequenceCharPtr->Get(choice[1])->MergeSort();
							end = steady_clock::now();
							delete passCharPtr;
							cout << "MergeSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passCharPtr = sequenceCharPtr->Get(choice[1])->ShakerSort();
							end = steady_clock::now();
							delete passCharPtr;
							cout << "ShakerSort - " << duration<float>(end - start).count() << " sec" << endl;

							printf("sequenceCharPtr sorted");
							break;
						case 4:
							cout << "-------------" << endl;
							cout << "|1.FirstName|" << endl;
							cout << "|2.LastName |" << endl;
							cout << "|3.ID       |" << endl;
							cout << "-------------" << endl;
							cin >> typeCmp;
							start = steady_clock::now();
							passStudent = sequenceStudent->Get(choice[1])->QuickSort(cmpStudent[typeCmp - 1]);
							end = steady_clock::now();
							delete passStudent;
							cout << "QuickSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passStudent = sequenceStudent->Get(choice[1])->ShellSort(cmpStudent[typeCmp - 1]);
							end = steady_clock::now();
							delete passStudent;
							cout << "ShellSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passStudent = sequenceStudent->Get(choice[1])->MergeSort(cmpStudent[typeCmp - 1]);
							end = steady_clock::now();
							delete passStudent;
							cout << "MergeSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passStudent = sequenceStudent->Get(choice[1])->ShakerSort(cmpStudent[typeCmp - 1]);
							end = steady_clock::now();
							delete passStudent;
							cout << "ShakerSort - " << duration<float>(end - start).count() << " sec" << endl;

							printf("sequenceStudent sorted");
							break;
						case 5:
							cout << "-------------" << endl;
							cout << "|1.FirstName|" << endl;
							cout << "|2.LastName |" << endl;
							cout << "|3.ID       |" << endl;
							cout << "|4.Subject  |" << endl;
							cout << "-------------" << endl;
							cin >> typeCmp;
							start = steady_clock::now();
							passTeacher = sequenceTeacher->Get(choice[1])->QuickSort(cmpTeacher[typeCmp - 1]);
							end = steady_clock::now();
							delete passTeacher;
							cout << "QuickSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passTeacher = sequenceTeacher->Get(choice[1])->ShellSort(cmpTeacher[typeCmp - 1]);
							end = steady_clock::now();
							delete passTeacher;
							cout << "ShellSort - " << duration<float>(end - start).count() << " sec" << endl;	

							start = steady_clock::now();
							passTeacher = sequenceTeacher->Get(choice[1])->MergeSort(cmpTeacher[typeCmp - 1]);
							end = steady_clock::now();
							delete passTeacher;
							cout << "MergeSort - " << duration<float>(end - start).count() << " sec" << endl;

							start = steady_clock::now();
							passTeacher = sequenceTeacher->Get(choice[1])->ShakerSort(cmpTeacher[typeCmp - 1]);
							end = steady_clock::now();
							delete passTeacher;
							cout << "ShakerSort - " << duration<float>(end - start).count() << " sec" << endl;

							printf("sequenceTeacher sorted");
							break;
					}
					
			}
			cout << endl;
			system("pause");

			page = -1;
		}
		else if (page == 3)
		{
			LinkedListTests* testList = new LinkedListTests();
			DynamicArrayTests* testArray = new DynamicArrayTests();
			LinkedListSequenceTests* testListSequence = new LinkedListSequenceTests();
			ArraySequenceTests* testArraySequence = new ArraySequenceTests();
			SortsTests* testSort = new SortsTests();
			testArray->Test();
			std::this_thread::sleep_for(400ms);
			testList->Test();
			std::this_thread::sleep_for(400ms);
			testListSequence->Test();
			std::this_thread::sleep_for(400ms);
			testArraySequence->Test();
			std::this_thread::sleep_for(400ms);
			testSort->Test();
			std::this_thread::sleep_for(400ms);
			cout << "First Laba work correctly\n";
			system("pause");
			page = -1;
		}
		else if (page == 4) 
		{
			int begin, end, step,typeSort;
			cout << "Enter begin:" << endl;
			cin >> begin;
			cout << "Enter end:" << endl;
			cin >> end;
			cout << "Enter step:" << endl;
			cin >> step;
			float beginCopy = begin;
			Sequence<int>* pass;
			Sequence<int>* pass2;
			Sequence<char*>* pass3;
			Sequence<char*>* pass4;
			steady_clock::time_point start;
			steady_clock::time_point finish;
			float* itemsQuickSort = new float[((end-begin)/step)+1];
			float* itemsShellSort = new float[((end-begin)/step)+1];
			float* itemsMergeSort = new float[((end-begin)/step)+1];
			float* itemsShakerSort = new float[((end-begin)/step)+1];
			
			int i,j;
			i = 0;
			j = 0;
			while (typeSort != 1 & typeSort != 2) 
			{
				cout << "-------------" << endl;
				cout << "|1.Int       |" << endl;
				cout << "|2.Str       |" << endl;
				cout << "-------------" << endl;
				cin >> typeSort;
			}
			if (typeSort == 1) 
			{
				while (beginCopy <= end)
				{
					auto passInt = InputIntArray(beginCopy, 1, 1000000);
					pass = new ArraySequence<int>(passInt.items, passInt.count);
					start = steady_clock::now();
					pass2 = pass->QuickSort();
					finish = steady_clock::now();
					delete pass2;
					itemsQuickSort[i] = duration<float>(finish - start).count();
					start = steady_clock::now();
					pass2 = pass->ShellSort();
					finish = steady_clock::now();
					delete pass2;
					itemsShellSort[i] = duration<float>(finish - start).count();
					start = steady_clock::now();
					pass2 = pass->MergeSort();
					finish = steady_clock::now();
					delete pass2;
					itemsMergeSort[i] = duration<float>(finish - start).count();
					start = steady_clock::now();
					pass2 = pass->ShakerSort();
					finish = steady_clock::now();
					delete pass2;
					itemsShakerSort[i] = duration<float>(finish - start).count();
					i++;
					beginCopy += step;
				}
				chart(begin, end, step, itemsQuickSort,itemsShellSort, itemsMergeSort, itemsShakerSort);
			}
			else if(typeSort==2)
			{
				while (beginCopy <= end)
				{
					auto passStr = InputCharPtrArray(beginCopy);
					pass3 = new ArraySequence<char*>(passStr.items, passStr.count);
					start = steady_clock::now();
					pass4 = pass3->QuickSort();
					finish = steady_clock::now();
					delete pass4;
					itemsQuickSort[i] = duration<float>(finish - start).count();
					start = steady_clock::now();
					pass4 = pass3->ShellSort();
					finish = steady_clock::now();
					itemsShellSort[i] = duration<float>(finish - start).count();
					delete pass4;
					start = steady_clock::now();
					pass4 = pass3->MergeSort();
					finish = steady_clock::now();
					delete pass4;
					itemsMergeSort[i] = duration<float>(finish - start).count();
					start = steady_clock::now();
					pass4 = pass3->ShakerSort();
					finish = steady_clock::now();
					delete pass4;
					itemsShakerSort[i] = duration<float>(finish - start).count();
					i++;
					beginCopy += step;
				}
				chart(begin, end, step, itemsQuickSort, itemsShellSort, itemsMergeSort, itemsShakerSort);
			}
			page = -1;
		}
		else if (page == 5)
		{
			OpenGistogramma();
			system("pause");
			page = -1;
		}
		else if (page == 6) 
		{
			system("cls");
			cout << "----------------------" << endl;
			cout << "|1. Input            |" << endl;
			cout << "|2. Print            |" << endl;
			cout << "|0. Exit             |" << endl;
			cout << "----------------------" << endl;
			int miniPage;
			cin >> miniPage;
			Graph<int>* example;
			while (miniPage != 1 && miniPage != 2 && miniPage != 3 && miniPage != 4 && miniPage != 5 && miniPage != 6 && miniPage != 0)
			{
				cout << "try again!" << endl;
				cin >> miniPage;
			}
			if (miniPage == 1) 
			{
				cout << "Enter count :" << endl;
				int count;
				cin >> count;
				example = new Graph<int>(count, false);
				for (int i = 0; i < example->GetCountNode(); i++)
				{
					for (int j = 0; j < example->GetCountNode(); j++)
					{
						arc<int> pass ;
						pass.fromNode = i;
						pass.toNode = j;
						cout << "Enter ("<<i<<','<<j<<"):" << endl;
						cin >> pass.weight;
						example->Insert(pass);
					}
				}
			}
			if (miniPage == 2) 
			{
				for (int i = 0; i < example->GetCountNode(); i++)
				{
					cout << "[";
					for (int j = 0; j < example->GetCountNode(); j++)
					{
						cout << example->Get(i, j)<<" ";
					}
					cout << "]" << endl;
				}
				for (int i = 0; i < example->GetCountNode(); i++) 
				{
					cout << i << ":";
					for (int j = 0; j < example->GetCountNode(); j++) 
					{
						if (example->Get(i,j)!= 0) 
						{
							cout << example->Get(i, j) << " ";
						}
						cout << endl;
					}
				}
			}
				system("pause");
				page = -1;
		}
	}
}
int numberForGistogramm = 0;
extern void InputSequence(int dataType, int count, int min, int max)
{
	cout << dataType << " " << count << endl;
	string name = "ForGistogramm";
	string number = std::to_string(numberForGistogramm++);
	name.append("#");
	name.append(number);
	sequenceNames->Get(dataType)->Append(name);
	if (dataType == 0)
	{
		auto inputedArray = InputIntArray(count, min, max);
		sequenceInt->Append(new ArraySequence<int>(inputedArray.items, inputedArray.count));
	}
	else if (dataType == 1)
	{
		auto inputedArray = InputFloatArray(count, min, max);
		sequenceFloat->Append(new ArraySequence<float>(inputedArray.items, inputedArray.count));
	}
	else if (dataType == 2)
	{
		auto inputedArray = InputComplexNumberArray(count, min, max, min, max);
		sequenceComplexNumber->Append(new ArraySequence<ComplexNumber>(inputedArray.items, inputedArray.count));
	}
}
extern void InputSequence(int dataType, int count)
{
		string name = "ForGistogramm";
		string number = std::to_string(numberForGistogramm++);
		name.append("#");
		name.append(number);
		sequenceNames->Get(dataType)->Append(name);
		if (dataType == 3)
		{
			auto inputedArray = InputCharPtrArray(count);
			sequenceCharPtr->Append(new ArraySequence<char*>(inputedArray.items, inputedArray.count));
		}
		else if (dataType == 4)
		{
			auto inputedArray = InputStudentArray(count);
			sequenceStudent->Append(new ArraySequence<Student>(inputedArray.items, inputedArray.count));
		}
		else if (dataType == 5)
		{
			auto inputedArray = InputTeacherArray(count);
			sequenceTeacher->Append(new ArraySequence<Teacher>(inputedArray.items, inputedArray.count));
		}
}
	extern Dictionary<string,int>* GetPointsForGistogramm(int start,int end,int step,int dataType) 
	{
		Dictionary<string, int>* result = new Dictionary<string, int>(end-start);
		if (dataType == 0)
		{
			if (start < step) { start=step; }
			step = max(step, 1);
			for (int i = start; i < end; i += step)
			{
				int countElements = 0;
				for (int j = 0; j < sequenceInt->GetLast()->GetLength(); j++)
				{
					if (i - step < sequenceInt->GetLast()->Get(j) && sequenceInt->GetLast()->Get(j) < i + step)
					{
						countElements += 1;
					}
				}
				cout << std::to_string(i) << " " << countElements << endl;
				result->Add(std::to_string(i), countElements);

			}
			
		}
		else if (dataType == 1)
		{			
			if (start < step) { start = step / 2; }
			for (int i = start; i < end; i += step + 1 - step % 2)
			{
				int countElements = 0;
				for (int j = 0; j < sequenceFloat->GetLast()->GetLength(); j++)
				{
					if (i - step / 2 < sequenceFloat->GetLast()->Get(j) && sequenceFloat->GetLast()->Get(j) < i + step / 2)
					{
						countElements += 1;
					}
				}
				cout << std::to_string(i) << " " << countElements << endl;
				result->Add(std::to_string(i), countElements);

			}
			
		}
		else if (dataType == 2)
		{
			if (start < step) { start = step / 2; }
			for (int i = start; i < end; i += step + 1 - step % 2)
			{
				int countElements = 0;
				for (int j = 0; j < sequenceComplexNumber->GetLast()->GetLength(); j++)
				{
					if (i - step / 2 < sequenceComplexNumber->GetLast()->Get(j).GetRe() && sequenceComplexNumber->GetLast()->Get(j).GetRe() < i + step / 2)
					{
						countElements += 1;
					}
				}
				cout << std::to_string(i) << " " << countElements << endl;
				result->Add(std::to_string(i), countElements);

			}
		}
		
		return result;
	}
	extern  Dictionary<string, int>* GetPointsForGistogramm(int dataType)
	{
		Dictionary<string, int>* result = new Dictionary<string, int>(27);
		const string x[] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };

		if (dataType == 3)
		{
			const char forcmp[] = "abcdefghijklmnopqrstuvwxyz";
			for (int i = 0; i < 26; i++)
			{
				int countElements = 0;
				for (int j = 0; j < sequenceCharPtr->GetLast()->GetLength(); j++)
				{
					if (sequenceCharPtr->GetLast()->Get(j)[0] == forcmp[i])
					{
						countElements += 1;
					}
				}
				cout << x[i] << " " << countElements << endl;
				result->Add(x[i], countElements);
			}
		}
		else if (dataType == 4)
		{
			const char forcmp[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

			for (int i = 0; i < 26; i++)
			{
				int countElements = 0;
				for (int j = 0; j < sequenceStudent->GetLast()->GetLength(); j++)
				{
					if (sequenceStudent->GetLast()->Get(j).GetFirstName()[0] == forcmp[i])
					{
						countElements += 1;
					}
				}
				cout << x[i] << " " << countElements << endl;
				result->Add(x[i], countElements);
			}
		}
		else if (dataType == 5)
		{
			const char forcmp[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

			for (int i = 0; i < 26; i++)
			{
				int countElements = 0;
				for (int j = 0; j < sequenceTeacher->GetLast()->GetLength(); j++)
				{
					if (sequenceTeacher->GetLast()->Get(j).GetFirstName()[0] == forcmp[i])
					{
						countElements += 1;
					}
				}
				cout << x[i] << " " << countElements << endl;
				result->Add(x[i], countElements);
			}
		}
		return result;
	}