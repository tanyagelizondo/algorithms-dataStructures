#include <iostream>
#include <vector>
using namespace std;

/*
    Merge method

*/
void merge(int low, int mid, int high, int arr[])
{
    int i, j, k;

    // Get the size of the 2 auxiliar arrays that we will use
    int sizeA = mid - low + 1; // from the beggining to mid
    int sizeB = high - mid;    // from mid to the end

    int A[sizeA]; // this array will contain the first half
    int B[sizeB]; // this array will contain the second half

    // Copy the data from the original array to the auxiliar arrays
    for (int i = 0; i < sizeA; i++)
    {
        A[i] = arr[low + i];
    }
    for (int i = 0; i < sizeB; i++)
    {
        B[i] = arr[mid + 1 + i]; // we add the +1 because we don't want to include mid
    }

    i = 0;   // initial index of the A subarray
    j = 0;   // initial index of the B subarray
    k = low; // initial index of the merged subarray

    while (i < sizeA && j < sizeB)
    {
        // if A[i] is smaller then add it to the array
        if (A[i] <= B[j])
        { // Actually we are overwriting the original array
            arr[k] = A[i];
            k++;
            i++;
        }
        else
        { // if B[j] is smaller then add it to the array
            arr[k] = B[j];
            k++;
            j++;
        }
    }

    // Copy the remaining elements (if any)
    for (; i < sizeA; i++)
    {
        arr[k] = A[i];
        k++;
    }

    for (; j < sizeB; j++)
    {
        arr[k] = B[j];
        k++;
    }
}

void mergeSort(int low, int high, int arr[])
{

    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(low, mid, arr);
        mergeSort(mid + 1, high, arr);
        merge(low, mid, high, arr);
    }
}

int main()
{

    int arr1[4] = {9, 3, 7, 5};

    mergeSort(0, 3, arr1);

    cout << "=== Merge Sort ===" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}