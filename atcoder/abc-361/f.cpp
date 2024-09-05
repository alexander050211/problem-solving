#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
bool prime(ll x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
ll f(ll x)
{
    ll ret = 0;
    for (int i = 2; i <= x; i++)
        if (x % i == 0 && prime(i))
        {
            ret++;
            x /= i;
            if (x % i == 0)
                return -1;
        }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, ans = 1;
    cin >> n;

    for (int i = 2; i <= 60; i++)
    {
        ll temp = (ll)floor(pow(n, (double)1 / i)) - 1;
        if (f(i) == -1)
            continue;
        else if (f(i) % 2)
            ans += temp;
        else
            ans -= temp;
    }
    cout << ans << endl;
    return 0;
}