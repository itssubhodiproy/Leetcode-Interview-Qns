#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxcount = 1;

    for (int i = 0; i < n - 1; i++)
    {
        int maxi = arr[i];
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > maxi)
            {
                count++;
                maxi = arr[j];
            }
        }
        maxcount = max(maxcount, count);
    }

    cout << maxcount << endl;
    return 0;
}