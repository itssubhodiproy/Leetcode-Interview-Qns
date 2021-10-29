#include <iostream>
using namespace std;
int arr[1000];

int stair(int n)
{

    if (arr[n] != 0)
    {
        return arr[n];
    }

    if (n <= 2)
    {
        arr[n] = n;
        return n;
    }

    arr[n] = stair(n - 1) + stair(n - 2);
    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << stair(n) << endl;
    return 0;
}
