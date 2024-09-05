#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++)
        cout << arr[i] << ' ';
    cout << x << ' ';
    for (int i = k; i < n; i++)
        cout << arr[i] << ' ';
    return 0;
}