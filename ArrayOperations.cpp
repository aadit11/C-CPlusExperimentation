#include <iostream>
using namespace std;

void deleteElement(int arr[], int &n)
{
    int pos;
    cout << "Enter the location of the element which is to be deleted: " << endl;
    cin >> pos;
    if (pos > n)
        cout << "Element can not be deleted" << endl;
    else
    {
        for (int i = pos - 1; i < n - 1; i++) // replacing the element to be deleted with the following element
            arr[i] = arr[i + 1];
        cout << "Resultant Array is: " << endl;
        n--; // updating the size after deletion
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
}

void insertElement(int arr[], int &n)
{
    int pos, value;
    cout
        << "Enter the location where you wish to insert an element: " << endl;
    cin >> pos;
    cout << "Enter the value to insert: " << endl;
    cin >> value;
    for (int i = n - 1; i >= pos - 1; i--) // creating space by shifting the element down
        arr[i + 1] = arr[i];
    arr[pos - 1] = value; // at the desired space inserting the element
    n++;                  // updating size after insertion
    cout << "Resultant Array is: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void reverseArray(int arr[], int n)
{
    int startPos = 0;
    int endPos = n - 1;
    int temp;
    while (startPos < endPos)
    {
        // swapping first and last elements
        temp = arr[startPos];
        arr[startPos] = arr[endPos];
        arr[endPos] = temp;
        startPos++;
        endPos--;
    }
    cout << "Resultant Array is: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n;
    cout << "How many elements are there in array: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ch;
    char ans;
    do
    {
        cout << "\n1. Delete\n2. Insert\n3. Reverse\n4. Exit\n"
             << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            deleteElement(arr, n);
            break;
        case 2:
            insertElement(arr, n);
            break;
        case 3:
            reverseArray(arr, n);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Wrong Input!" << endl;
            break;
        }
        cout << "Do you want to continue? (y/n): " << endl;
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}
