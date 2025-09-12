#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll tree[400005];
void update(ll node,ll st,ll en,ll idx,ll v)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    tree[node]+=v;
    return;
  }
  ll mid=(st+en)>>1;
  update(node<<1,st,mid,idx,v); update(node<<1|1,mid+1,en,idx,v);
  tree[node]=tree[node<<1]+tree[node<<1|1];
}
ll query(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return query(node<<1,st,mid,l,r)+query(node<<1|1,mid+1,en,l,r);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll tc;
  cin>>tc;
  while(tc--)
  {
    ll n,m;
    cin>>n>>m;
    vector<pll> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i].S>>arr[i].F;
    sort(all(arr));
    for(auto& x:arr) swap(x.F,x.S);
    vector<pair<pll,pll>> brr;
    for(int i=0; i<m; i++)
    {
      ll a,b,c,d;
      cin>>a>>b>>c>>d;
      brr.pb({{c,1},{a,b}});
      brr.pb({{d+1,-1},{a,b}});
    }
    sort(all(brr));
    ll ans=0;
    ll idx=0;
    for(int i=0; i<n; i++)
    {
      while(idx<2*m && brr[idx].F.F<=arr[i].S)
      {
        update(1,0,100000,brr[idx].S.F,brr[idx].F.S);
        if(brr[idx].S.S<100000) update(1,0,100000,brr[idx].S.S+1,-brr[idx].F.S);
        idx++;
      }
      ans+=query(1,0,100000,0,arr[i].F);
    }
    cout<<ans<<endl;
    for(int i=0; i<=400000; i++) tree[i]=0;
  }
  return 0;
}