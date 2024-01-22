#include <iostream>
using namespace std;

/*
    Binary Search Iterative

    parameters:
    arr: sorted array
    key: integer of the number we are searching

    returns: index of the key element, or -1 if not found
*/

int binarySearchIterative(int arr[], int size, int key)
{

    int low;
    int high;
    int mid;

    // assign low to the first element of the array
    low = 0;
    // assing high to the last element of the array
    high = size - 1;

    while (low <= high)
    {
        // calculate mid
        mid = (low + high) / 2;

        // if it's equal, we found it
        if (key == arr[mid])
        {
            return mid;
        }
        // if key is smaller than mid, then we have to search in the left side
        if (key < arr[mid])
        {
            high = mid - 1;
        }
        // if key is greater than mid, then we have to search in the right side
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{

    int arr1[15] = {3, 6, 8, 12, 14, 17, 25, 29, 31, 36, 42, 47, 53, 55, 62};

    int size = sizeof(arr1) / sizeof(int);

    cout << "== BINARY SEARCH ITERATIVE ==" << endl;
    cout << "Key = 42, Index expected = 10" << endl;
    cout << "BS: " << binarySearchIterative(arr1, size, 42) << endl;

    cout << "Key = 12, Index expected = 3" << endl;
    cout << "BS: " << binarySearchIterative(arr1, size, 12) << endl;

    cout << "Key = 30, Index expected = -1" << endl;
    cout << "BS: " << binarySearchIterative(arr1, size, 30) << endl;
    return 0;
}