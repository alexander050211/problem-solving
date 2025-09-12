#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const ll INF=-(ll)1e17;
ll arr[400005];
struct Node
{
  ll mn,mx;
  ll ab,ba,aba;
};
Node tree[1200005];
Node f(Node a,Node b)
{
  return {min(a.mn,b.mn),max(a.mx,b.mx),
    max({a.ab,b.ab,b.mx-a.mn}),max({a.ba,b.ba,a.mx-b.mn}),max({a.aba,b.aba,a.ab-b.mn,b.ba-a.mn})};
}
Node init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]={arr[st],arr[st],INF,INF,INF};
  ll mid=(st+en)>>1;
  return tree[node]=f(init(node<<1,st,mid),init(node<<1|1,mid+1,en));
}
void update(ll node,ll st,ll en,ll idx,ll v)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    tree[node]={v,v,INF,INF,INF};
    return;
  }
  ll mid=(st+en)>>1;
  update(node<<1,st,mid,idx,v); update(node<<1|1,mid+1,en,idx,v);
  tree[node]=f(tree[node<<1],tree[node<<1|1]);
}
Node query(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return {-INF,INF,INF,INF,INF};
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return f(query(node<<1,st,mid,l,r),query(node<<1|1,mid+1,en,l,r));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,q;
  cin>>n>>q;
  for(int i=1; i<=n; i++) cin>>arr[i];
  init(1,1,n);
  while(q--)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    if(a==1) update(1,1,n,b,c);
    else cout<<query(1,1,n,b,c).aba<<endl;
  }
  return 0;
}