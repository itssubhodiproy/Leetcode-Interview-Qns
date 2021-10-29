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
    int maxcount = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int maxi = arr[i];
        int count = 1;
        for (int j = i; j < n; j++)
        {
            if (arr[j] > maxi)
            {
                maxi = arr[j];
                count++;
            }
        }
        maxcount = max(maxcount, count);
    }
    cout << maxcount << endl;
    return 0;
}
