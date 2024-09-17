#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
#define all(x) x.begin(), x.end()
vector<ll> arr;
ll n;
bool sieve[10005], brr[10005];
void init()
{
    for (int i = 2; i <= 10000; i++)
        sieve[i] = true;
    for (int i = 2; i <= 10000; i++)
    {
        if (!sieve[i])
            continue;
        for (int j = 2 * i; j <= 10000; j += i)
            sieve[j] = false;
    }
}
ll f(ll x)
{
    ll ret = 0;
    for (int i = 2; i <= 10000; i++)
    {
        if (i > x)
            break;
        if (!sieve[i])
            continue;
        while (x % i == 0)
        {
            ret++;
            x /= i;
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    init();
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 2; i <= 10000; i++)
        brr[i] = f(i);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans ^= brr[arr[i]];
    if (ans)
        cout << "Anna";
    else
        cout << "Bruno";
    return 0;
}