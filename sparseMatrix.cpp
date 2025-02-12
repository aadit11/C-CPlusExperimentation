#include <iostream>
using namespace std;
#define MAX 100

void readMatrix(int a[10][10], int m, int n)
{
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
}

void readSparse(int b[MAX][3], int m, int n, int t)
{
    b[0][0] = m;
    b[0][1] = n;
    b[0][2] = t;
    cout << "Enter the elements in triple form (row, column, value): " << endl;
    for (int i = 1; i <= t; i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];
}

void displayMatrix(int a[10][10], int m, int n)
{
    cout << "\nMatrix Form\n"
         << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << "\n";
    }
}

void displaySparse(int b[MAX][3])
{
    cout << "\nSparse Form\n"
         << endl;
    int n = b[0][2]; // number of triples
    for (int i = 0; i <= n; i++)
        cout << b[i][0] << "\t" << b[i][1] << "\t" << b[i][2] << endl;
}

void convert_conventional_sparse(int a[10][10], int m, int n, int b[MAX][3])
{
    int i, j, k;
    // i,j are indices for 2d matrix
    // k is index for sparse form
    k = 1;       // starting from row no. 1
    b[0][0] = m; // storing no. of rows
    b[0][1] = n; // storing no. of columns
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            // checking for non-zero elements
            if (a[i][j] != 0)
            {
                b[k][0] = i;       // storing index of row
                b[k][1] = j;       // storing index of column
                b[k][2] = a[i][j]; // storing non-zero value
                k++;
            }
    b[0][2] = k - 1; // storing total no. of non-zero values
}

void convert_sparse_conventional(int b[MAX][3], int a[10][10])
{
    int i, j, k;
    // i,j are indices for 2d matrix
    // k is index for sparse form
    k = 1; // starting from row no. 1
    for (i = 0; i < b[0][0]; i++)
        for (j = 0; j < b[0][1]; j++)
        {
            if (k > b[0][2] || i != b[k][0] || j != b[k][1])
                a[i][j] = 0;
            else
            {
                a[i][j] = b[k][2];
                k++;
            }
        }
}

void slowTranspose(int b[MAX][3], int bt[MAX][3])
{
    int k, n;
    bt[0][0] = b[0][1]; // no. of rows of transpose = no. of columns of original
    bt[0][1] = b[0][0]; // no. of columns of transpose = no. of rows of original
    bt[0][2] = b[0][2]; // no. of non-zero terms will be equal in both
    k = 1;
    n = b[0][2];
    for (int i = 0; i < b[0][1]; i++)
        for (int j = 1; j <= n; j++)
            // if column no of current triplet == i then insert the element in transpose
            if (i == b[j][1])
            {
                bt[k][0] = i;
                bt[k][1] = b[j][0];
                bt[k][2] = b[j][2];
                k++;
            }
}

void fastTranspose(int b[MAX][3], int bt[MAX][3])
{
    int m, n, t, i, col_num, loc;
    int total[MAX], index[MAX];
    m = b[0][0];
    n = b[0][1];
    t = b[0][2];
    bt[0][0] = n; // no. of rows of transpose = no. of columns of original
    bt[0][1] = m; // no. of columns of transpose = no. of rows of original
    bt[0][2] = t; // no. of non-zero terms will be equal in both
    for (i = 0; i < n; i++)
        total[i] = 0;
    for (i = 1; i <= t; i++)
    {
        col_num = b[i][1];
        total[col_num]++;
    }
    index[0] = 1;
    for (i = 1; i < n; i++)
        index[i] = index[i - 1] + total[i - 1];
    for (i = 1; i <= t; i++)
    {
        col_num = b[i][1];
        loc = index[col_num];
        index[col_num]++;
        bt[loc][0] = b[i][1];
        bt[loc][1] = b[i][0];
        bt[loc][2] = b[i][2];
    }
}

void additionSparse(int b1[MAX][3], int b2[MAX][3], int b3[MAX][3])
{
    int t1, t2, i, j, k;
    t1 = b1[0][2];
    t2 = b2[0][2];
    i = j = k = 0;
    b3[0][0] = b1[0][0];
    b3[0][1] = b1[0][1];
    while (i <= t1 && j <= t2)
    {
        if (b1[i][0] < b2[j][0])
        {
            // row numbers are not equal
            b3[k][0] = b1[i][0];
            b3[k][1] = b1[i][1];
            b3[k][2] = b1[i][2];
            k++;
            i++;
            goto last;
        }
        if (b2[j][0] < b1[i][0])
        {
            // row numbers are not equal
            b3[k][0] = b2[j][0];
            b3[k][1] = b2[j][1];
            b3[k][2] = b2[j][2];
            k++;
            j++;
            goto last;
        }
        if (b1[i][1] < b2[j][1])
        {
            // row numbers are equal, compare column
            b3[k][0] = b1[i][0];
            b3[k][1] = b1[i][1];
            b3[k][2] = b1[i][2];
            k++;
            i++;
            goto last;
        }
        if (b2[j][1] < b1[i][1])
        {
            // row numbers are equal, compare column
            b3[k][0] = b2[j][0];
            b3[k][1] = b2[j][1];
            b3[k][2] = b2[j][2];
            k++;
            j++;
            goto last;
        }
        b3[k][0] = b1[i][0];
        // row and column numbers are equal
        b3[k][1] = b1[i][1];
        b3[k][2] = b1[i][2] + b2[j][2];
        k++;
        i++;
        j++;
    last:;
    }
    while (i <= t1)
    {
        // copy remaining terms from b1
        b3[k][0] = b1[i][0];
        b3[k][1] = b1[i][1];
        b3[k][2] = b1[i][2];
        k++;
        i++;
    }
    while (j <= t2)
    {
        // copy remaining terms from b2
        b3[k][0] = b2[j][0];
        b3[k][1] = b2[j][1];
        b3[k][2] = b2[j][2];
        k++;
        j++;
    }
    b3[0][2] = k - 1; // set number of terms in b3
}

