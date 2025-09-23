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
ll arr[200005];
Node tree[800005];
inline Node f(Node a,Node b)
{
  return {max(a.sl,a.ss+b.sl),max(b.sr,a.sr+b.ss),a.ss+b.ss,max({a.sa,b.sa,a.sr+b.sl})};
}
Node init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]={arr[st],arr[st],arr[st],arr[st]};
  ll mid=(st+en)>>1;
  return tree[node]=f(init(node<<1,st,mid),init(node<<1|1,mid+1,en));
}
void upd(ll node,ll st,ll en,ll idx,ll v)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    arr[st]+=v;
    tree[node]={arr[st],arr[st],arr[st],arr[st]};
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
  ll n,m,k,d;
  cin>>n>>m>>k>>d;
  for(int i=0; i<n; i++) arr[i]=-k;
  init(1,0,n-1);
  while(m--)
  {
    ll a,b;
    cin>>a>>b;
    upd(1,0,n-1,a-1,b);
    if(query(1,0,n-1,0,n-d-1).sa<=k*d && query(1,0,n-1,n-d-1,n-1).ss<=0) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;
  }
  return 0;
}