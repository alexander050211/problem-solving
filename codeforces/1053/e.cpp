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
  ll n;
  cin>>n;
  vector<ll> arr(n),brr(n),crr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  for(int i=0; i<n; i++) cin>>brr[i];
  for(int i=0; i<n; i++) cin>>crr[i];
  vector<ll> pos(n+1);
  for(int i=0; i<n; i++) pos[crr[i]]=i+1;
  vector<ll> p(n+1);
  for(int i=0; i<n; i++) p[i+1]=pos[brr[i]];
  ll ans=0;
  vector<bool> visited(n+1,false);
  auto f=[&](const vector<ll>& vrr)->ll{
    if(vrr.empty()) return 0;
    ll tmax=-INF,mmax=0;
    for(auto x:vrr)
    {
      mmax+=x;
      tmax=max(tmax,mmax);
      if(mmax<0) mmax=0;
    }
    if(tmax==-INF)
    {
      ll ret=-INF;
      for(auto x:vrr) ret=max(ret,x);
      return ret;
    }
    ll sum=0;
    ll tmin=INF,mmin=0;
    for(auto x:vrr)
    {
      sum+=x;
      mmin+=x;
      tmin=min(tmin,mmin);
      if(mmin>0) mmin=0;
    }
    if(tmin==sum) return tmax;
    return max(tmax,sum-tmin);
  };
  for(int i=1; i<=n; i++)
  {
    if(visited[i]) continue;
    vector<ll> cycle;
    ll idx=i;
    while(!visited[idx])
    {
      visited[idx]=true;
      cycle.pb(arr[brr[idx-1]-1]);
      idx=p[idx];
    }
    ll temp=f(cycle);
    ans+=(temp>0)?temp:0;
  }
  cout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll tt=1;
  cin>>tt;
  while(tt--)
  {
    solve();
  }
  return 0;
}