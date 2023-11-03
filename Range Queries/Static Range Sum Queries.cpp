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
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = v[i - 1] + prefix[i - 1];
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        ll ans = prefix[r] - prefix[l - 1];
        cout << ans << '\n';
    }
}

int main()
{
    fast;
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
