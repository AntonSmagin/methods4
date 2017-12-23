#include <iostream>
#include <string> 
#include <stdio.h>
#include "time.h"

class Array
{
	int *arr;
	int count;
	int *copyarr;

	void Merg(int begin, int end);
	void MergSort(int left, int right);

public:

	Array();
	Array(int count);
	~Array();
	int size_arr();
	void add(int data);
	void random_add(int n, int range);
	int print_arr(int i);

	void InsertionSort();
	void ShellSort();
	void WrapperMergeSort();
	void CountingSort();
	int InterpolationSearch(int key);
	int InterpolationSearchTracking(int key, int ind);



	void copy();
	void copyArr();
	void delete_arr();
};
