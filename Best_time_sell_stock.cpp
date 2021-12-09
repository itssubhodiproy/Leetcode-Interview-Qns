#include <bits/stdc++.h>
using namespace std;

// o- based indexing code
int best_time_bruteforce(int arr[], int n)         //  <<<<<-----Bruteforce------->>>>>
{
	// int n = sizeof (arr) / sizeof (arr[0]);
	int maxi = INT_MIN;
	int total_max = INT_MIN;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			maxi = max(maxi, arr[j] - arr[i]);
		}
		total_max = max(maxi, total_max);
	}
	return total_max;
}

int optimized(int arr[], int n)                   //   <<<<<<---------Optimized-------->>>>>>>
{
	int min_num = INT_MAX;
	int max_profit = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		min_num = min(min_num, arr[i]);
		max_profit = max(max_profit, arr[i] - min_num);
	}
	return max_profit;
}

// { Driver Code Starts.
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int arr[] = {5, 4, 11, 1, 16, 9};
		// cout << best_time_bruteforce(arr, 6) << "\n";
		cout << optimized(arr, 6) << "\n";
	}
	return 0;
} // } Driver Code Ends
