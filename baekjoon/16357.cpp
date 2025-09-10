#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll tree[800005],lazy[800005];
void ulazy(ll node,ll st,ll en)
{
  if(!lazy[node]) return;
  tree[node]=max(tree[node],lazy[node]);
  if(st!=en)
  {
    lazy[node<<1]=max(lazy[node],lazy[node<<1]);
    lazy[node<<1|1]=max(lazy[node],lazy[node<<1|1]);
  }
  lazy[node]=0;
}
void urange(ll node,ll st,ll en,ll l,ll r,ll v)
{
  ulazy(node,st,en);
  if(r<st || en<l) return;
  if(l<=st && en<=r)
  {
    tree[node]=max(tree[node],v);
    if(st!=en)
    {
      lazy[node<<1]=max(v,lazy[node<<1]);
      lazy[node<<1|1]=max(v,lazy[node<<1|1]);
    }
    return;
  }
  ll mid=(st+en)>>1;
  urange(node<<1,st,mid,l,r,v); urange(node<<1|1,mid+1,en,l,r,v);
  tree[node]=max(tree[node<<1],tree[node<<1|1]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  vector<pll> arr(n);
  vector<ll> brr;
  for(int i=0; i<n; i++)
  {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    arr[i]={d,b};
    brr.pb(b); brr.pb(d);
  }
  std::sort(all(brr));
  brr.erase(unique(all(brr)),brr.end());
  for(auto& x:arr)
  {
    x.F=lower_bound(all(brr),x.F)-brr.begin();
    x.S=lower_bound(all(brr),x.S)-brr.begin();
  }
  ll m=brr.size();
  vector<pair<ll,pll>> crr;
  for(int i=0; i<n; i++)
  {
    crr.push_back({arr[i].F,{i,1}});
    crr.push_back({arr[i].S+1,{i,-1}});
  }
  std::sort(all(crr));
  ll temp=0,tmax=0,idx=0;
  for(int i=0; i<m-1; i++)
  {
    while(idx<crr.size() && crr[idx].F<=i)
    {
      
      temp+=crr[idx].S.S;
      tmax=max(tmax,temp);
      idx++;
    }
    urange(1,0,m-1,i+1,m-1,tmax);
  }
  return 0;
}