void multiplicationSparse(int b1[MAX][3], int b2[MAX][3], int b3[MAX][3])
{
    int b22[MAX][3];
    int i, j, k, b1rno, b2colno, i1, sum, t1, t2;
    t1 = b1[0][2];
    t2 = b2[0][2];
    if (b1[0][1] != b2[0][0])
    {
        cout << "Cannot multiply!" << endl;
        return;
    }
    fastTranspose(b2, b22);
    k = 1;
    i = 1;
    while (i <= t1)
    {
        i1 = i;
        j = 1;
        while (j <= t2)
        {
            b1rno = b1[i][0];
            b2colno = b22[j][0];
            sum = 0;
            while (i <= t1 && j <= t2 && b1rno == b1[i][0] && b2colno == b22[j][0])
            {
                if (b1[i][1] == b22[j][1])
                {
                    sum += b1[i][2] * b22[j][2];
                    i++;
                    j++;
                }
                else if (b1[i][1] < b22[j][1])
                    i++;
                else
                    j++;
            }
            if (sum != 0)
            {
                b3[k][0] = b1rno;
                b3[k][1] = b2colno;
                b3[k][2] = sum;
                k++;
            }
            if (j <= t2)
                i = i1;
            while (b2colno == b22[j][0] && j <= t2)
                j++;
        }
        while (b1rno == b1[i][0] && i <= t1)
            i++;
    }
    b3[0][0] = b1[0][0];
    b3[0][1] = b22[0][0];
    b3[0][2] = k - 1;
}

int main()
{
    int a[10][10]; // matrix
    int m, n, t;
    int b[MAX][3];  // sparse form
    int bt[MAX][3]; // transpose of sparse
    int b1[MAX][3], b2[MAX][3], b3[MAX][3];
    int ch;
    char ans;
    do
    {
        cout << "\n1. Conventional to Sparse Representation\n2. Sparse to Conventional Representation\n3. Transpose\n4. Addition\n5. Multiplication\n6. Exit\n"
             << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the number of rows: " << endl;
            cin >> m;
            cout << "Enter the number of columns: " << endl;
            cin >> n;
            readMatrix(a, m, n);
            convert_conventional_sparse(a, m, n, b);
            displaySparse(b);
            break;
        case 2:
            cout << "Enter the number of rows: " << endl;
            cin >> m;
            cout << "Enter the number of columns: " << endl;
            cin >> n;
            cout << "Enter the number of non-zero elements: " << endl;
            cin >> t;
            readSparse(b, m, n, t);
            convert_sparse_conventional(b, a);
            displayMatrix(a, m, n);
            break;
        case 3:
        {
            int ch1;
            cout << "\n1. Slow Transpose\n2. Fast Transpose\n"
                 << endl;
            cout << "Enter your choice: " << endl;
            cin >> ch1;
            switch (ch1)
            {
            case 1:
                cout << "Enter the number of rows: " << endl;
                cin >> m;
                cout << "Enter the number of columns: " << endl;
                cin >> n;
                cout << "Enter the number of non-zero elements: " << endl;
                cin >> t;
                readSparse(b, m, n, t);
                slowTranspose(b, bt);
                displaySparse(bt);
                break;
            case 2:
                cout << "Enter the number of rows: " << endl;
                cin >> m;
                cout << "Enter the number of columns: " << endl;
                cin >> n;
                cout << "Enter the number of non-zero elements: " << endl;
                cin >> t;
                readSparse(b, m, n, t);
                fastTranspose(b, bt);
                displaySparse(bt);
                break;
            default:
                cout << "Wrong Input!" << endl;
                break;
            }
        }
        break;
        case 4:
            cout << "Enter the number of rows: " << endl;
            cin >> m;
            cout << "Enter the number of columns: " << endl;
            cin >> n;
            cout << "Enter the number of non-zero elements of sparse 1: " << endl;
            cin >> t;
            readSparse(b1, m, n, t);
            cout << "Enter the number of non-zero elements of sparse 2: " << endl;
            cin >> t;
            readSparse(b2, m, n, t);
            additionSparse(b1, b2, b3);
            displaySparse(b3);
            break;
        case 5:
            cout << "Enter the number of rows: " << endl;
            cin >> m;
            cout << "Enter the number of columns: " << endl;
            cin >> n;
            cout << "Enter the number of non-zero elements of sparse 1: " << endl;
            cin >> t;
            readSparse(b1, m, n, t);
            cout << "Enter the number of rows: " << endl;
            cin >> m;
            cout << "Enter the number of columns: " << endl;
            cin >> n;
            cout << "Enter the number of non-zero elements of sparse 2: " << endl;
            cin >> t;
            readSparse(b2, m, n, t);
            multiplicationSparse(b1, b2, b3);
            displaySparse(b3);
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
