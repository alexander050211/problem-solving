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
    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> g1(h), g2(w);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            g1[i].insert(j);
            g2[j].insert(i);
        }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if (g1[a].count(b))
        {
            g1[a].erase(b);
            g2[b].erase(a);
            continue;
        }
        auto it = g2[b].lower_bound(a);
        if (it != g2[b].begin())
        {
            g1[*prev(it)].erase(b);
            g2[b].erase(*prev(it));
        }
        it = g2[b].lower_bound(a);
        if (it != g2[b].end())
        {
            g1[*it].erase(b);
            g2[b].erase(*it);
        }
        it = g1[a].lower_bound(b);
        if (it != g1[a].begin())
        {
            g1[a].erase(*prev(it));
            g2[*prev(it)].erase(a);
        }
        it = g1[a].lower_bound(b);
        if (it != g1[a].end())
        {
            g1[a].erase(*it);
            g2[*it].erase(a);
        }
    }
    ll ans = 0;
    for (int i = 0; i < h; i++)
        ans += g1[i].size();
    cout << ans << endl;
    return 0;
}