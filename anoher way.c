#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>
int size = 100000;
int array[100000];
//make array random of 1000000 elements
void Random_number(int array[])
{
  int i;
  srand(time(NULL));
  for (i=0 ; i<size ; i++)
  {
       array[i] = rand() % 100000 + 1;

  }
}
//Function to sort an array using insertion sort
void insertion_sort(int arr[] , int size)
{
    int i, Comp, j;
    for (i = 1; i < size; i++) {
        Comp = arr[i];
        j = i - 1;
    while (j >= 0 && arr[j] > Comp) {
        arr[j + 1] = arr[j];
        j = j - 1;
        }
        arr[j + 1] = Comp;
    }
    printf("\nThe array is sorted using insertion sort in %u seconds\n", clock());
}
//function to swap elements in in quick sort
void swap(int *i, int *j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}

void quick_sort(int high, int low) {
	if (high >= low)return;
	int comp = high, i = high + 1, j = low;
	while (i <= j) {
		while (i <= low && array[i] <= array[comp])
            i++;
		while (j > high && array[j] >= array[comp])
            j--;
		if (i > j) swap(&array[comp], &array[j]);
		else swap(&array[i], &array[j]);
	}

	quick_sort(high, j - 1);
	quick_sort(j + 1, low);

}


int main()
{
  	int i;
	srand(time(NULL));
	for (i = 0; i < size; i++) {
		array[i] = rand() % 100000 + 1;
	}
	Random_number(array);

	printf("Array of 100000 random numbers is initialized\n");


	quick_sort(0, size - 1);
	printf("The array is sorted using quick sort in %u seconds", clock());

    insertion_sort(array, size);
    return 0;
}
