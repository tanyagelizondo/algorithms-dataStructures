#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int low, int high, int key)
{
    int mid;
    if (low == high)
    {

        if (arr[low] == key)
        {
            return low;
        }
        else
        {
            // the element was not found
            return -1;
        }
    }
    else
    {
        mid = (low + high) / 2;

        if (key == arr[mid])
        {
            return mid;
        }
        // performe bsr in the left side
        if (key < arr[mid])
        {
            return binarySearchRecursive(arr, low, mid - 1, key);
        }
        else
        {
            // peprform the bsr to tge right side (cause it'a bigger)
            return binarySearchRecursive(arr, mid + 1, high, key);
        }
    }
}

int main()
{

    int arr1[15] = {3, 6, 8, 12, 14, 17, 25, 29, 31, 36, 42, 47, 53, 55, 62};

    int size = sizeof(arr1) / sizeof(int);
    int l = 0;
    int h = size - 1;

    cout << "== BINARY SEARCH Recursive ==" << endl;
    cout << "Key = 42, Index expected = 10" << endl;
    cout << "BS: " << binarySearchRecursive(arr1, l, h, 42) << endl;

    cout << "Key = 12, Index expected = 3" << endl;
    cout << "BS: " << binarySearchRecursive(arr1, l, h, 12) << endl;

    cout << "Key = 30, Index expected = -1" << endl;
    cout << "BS: " << binarySearchRecursive(arr1, l, h, 30) << endl;
    return 0;
}