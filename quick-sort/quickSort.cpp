#include <iostream>

using namespace std;

int partition(int low, int high, int arr[])
{

    int i, j;
    int pivot = arr[low];
    i = low;
    j = high;
    while (i < j)
    {
        // increment i until you find an element greater than pivot
        while (arr[i] <= pivot)
        {
            i++;
        }
        // decrement j until you find an element smaller or equal to pivot
        while (arr[j] > pivot)
        {
            j--;
        }

        // we haven't transverse all the array, then continue with the swaps
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    // now we have to swap the pivot to the correct position
    swap(arr[low], arr[j]);

    return j;
}

void quickSort(int low, int high, int arr[])
{
    int j;

    // At least there's two elements in the array
    if (low < high)
    {

        j = partition(low, high, arr);
        quickSort(low, j, arr);
        quickSort(j + 1, high, arr);
    }
}
int main()
{

    int arr1[4] = {1, 3, 4, 2};

    quickSort(0, 3, arr1);

    for (int i = 0; i < 4; i++)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}