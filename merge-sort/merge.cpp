#include <iostream>
#include <vector>
using namespace std;

/*
    Merge two lists into a new list in ascending order.

    parameters:
    A -> list 1 (ordered list)
    B -> list 2 (ordered list)

    return: result -> list with the merged elements (ascending order)

*/
vector<int> merge(vector<int> A, vector<int> B)
{
    // Get the size of the lists
    int sizeA, sizeB;
    sizeA = A.size() - 1;
    sizeB = B.size() - 1;
    // Create the resulted merged list
    vector<int> result;
    // Create the indexes to transverse the lists
    int i, j;

    i = 0; // index for list A
    j = 0; // index for list B

    while (i <= sizeA && j <= sizeB)
    {
        // Add the smallest value to the list
        if (A[i] < B[j])
        {
            result.push_back(A[i]);

            // increment the index of A
            i++;
        }
        else
        {
            result.push_back(B[j]);
            // indrement the index of B
            j++;
        }
    }

    // add the remaining elements of either A or B list
    for (; i <= sizeA; i++)
    {
        result.push_back(A[i]);
    }

    for (; j <= sizeB; j++)
    {
        result.push_back(B[j]);
    }

    return result;
}

int main()
{
    vector<int> list1 = {1, 3, 5, 8, 9, 11};
    vector<int> list2 = {2, 4, 6, 10, 12, 15, 20};
    vector<int> mergedlist;

    mergedlist = merge(list1, list2);

    cout << " === MERGE TWO LISTS ===" << endl;
    for (int i = 0; i < mergedlist.size(); i++)
    {
        cout << mergedlist[i] << " ";
    }

    return 0;
}