#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,temp;
    cin >> n;
    vector<int> count(1e5, 0), dp(1e5, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        count[temp]++;
    }
    dp[1] = count[1];
    for (int i = 2; i <= 1e5; i++)
    {
        int ans1 = dp[i - 1];
        int ans2 = dp[i - 2] + i * count[i];

        dp[i] = max(ans1, ans2);
    }
    cout << dp[1e5];
    return 0;
}