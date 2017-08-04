#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

void swap(int& left, int& right) {
	int temp = left;
	left = right;
	right = temp;
}

void partition(int size, int* array) {
	int p = array[0];
	int left = 0, equal = 1;

	for (int i = 1; i < size; ++i)
	{
		if (p > array[i]) {
			swap(array[equal + left], array[i]);
			++left;
		}
		else if (p == array[i]) {
			swap(array[equal], array[i]);
			++equal;
		}

#if 0
		cout << "Left " << left << " Equal " << equal << endl;
		for (int j = 0 ; j <= i ; ++j) {
		cout << array[j] << " ";
		}
		cout << endl;
#endif
	}

	for (int i = 0; i < equal; ++i)
	{
		swap(array[i], array[equal + left - 1 - i]);
	}

	for (int i = 0 ; i < size ; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
} 

int main()
{
	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
	   scanf("%d", &_ar[_ar_i]); 
	}

	partition(_ar_size, _ar);
	   
	return 0;
}