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
const ll INF=(ll)1e18;
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
    if(v>0) tree[node]={v,v,v,v};
    else tree[node]={0,0,v,0};
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n1,n2;
  vector<ll> xrr,yrr;
  cin>>n1;
  vector<pair<pll,ll>> ball;
  for(int i=0; i<n1; i++)
  {
    ll a,b;
    cin>>a>>b;
    ball.pb({{a,b},1});
    xrr.pb(a); yrr.pb(b);
  }
  cin>>n2;
  for(int i=0; i<n2; i++)
  {
    ll a,b;
    cin>>a>>b;
    ball.pb({{a,b},-1});
    xrr.pb(a); yrr.pb(b);
  }
  ll v1,v2;
  cin>>v1>>v2;
  for(auto& x:ball) x.S=(x.S==1)?v1:-v2;
  sort(all(ball));
  sort(all(xrr)); xrr.erase(unique(all(xrr)),xrr.end());
  sort(all(yrr)); yrr.erase(unique(all(yrr)),yrr.end());
  for(auto& p:ball)
  {
    p.F.F=lower_bound(all(xrr),p.F.F)-xrr.begin();
    p.F.S=lower_bound(all(yrr),p.F.S)-yrr.begin();
  }
  ll ans=0;
  ll m=yrr.size();
  for(int i=0; i<n1+n2; i++)
  {
    for(int j=0; j<4*(n1+n2); j++) tree[j]={0,0,0,0};
    for(int j=i; j<n1+n2; j++)
    {
      upd(1,0,m-1,ball[j].F.S,ball[j].S);
      ans=max(ans,query(1,0,m-1,0,m-1).sa);

    }
  }
  cout<<ans<<endl;
  return 0;
}