#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n1, n2, i, j, k;
    cout << "How many elements are there in array 1: " << endl;
    cin >> n1;
    int arr1[n1];
    cout << "Enter the elements of array 1: " << endl;
    for (i = 0; i < n1; i++)
        cin >> arr1[i];
    sort(arr1, arr1 + n1);
    cout << "How many elements are there in array 2: " << endl;
    cin >> n2;
    int arr2[n2];
    cout << "Enter the elements of array 2: " << endl;
    for (j = 0; j < n2; j++)
        cin >> arr2[j];
    sort(arr2, arr2 + n2);
    int arr3[n1 + n2];
    i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < n1)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < n2)
    {
        arr3[k++] = arr2[j++];
    }
    cout << ("Merged array is: ") << endl;
    for (k = 0; k < n1 + n2; k++)
    {
        cout << arr3[k] << " ";
    }
    return 0;
}
