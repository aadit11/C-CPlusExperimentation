#include <iostream>
#include <cstring>
using namespace std;

void readString(char s[])
{
    cout << "Enter the string: " << endl;
    // gets(s);
    int i = 0;
    while ((s[i] = getchar()) != '\n')
        i++;
    s[i] = '\0';
}

void lengthString(char s[])
{
    int l = 0;
    // l = strlen(s);
    while (s[l] != '\0')
        l++;
    cout << "Length of string is: " << l << endl;
}

void copyString(char s1[], char s2[])
{
    // strcpy(s1, s2);
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    cout << "Copied String is: " << s1 << endl;
}

void comparisonString(char s1[], char s2[])
{
    int i;
    /*
    i = strcmp(s1, s2);
    if (i == 0)
        cout << "s1=s2" << endl;
    else if (i > 0)
        cout << "s1>s2" << endl;
    else
        cout << "s1<s2" << endl;
    */
    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
        // locating place of mismatch
        i++;
    if (s1[i] > s2[i])
        cout << "s1>s2" << endl;
    else if (s1[i] < s2[i])
        cout << "s1<s2" << endl;
    else
        cout << "s1=s2" << endl;
}

void reverseString(char s[])
{
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j)
    {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    cout << "Reversed string is: " << s << endl;
}

void concatenateString(char s1[], char s2[])
{
    // strcat(s1, s2);
    int i = strlen(s1);
    for (int j = 0; s2[j] != '\0'; i++, j++)
        s1[i] = s2[j];
    s1[i] = '\0';
    cout << "Concatenated string is: " << s1 << endl;
}

void searchString(char s[])
{
    char subs[100];
    cout << "Enter the search string: " << endl;
    gets(subs);
    // i is the index for main string
    // j is the index for search string
    int i, j = 0;
    while (s[i] != '\0')
    {
        // if first char of search string is found in main string
        while (s[i] != subs[0] && s[i] != '\0')
            i++;
        // remember the location of i
        int k = i;
        // match the remaining chars of search string
        while (s[i] == subs[j] && s[i] != '\0' && subs[j] != '\0')
        {
            i++;
            j++;
        }
        // entire search string found
        if (subs[j] == '\0')
        {
            cout << "Search string found at: " << k << endl;
            return;
        }
        // reached the end of main string
        if (s[i] == '\0')
        {
            cout << "Search string not found!" << endl;
            return;
        }
        // continue searching
        i = k + 1;
        j = 0;
    }
    cout << "Search string not found!" << endl;
}

int main()
{
    char s1[100], s2[100];
    int ch;
    char ans;
    do
    {
        cout << "\n1. Read\n2. Length\n3. Copy\n4. Compare\n5. Reverse\n6. Concatenate\n7. Search\n8. Exit\n"
             << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            readString(s1);
            readString(s2);
            break;
        case 2:
            lengthString(s1);
            lengthString(s2);
            break;
        case 3:
            copyString(s1, s2);
            break;
        case 4:
            comparisonString(s1, s2);
            break;
        case 5:
            reverseString(s1);
            reverseString(s2);
            break;
        case 6:
            concatenateString(s1, s2);
            break;
        case 7:
            searchString(s1);
            searchString(s2);
            break;
        case 8:
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
