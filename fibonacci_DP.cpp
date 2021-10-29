#include <iostream>
using namespace std;
int arr[1000];

int fib(int n)
{
    if (arr[n] != 0)
    {
        return arr[n];
    }
    if (n <= 1)
    {
        arr[n] = n;
        return arr[n];
    }

    arr[n] = fib(n - 1) + fib(n - 2);

    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
