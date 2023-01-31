#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define vi vector<int>

// int fun(int ind, int state, vector<vi> &dp, vi &a)
// {
//     if (ind < 0)
//         return 0;
//     if (dp[ind][state] != -1)
//         return dp[ind][state];

//     if (a[ind] == 0 || a[ind] == state)
//         return dp[ind][state] = 1 + fun(ind - 1, 0, dp, a);

//     else if (a[ind] == 1)
//     {
//         return dp[ind][state] = fun(ind - 1, 1, dp, a);
//     }
//     else if (a[ind] == 2)
//     {
//         return dp[ind][state] = fun(ind - 1, 2, dp, a);
//     }
//     else
//     {
//         int contest = fun(ind - 1, 1, dp, a);
//         int gym = fun(ind - 1, 2, dp, a);
//         int ans;
//         if (state == 1)
//             ans = min(10000000 * 1ll, gym);
//         else
//             ans = min(10000000 * 1ll, contest);
//         return dp[ind][ans] = ans;
//     }
// }
int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vi pre(3, 0), curr(3, 0);

    for (int i = 1; i <= n; i++)
    {
        curr[0] = min(pre[0], min(pre[1], pre[2])) + 1;
        if (a[i] == 0)
        {
            curr[1] = 1 + pre[1];
            curr[2] = 1 + pre[2];
        }
        else if (a[i] == 1)
        {
            curr[1] = min(pre[0], pre[2]);
            curr[2] = 1 + pre[2];
        }
        else if (a[i] == 2)
        {
            curr[1] = 1 + pre[1];
            curr[2] = min(pre[0], pre[1]);
        }
        else if (a[i] == 3)
        {
            curr[1] = min(pre[0], pre[2]);
            curr[2] = min(pre[0], pre[1]);
        }
        //cout << curr[0] << " " << curr[1] << " " << curr[2] << endl;
        pre = curr;
    }
    cout << min(pre[0], min(pre[1], pre[2]));
}