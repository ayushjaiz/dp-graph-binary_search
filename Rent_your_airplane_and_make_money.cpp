#include <bits/stdc++.h>
using namespace std;

struct job
{
    int start, end, profit;
};
bool compare(job i, job j)
{
    return i.end < j.end;
}
int curLatest(int index, job arr[])
{
    int low = 0, high = index - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid].end <= arr[index].start)
        {
            if (arr[mid + 1].end <= arr[index].start)
                low = mid + 1;

            else return mid;
        }
        else high = mid - 1;
    }
    return -1;
}
int maxProfit(job arr[], int n)
{
    vector<int> dp(n, 0);
    dp[0] = arr[0].profit;

    for (int i = 1; i < n; i++)
    {
        int take = arr[i].profit;

        int idx = curLatest(i, arr);
        if (idx != -1) take += dp[idx];

        int nottake = dp[i - 1];
        
        dp[i] = max(take, nottake);
    }
    return dp[n - 1];
}
void solve()
{
    int n, maxi;
    cin >> n;
    job arr[n];
    for (int i = 0; i < n; i++)
    {
        job curr;
        cin >> curr.start >> curr.end >> curr.profit;
        curr.end += curr.start;
        arr[i] = curr;
    }
    sort(arr, arr + n, compare);
    cout << maxProfit(arr, n);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    cin >> testcases;
    while (testcases--)
    {
        solve();
        cout << endl;
    }
    return 0;
}