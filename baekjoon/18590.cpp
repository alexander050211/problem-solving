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
struct Node
{
  ll sl,sr,ss,sa;
};
Node tree[8005];
inline Node f(Node a,Node b)
{
  return {max(a.sl,a.ss+b.sl),max(b.sr,b.ss+a.sr),a.ss+b.ss,max({a.sa,b.sa,a.sr+b.sl})};
}
void upd(ll node,ll st,ll en,ll idx,ll v)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    ll temp=tree[node].ss+v;
    tree[node]={temp,temp,temp,temp};
    return;
  }
  ll mid=(st+en)>>1;
  upd(node<<1,st,mid,idx,v); upd(node<<1|1,mid+1,en,idx,v);
  tree[node]=f(tree[node<<1],tree[node<<1|1]);
}
Node query(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return {-INF,-INF,0,-INF};
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return f(query(node<<1,st,mid,l,r),query(node<<1|1,mid+1,en,l,r));
}
void solve()
{
  ll n;
  cin>>n;
  vector<pair<pll,ll>> arr;
  vector<ll> xrr,yrr;
  for(int i=0; i<n; i++)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    xrr.pb(a); yrr.pb(b);
    arr.pb({{a,b},c});
  }
  sort(all(xrr)); xrr.erase(unique(all(xrr)),xrr.end());
  sort(all(yrr)); yrr.erase(unique(all(yrr)),yrr.end());
  for(auto& p:arr)
  {
    p.F.F=lower_bound(all(xrr),p.F.F)-xrr.begin();
    p.F.S=lower_bound(all(yrr),p.F.S)-yrr.begin();
  }
  sort(all(arr));
  ll m1=xrr.size(),m2=yrr.size();
  ll ans=0;
  for(int i=0; i<m1; i++)
  {
    ll idx=0;
    while(arr[idx].F.F<i) idx++;
    for(int j=0; j<4*n; j++) tree[j]={0,0,0,0};
    for(int j=idx; j<n; j++)
    {
      upd(1,0,m2-1,arr[j].F.S,arr[j].S);
      if(j==n-1 || arr[j].F.F<arr[j+1].F.F) ans=max(ans,query(1,0,m2-1,0,m2-1).sa);
    }
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