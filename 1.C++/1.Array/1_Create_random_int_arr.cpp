#include <bits/stdc++.h>
using namespace std;

/// parameters
const int MAX_ARR_LEN = 10000;
int a[MAX_ARR_LEN]; // Array
int n; // Number of array elements

/// List of functions
void showarr(int a[], int n);

int main()
{
    ofstream f("array.txt"); /// Save array into text file
    int min_value, max_value; // Min, max value of array elemnents
    cout << "Enter number of array elements: ";
    cin >> n;
    f << n << '\n';
    do{
        cout << "Enter max value of array elements: ";
        cin >> max_value;
        cout << "Enter min value of array elements: ";
        cin >> min_value;
        if (max_value < min_value)
            cout << "Max must be greater than min value, re-enter!\n";
    } while (max_value < min_value);

    srand(time(nullptr));
    cout << "\n------------\nCreated Array: \n";
    for (int i = 0; i < n; ++i)
    {
        a[i] = rand()%(max_value-min_value+1)+min_value;
        f << a[i] << ' ';
    }
    f.close();

    // show arr
    showarr(a, n);

}

void showarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << endl;
}
