/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

int partition(int array[], int first, int last)
{
	int pivot = array[last];
	int i = (first - 1); 

	for (int j = first; j <= last - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[i + 1], array[last]);
	return (i + 1);
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


void quickSort(int array[], int first, int last)
{
	if (first < last)
	{
		int part = partition(array, first, last);

		quickSort(array, first, part - 1);
		quickSort(array, part + 1, last);
	}
}

void print(int array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
}


int main()
{
    int *array, num, j, k;


	cout << "Enter the number of integer elements: ";
	cin >> num; cout << endl;

	array = new int[num];

	cout << "Enter the elements: ";
	for (j = 0; j < num; j++)
	{
		cin >> array[j];
	}
	cout << endl << endl << endl;
	
	cout << "Quick sort results: " << endl;
	quickSort(array, 0, num - 1);
	print(array, num);

}
