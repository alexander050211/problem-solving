#include <bits/stdc++.h>
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
struct Fenwick
{
  ll sz;
  vector<ll> bit;
  void init(ll x) { sz=x+1; bit.assign(sz+1,0); }
  void add(ll x,ll v)
  {
    ll temp=(v%mod+mod)%mod;
    for(int i=x+1; i<=sz; i+=i&-i)
    {
      bit[i]+=temp;
      if(bit[i]>=mod) bit[i]-=mod;
    }
  }
  ll sum(ll x)
  {
    if(x<0) return 0;
    ll ret=0;
    for(int i=x+1; i>0; i-=i&-i)
    {
      ret+=bit[i];
      if(ret>=mod) ret-=mod;
    }
    return ret;
  }
  ll query(ll l,ll r)
  {
    if(r<l) return 0;
    ll ret=sum(r)-sum(l-1);
    if(ret<0) ret+=mod;
    return ret;
  }
};
void solve()
{
  ll n;
  cin>>n;
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  vector<Fenwick> fx(n+1),fy(n+1);
  for(int i=0; i<=n; i++)
  {
    fx[i].init(n);
    fy[i].init(n);
  }
  fx[0].add(0,1); fy[0].add(0,1);
  for(int i=0; i<n; i++)
  {
    for(int y=0; y<=arr[i]; y++)
    {
      ll val=fx[y].query(y,arr[i]);
      if(val)
      {
        fx[y].add(arr[i],val);
        fy[arr[i]].add(y,val);
      }
    }
    for(int x=arr[i]+1; x<=n; x++)
    {
      ll val=fy[x].sum(arr[i]);
      if(val)
      {
        fx[arr[i]].add(x,val);
        fy[x].add(arr[i],val);
      }
    }
  }
  ll ans=0;
  for(int y=0; y<=n; y++) ans=(ans+fx[y].sum(n))%mod;
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