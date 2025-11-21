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
ll cp[2005];
ll fin(ll x)
{
  if(cp[x]==x) return x;
  return cp[x]=fin(cp[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m;
  cin>>n>>m;
  vector<pll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i].F>>arr[i].S;
  for(int i=0; i<n; i++) cp[i]=i;
  priority_queue<pair<ll,pll>> pq;
  auto dist=[&](ll a,ll b) {
    return (ll)pow(arr[a].F-arr[b].F,2)+pow(arr[a].S-arr[b].S,2);
  };
  for(int i=0; i<n; i++)for(int j=i+1; j<n; j++)if(dist(i,j)>=m) pq.push({-dist(i,j),{i,j}});
  ll ans=0;
  while(!pq.empty()) {
    auto [x,y]=pq.top();
    pq.pop();
    if(fin(y.F)==fin(y.S)) continue;
    ans-=x;
    cp[fin(y.F)]=fin(y.S);
  }
  for(int i=0; i<n; i++)for(int j=i+1; j<n; j++)if(fin(i)!=fin(j)) {
    cout<<-1<<endl;
    return 0;
  }
  cout<<ans<<endl;
  return 0;
}