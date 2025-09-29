#include <bits/stdc++.h>
#define endl '\n'
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll mod=(ll)1e9+7;
const ll INF=(ll)4e18;

void solve() 
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    unordered_set<ll> black;
    black.reserve(m + 2*n + 16);
    for(int i = 0; i < m; ++i)
    {
      ll x;
      cin >> x;
      black.insert(x);
    }
    unordered_map<ll,ll> nxt;
    nxt.reserve(m + 2*n + 16);
    auto nwhite = [&](ll x) {
      vector<ll> path;
      ll y = x;
      while(black.count(y))
      {
        path.push_back(y);
        auto it = nxt.find(y);
        y =(it == nxt.end() ? y + 1 : it->second);
      }
      for(ll v : path) nxt[v] = y;
      return y;
    };
    ll last=1;
    for(int i=0; i<n; ++i)
    {
      ll base;
      if(!i) base=1;
      else base =(s[i-1] == 'A')?last:nwhite(last + 1);
      ll pos =(s[i] == 'A') ?(base + 1) : nwhite(base + 1);
      if(black.insert(pos).second) nxt[pos] = pos + 1;
      last = pos;
    }
    vector<ll> out(black.begin(), black.end());
    sort(all(out));
    cout<<out.size()<<endl;
    for(ll v:out) cout<<v<<' ';
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tt=1;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}