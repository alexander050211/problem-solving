#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
vector<pair<ll, pll>> arr;
ll n, m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        arr.push_back({c, {a, b}});
    }

    return 0;
}