#include <bits/stdc++.h>
using namespace std;
#define int long long int

int a[200005], x[200005], y[200005], dp[200005][2];
int n;
int kk(int ind, int turn, int next)
{
    if (ind == n-1) return next * a[n-1];
    if (dp[ind][turn] != -1) return dp[ind][turn];

    int ans1 = next * x[ind] + kk(ind + 1, 0, y[ind]);
    int ans2 = next * y[ind] + kk(ind + 1, 1, x[ind]);
    return dp[ind][turn] = min(ans1, ans2);
}
void solve()
{
    int s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (s >= a[i])
            x[i] = 0, y[i] = a[i];
        else
        {
            x[i] = min(s, a[i] - s);
            y[i] = max(s, a[i] - s);
        }
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    int ans1 = a[0] * x[1] + kk(2, 0, y[1]);
    int ans2 = a[0] * y[1] + kk(2, 1, x[1]);
    cout << min(ans1, ans2);
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