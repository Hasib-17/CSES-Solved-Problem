// بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long int
#define ul unsigned long long
#define dec greater<int>()
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
void solve()
{
    int n, q;
    cin >> n >> q;
    int m[n][30];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[i][0] = a;
    }
    // processing...
    for (int j = 1; j <= 30; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int len = r - l + 1;
        int j = 0;
        while (1 << (j + 1) <= len)
            j++;
        int ans = min(m[l][j], m[r - (1 << j) + 1][j]);
        cout << ans << '\n';
    }
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
