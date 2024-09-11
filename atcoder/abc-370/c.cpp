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
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (s[i] != t[i]);
    vector<ll> temp(cnt, 0);
    cout << cnt << endl;
    ll st = 0, en = cnt - 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[i])
            continue;
        if (s[i] < t[i])
            temp[en--] = i;
        else
            temp[st++] = i;
    }
    for (int i = 0; i < cnt; i++)
    {
        s[temp[i]] = t[temp[i]];
        cout << s << endl;
    }
    return 0;
}