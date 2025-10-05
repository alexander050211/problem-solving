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
inline ll f(const array<vector<ll>,3>& pref,ll l,ll r)
{
  if(l>r) return 0;
  ll c=l%3;
  return pref[c][r]-(l?pref[c][l-1]:0);
}
void solve()
{
  ll n,q;
  cin>>n>>q;
  vector<ll> arr(n+1);
  for(int i=1; i<=n; i++) cin>>arr[i];
  vector<ll> zrr,orr;
  for(int i=1; i<=n; i++)
  {
    if(arr[i]) orr.pb(i);
    else zrr.pb(i);
  }
  vector<ll> f0,f1;
  if(zrr.size()>=3)
  {
    f0.resize(zrr.size()-2);
    for(int i=0; i<zrr.size()-2; i++) f0[i]=min(zrr[i+1]-zrr[i],zrr[i+2]-zrr[i+1]);
  }
  if(orr.size()>=3)
  {
    f1.resize(orr.size()-2);
    for(int i=0; i<orr.size()-2; i++) f1[i]=min(orr[i+1]-orr[i],orr[i+2]-orr[i+1]);
  }
  array<vector<ll>,3> pre0,pre1;
  for(int i=0; i<3; i++)
  {
    pre0[i].assign(f0.size(),0);
    pre1[i].assign(f1.size(),0);
  }
  for(int i=0; i<f0.size(); i++)
  {
    for(int j=0; j<3; j++) pre0[j][i]=(i?pre0[j][i-1]:0);
    pre0[i%3][i]+=f0[i];
  }
  for(int i=0; i<f1.size(); i++)
  {
    for(int j=0; j<3; j++) pre1[j][i]=(i?pre1[j][i-1]:0);
    pre1[i%3][i]+=f1[i];
  }
  while(q--)
  {
    ll l,r;
    cin>>l>>r;
    ll l0=lower_bound(all(zrr),l)-zrr.begin();
    ll r0=upper_bound(all(zrr),r)-zrr.begin()-1;
    ll c0=(l0<=r0?r0-l0+1:0);
    
    ll l1=lower_bound(all(orr),l)-orr.begin();
    ll r1=upper_bound(all(orr),r)-orr.begin()-1;
    ll c1=(l1<=r1?r1-l1+1:0);
    if(c0%3 || c1%3)
    {
      cout<<-1<<endl;
      continue;
    }
    ll t0=c0/3,t1=c1/3;
    ll s0=0,s1=0;
    if(c0>=3)
    {
      ll st0=l0;
      ll ls0=r0-2;
      if(!f0.empty())
      {
        ls0=min(ls0,(ll)f0.size()-1);
        if(st0<=ls0) s0=f(pre0,st0,ls0);
      }
    }
    if(c1>=3)
    {
      ll st1=l1;
      ll ls1=r1-2;
      if(!f1.empty())
      {
        ls1=min(ls1,(ll)f1.size()-1);
        if(st1<=ls1) s1=f(pre1,st1,ls1);
      }
    }
    ll ans=min(s0+t1,s1+t0);
    cout<<ans<<endl;
  }
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