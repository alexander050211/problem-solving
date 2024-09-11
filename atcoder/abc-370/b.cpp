#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
#define all(x) x.begin(), x.end()
ll n;
int arr[105][105];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ret = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= n; i++)
    {
        ll temp = arr[max(ret, i)][min(ret, i)];
        ret = temp;
    }
    cout << ret << endl;
    return 0;
}