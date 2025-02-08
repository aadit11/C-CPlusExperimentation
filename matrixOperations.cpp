#include <iostream>
using namespace std;

/* In row major matrix, the element a[i] [j] will be at
 * base address + (row_index * total number of columns + column_index) * element_size
 * In column major matrix, the element at a[i] [j] will be at
 * base address + (column_index * total number of rows + row_index) * element_size */

void add(int arr1[][100], int arr2[][100], int r, int c)
{
    int arr3[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            arr3[i][j] = arr1[i][j] + arr2[i][j];
    for (int i = 0; i < r; i++)
    {
        {
            for (int j = 0; j < c; j++)
                cout << arr3[i][j] << " ";
        }
        cout << "\n";
    }
}

void multiply(int arr1[][100], int arr2[][100], int m, int n, int p)
{
    // arr1(mxn) * arr2(nxp) = arr3(mxp)
    int arr3[m][p];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
        {
            // initializing arr3 with 0
            arr3[i][j] = 0;
            // multiplying
            for (int k = 0; k < n; k++)
                arr3[i][j] += arr1[i][k] * arr2[k][j];
        }
    for (int i = 0; i < m; i++)
    {
        {
            for (int j = 0; j < p; j++)
                cout << arr3[i][j] << " ";
        }
        cout << "\n";
    }
}

void transpose(int arr[][100], int m)
{
    // swapping elements of lower traingle and upper triangle
    for (int i = 1; i < m; i++)
        for (int j = 0; j < i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    for (int i = 0; i < m; i++)
    {
        {
            for (int j = 0; j < m; j++)
                cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void lowerTriangle(int arr[][100], int m)
{
    // for any element if i>j
    int sum = 0;
    for (int i = 1; i < m; i++)
        for (int j = 0; j < i; j++)
            sum += arr[i][j];
    cout << "Sum of all elements of lower triangle = " << sum << endl;
}

void upperTriangle(int arr[][100], int m)
{
    // for any element i<j
    int sum = 0;
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            sum += arr[i][j];
    cout << "Sum of all elements of upper triangle = " << sum << endl;
}

void diagonal(int arr[][100], int m)
{
    // for any element i=j
    int sum = 0;
    for (int i = 0; i < m; i++)
        sum += arr[i][i];
    cout << "Sum of all elements of main diagonal = " << sum << endl;
}

void saddlePoint(int arr[][100], int m)
{
    // A matrix is said to have a saddle point id some entry a[i][j] is the smallest value in row i and largest value in column j
    for (int i = 0; i < m; i++)
    {
        // check each row for saddle point
        // find smallest value of row i
        int rowvalue = arr[i][0];
        int rowloc = 0;
        for (int j = 1; j < m; j++)
        {
            if (rowvalue > arr[i][j])
            {
                rowvalue = arr[i][j];
                rowloc = j;
            }
        }
        // find the largest value in column by rowloc
        int colvalue = arr[0][rowloc];
        int colloc = 0;
        for (int j = 1; j < m; j++)
        {
            if (colvalue < arr[j][rowloc])
            {
                colvalue = arr[j][rowloc];
                colloc = j;
            }
        }
        if (i == colloc)
        {
            cout << "Saddle point exists at " << i << "," << rowloc << endl;
            return;
        }
    }
    cout << "Saddle point does not exist!" << endl;
}

int main()
{
    int arr1[100][100];
    int arr2[100][100];
    int r1, c1;
    cout << "Enter number of rows of matrix 1: " << endl;
    cin >> r1;
    cout << "Enter number of columns of matrix 1: " << endl;
    cin >> c1;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> arr1[i][j];
    int r2, c2;
    cout << "Enter number of rows of matrix 2: " << endl;
    cin >> r2;
    cout << "Enter number of columns of matrix 2: " << endl;
    cin >> c2;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> arr2[i][j];
    int ch;
    char ans;
    do
    {
        cout << "\n1. Addition\n2. Multiplication\n3. Transpose\n4. Special Sum\n5. Saddle Point\n6. Exit\n"
             << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (r1 == r2 && c1 == c2)
            {
                add(arr1, arr2, r1, c1);
            }
            break;
        case 2:
            if (c1 == r2)
            {
                cout << "Matrix 1 x Matrix 2" << endl;
                multiply(arr1, arr2, r1, c1, c2);
            }
            if (c2 == r1)
            {
                cout << "Matrix 2 x Matrix 1" << endl;
                multiply(arr2, arr1, r2, c2, c1);
            }
            break;
        case 3:
            if (r1 == c1)
            {
                cout << "Transpose of first matrix: " << endl;
                transpose(arr1, r1);
            }
            if (r2 == c2)
            {
                cout << "Transpose of second matrix: " << endl;
                transpose(arr2, r2);
            }
            break;
        case 4:
        {
            int ch1;
            char ans1;
            do
            {
                cout << "\n1. Sum of lower traingle\n2. Sum of upper traingle\n3. Sum of main diagonal\n"
                     << endl;
                cout << "Enter your choice: " << endl;
                cin >> ch1;
                switch (ch1)
                {
                case 1:
                    if (r1 == c1)
                        lowerTriangle(arr1, r1);
                    break;
                case 2:
                    if (r1 == c1)
                        upperTriangle(arr1, r1);
                    break;
                case 3:
                    if (r1 == c1)
                        diagonal(arr1, r1);
                    break;
                default:
                    cout << "Wrong Input!" << endl;
                    break;
                }
                cout << "Do you want to continue? (y/n): " << endl;
                cin >> ans1;
            } while (ans1 == 'y' || ans == 'Y');
        }
        break;
        case 5:
            if (r1 == c1)
            {
                cout << "Saddle point of matrix 1: " << endl;
                saddlePoint(arr1, r1);
            }
            if (r2 == c2)
            {
                cout << "Saddle point of matrix 2: " << endl;
                saddlePoint(arr2, r2);
            }
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Wrong Input!" << endl;
            break;
        }
        cout << "Do you want to go back to main menu? (y/n): " << endl;
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}
