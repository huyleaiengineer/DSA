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

void add_head(int a[], int val, int &n);
void add_tail(int a[], int val, int &n);
void add_any_pos(int a[], int val, int &n, int k);

void remove_head(int a[], int &n);
void remove_tail(int a[], int &n);
void remove_any_pos(int a[], int &n, int k);

void change_value(int a[], int n, int k, int val);




int main()
{

    /// First element means oth position, 2nd element ~ a[1], ....

    readFile(s);
    cout << "Originial Array: ";
    show(a, n);

    cout << "After adding 5 into head of Array: ";
    add_head(a, 5, n);
    show(a, n);

    cout << "After adding 105 into tail of Array: ";
    add_tail(a, 105, n);
    show(a, n);

    cout << "After adding 207 into 5th position in Array: ";
    add_any_pos(a, 207, n, 4);
    show(a, n);

    cout << "After Eleminating first element of Array: ";
    remove_head(a, n);
    show(a, n);

    cout << "After Eleminating last element of Array: ";
    remove_tail(a, n);
    show(a, n);

    cout <<  "After Eleminating 2th element of Array: ";
    remove_any_pos(a, n, 1);
    show(a, n);

    cout << "After asigning new value 1000000 for 4th elemnet ";
    change_value(a, n, 3, 1000000);
    show(a, n);


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

bool checkArrLength()
{
    return n < MAX_ARR_LEN;
}

void add_head(int a[], int val, int &n)
{
    if (!checkArrLength())
    {
        cout << "Can not add more element into array\n";
        return;
    }
    for (int i = n; i > 0; --i)
        a[i] = a[i-1];
    a[0] = val;
    ++n;
}

void add_tail(int a[], int val, int &n)
{
    if (!checkArrLength())
    {
        cout << "Can not add more element into array\n";
        return;
    }
    a[n] = val;
    ++n;
}

void add_any_pos(int a[], int val, int &n, int k)
{
     if (!checkArrLength())
    {
        cout << "Can not add more element into array\n";
        return;
    }
    if (k > n || k < 0)
    {
        cout << "Can not find the valid position to add an element into array\n";
        return;
    }
    for (int i = n; i > k; --i)
        a[i] = a[i-1];
    a[k] = val;
    ++n;
}


bool isEmpty()
{
    return n == 0;
}

void remove_head(int a[], int &n)
{
    if (isEmpty())
        cout << "Array is empty!\n";
    else
    {
        for (int i = 0; i < n-1; ++i)
            a[i] = a[i+1];
        --n;
    }
}

void remove_tail(int a[], int &n)
{
    if (isEmpty())
        cout << "Array is empty!\n";
    else
    {
        --n;
    }
}

void remove_any_pos(int a[], int &n, int k)
{
    if (isEmpty())
        cout << "Array is empty!\n";
    else
    {
        if (k > n || k < 0)
        {
            cout << "Can not find the valid position to add an element into array\n";
            return;
        }
        for (int i = k; i < n-1; ++i)
            a[i] = a[i+1];
        --n;
    }
}

void change_value(int a[], int n, int k, int val)
{
     if (!checkArrLength())
    {
        cout << "Can not add more element into array\n";
        return;
    }
    if (k > n || k < 0)
    {
        cout << "Can not find the valid position to add an element into array\n";
        return;
    }
    a[k] = val;
}

