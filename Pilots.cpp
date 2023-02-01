#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define vi vector<int>
int dp[5005][5005];
int fun(int c, int p, int t, vector<vi> &a)
{
    if (c + p == t + t) return dp[c][p] = 0;
 
    if (dp[c][p] != -1) return dp[c][p];
 
    int cap = a[c + p][0];
    int pilot = a[c + p][1];
 
    if (c >= p)
        return dp[c][p] = pilot + fun(c, p + 1, t, a);
    if (p == t)
        return dp[c][p] = cap + fun(c + 1, p, t, a);
 
    int op1 = cap + fun(c + 1, p, t, a);
    int op2 = pilot + fun(c, p + 1, t, a);
    return dp[c][p] = min(op1, op2);
}
int32_t main()
{
    int n;
    cin >> n;
    vector<vi> a(n, vi(2));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    memset(dp, -1, sizeof(dp));
    cout << fun(0, 0, n / 2, a)<<endl;
    return 0;
}