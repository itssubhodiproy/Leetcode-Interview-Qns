#include <bits/stdc++.h>
using namespace std; //------>>>>> It has some edgecases, so don't consider it as final solution//
                            // I approach it using basic nested for-loop and with a little help of stack//
int main()
{
    int n, w;
    cin >> n >> w;
    int weight[n];
    int value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int sum1 = 0;
        int sum2 = 0;
        for (int j = 0; j < n; j++)
        {
            sum1 += weight[j];
            if (sum1 > w)
            {
                sum1 -= weight[j];
                continue;
            }
            sum2 += value[j];
            st.push(sum2);
        }
    }
    int maxi = INT_MIN;
    while (!st.empty())
    {
        maxi = max(st.top(), maxi);
        st.pop();
    }

    cout << maxi << endl;
    return 0;
}
