#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define all(v) v.begin(), v.end()

bool pos(vi &v, int mid, int k, int n)
{
    int req = 0;
    for (int i = n / 2; i < n; i++)
    {
        if (v[i] >= mid) break;
        
        req += mid - v[i];
    }
    return (k >= req);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));

    int l = a[n / 2], h = 2e9, res;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (pos(a, mid, k, n))
        {
            l = mid + 1;
            res = mid;
        }
        else h = mid - 1;
    }
    cout << res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    // cin >> testcases;
    while (testcases--)
    {
        solve();
        cout << endl;
    }
    return 0;
}