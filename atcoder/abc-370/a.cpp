#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
#define all(x) x.begin(), x.end()
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a, b;
    cin >> a >> b;
    if (a && !b)
        cout << "Yes";
    else if (!a && b)
        cout << "No";
    else
        cout << "Invalid";
    return 0;
}