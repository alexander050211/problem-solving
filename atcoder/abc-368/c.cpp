#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ll t = x / 5;
        ans += t * 3;
        if (ans % 3 == 0)
        {
            if (x % 5 > 2)
                ans += 3;
            else if (x % 5 == 2)
                ans += 2;
            else if (x % 5 == 1)
                ans++;
        }
        else if (ans % 3 == 1)
        {
            if (x % 5 == 1)
                ans++;
            else if (x % 5)
                ans += 2;
        }
        else
        {
            if (x % 5 < 4)
                ans++;
            else if (x % 5 == 4)
                ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}