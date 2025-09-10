#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
struct Node
{
  ll ls,rs,as,sum;
};
Node tree[12005];
void update(ll node,ll st,ll en,ll idx,ll val)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    auto t=tree[node];
    tree[node]={t.ls+val,t.rs+val,t.as+val,t.sum+val};
    return;
  }
  ll mid=(st+en)>>1;
  update(node<<1,st,mid,idx,val); update(node<<1|1,mid+1,en,idx,val);
  auto t1=tree[node<<1],t2=tree[node<<1|1];
  tree[node]={max(t1.ls,t1.sum+t2.ls),max(t2.rs,t1.rs+t2.sum),max({t1.as,t2.as,t1.rs+t2.ls}),t1.sum+t2.sum};
}
Node query(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return {0,0,0,0};
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  auto t1=query(node<<1,st,mid,l,r),t2=query(node<<1|1,mid+1,en,l,r);
  return {max(t1.ls,t1.sum+t2.ls),max(t2.rs,t1.rs+t2.sum),max({t1.as,t2.as,t1.rs+t2.ls}),t1.sum+t2.sum};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  vector<pair<pll,ll>> arr(n);
  vector<ll> xrr,yrr;
  for(int i=0; i<n; i++)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    arr[i]={{a,b},c};
    xrr.pb(a); yrr.pb(b);
  }
  sort(all(xrr)); sort(all(yrr));
  xrr.erase(unique(all(xrr)),xrr.end()); yrr.erase(unique(all(yrr)),yrr.end());
  for(int i=0; i<n; i++) arr[i].F={lower_bound(all(xrr),arr[i].F.F)-xrr.begin(),lower_bound(all(yrr),arr[i].F.S)-yrr.begin()};
  ll m=xrr.size();
  ll ans=0;
  sort(all(arr),[&](const pair<pll,ll>& a,const pair<pll,ll>& b){
    return (a.F.S==b.F.S)?(a.F.F<b.F.F):(a.F.S<b.F.S);
  });
  for(int i=0; i<yrr.size(); i++)
  {
    ll idx=0;
    while(arr[idx].F.S<i) idx++;
    for(int j=i; j<yrr.size(); j++)
    {
      while(idx<n && arr[idx].F.S==j)
      {
        update(1,0,m-1,arr[idx].F.F,arr[idx].S);
        idx++;
      }
      ans=max(ans,query(1,0,m-1,0,m-1).as);
    }
    for(int j=0; j<4*m; j++) tree[j]={0,0,0,0};
  }
  cout<<ans<<endl;
  return 0;
}