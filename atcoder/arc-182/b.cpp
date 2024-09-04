#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll temp = (1 << k) - 1;
    for (int i = 0; i < n; i++)
    {
        if ((ll)i >= (ll)(1 << (k - 1)))
        {
            cout << "1 ";
            continue;
        }
        ll ret = temp;
        for (int j = 0; j < k; j++)
        {
            if ((i >> j) & 1)
                ret ^= (1 << (k - j - 2));
        }
        cout << ret << ' ';
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}