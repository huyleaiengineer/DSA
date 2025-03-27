#include <bits/stdc++.h>
using namespace std;

/// parameters
const int MAX_ARR_LEN = 10000;
int a[MAX_ARR_LEN]; // Array
int n; // Number of array elements
string s = "array.txt"; // File contains an array.

/// Functions
void readFile(string s);
void show(int a[], int n);

int Sequential_Search(int a[], int n, int val);
int Sequential_Search_recusion(int a[], int n, int val);
int Binary_Search(int a[], int n, int val);
int Binary_Search_rescursion(int a[], int l, int r, int val);

int main()
{
    readFile(s);
    cout << "Original Array: " << "\n";
    show(a, n);
    cout << "Found Elemnt: 10 -11 12 -20 14\n";

    cout << "Sequential Search\n";
    cout << Sequential_Search(a, n, 10) << ' ';
    cout << Sequential_Search(a, n, -11)<< ' ';
    cout << Sequential_Search(a, n, 12) << ' ';
    cout << Sequential_Search(a, n, -20) << ' ';
    cout << Sequential_Search(a, n, 14) << "\n";

     cout << "Sequential Search Recursion\n";
    cout << Sequential_Search_recusion(a, n, 10) << ' ';
    cout << Sequential_Search_recusion(a, n, -11)<< ' ';
    cout << Sequential_Search_recusion(a, n, 12) << ' ';
    cout << Sequential_Search_recusion(a, n, -20) << ' ';
    cout << Sequential_Search_recusion(a, n, 14) << "\n";

    sort(a, a+n);
    cout << "Sorted Array: ";
    show(a, n);

    cout << "Found Elemnt: 10 -11 12 -20 14\n";

    cout << "Binary Search\n";
    cout << Binary_Search(a, n, 10) << ' ';
    cout << Binary_Search(a, n, -11)<< ' ';
    cout << Binary_Search(a, n, 12) << ' ';
    cout << Binary_Search(a, n, -20) << ' ';
    cout << Binary_Search(a, n, 14) << "\n";

     cout << "Binary Search recursion\n";
    cout << Binary_Search_rescursion(a, 0, n-1, 10) << ' ';
    cout << Binary_Search_rescursion(a, 0, n-1, -11)<< ' ';
    cout << Binary_Search_rescursion(a, 0, n-1, 12) << ' ';
    cout << Binary_Search_rescursion(a, 0, n-1, -20) << ' ';
    cout << Binary_Search_rescursion(a, 0, n-1, 14) << "\n";

    return 0;
}

/// Functions
void readFile(string s)
{
    ifstream f(s);
    f >> n;
    for (int i = 0; i < n; ++i)
        f >> a[i];
}

void show(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}

int Sequential_Search(int a[], int n, int val)
{
    for (int i = 0; i < n; ++i)
        if (a[i] == val)
            return i;
    return -1;
}


int Sequential_Search_recusion(int a[], int n, int val)
{
    if (n == 0)
        return -1;
    if (a[n-1] == val)
        return n;
    return Sequential_Search_recusion(a, n-1, val);
}


int Binary_Search(int a[], int n, int val)
{
    int l = 0, r = n-1, mid;
    while (l <= r)
    {
        mid = l + (r-l)/2;
        if (a[mid] == val)
            return mid;
        else if (a[mid] < val)
            l = mid+1;
        else
            r = mid - 1;
    }
    return -1;
}

int Binary_Search_rescursion(int a[], int l, int r, int val)
{
    if (l <= r)
    {
        int mid = l + (r-l)/2;
        if (a[mid] == val)
            return mid;
        else if (a[mid] < val)
            return Binary_Search_rescursion(a, mid+1, r, val);
        else
             return Binary_Search_rescursion(a, l, mid-1, val);
    }
   // else
     return -1;
}


