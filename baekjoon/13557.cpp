#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18;
struct Node
{
  ll sl,sr,ss,sa;
};
ll arr[100005];
Node tree[400005];
inline Node f(Node a,Node b)
{
  return {max(a.sl,a.ss+b.sl),max(b.sr,b.ss+a.sr),a.ss+b.ss,max({a.sa,b.sa,a.sr+b.sl})};
}
Node init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]={arr[st],arr[st],arr[st],arr[st]};
  ll mid=(st+en)>>1;
  return tree[node]=f(init(node<<1,st,mid),init(node<<1|1,mid+1,en));
}
Node query(ll node,ll st,ll en,ll l,ll r)
{
  if(r<l) return {-INF,-INF,0,-INF};
  if(r<st || en<l) return {-INF,-INF,0,-INF};
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return f(query(node<<1,st,mid,l,r),query(node<<1|1,mid+1,en,l,r));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i];
  init(1,0,n-1);
  ll q;
  cin>>q;
  while(q--)
  {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(b<=c)
    {
      ll ans=query(1,0,n-1,b-1,c-1).ss;
      if(a<b) ans=max(ans,ans+query(1,0,n-1,a-1,b-2).sr);
      if(c<d) ans=max(ans,ans+query(1,0,n-1,c,d-1).sl);
      cout<<ans<<endl;
    }
    else
    {
      Node t1=query(1,0,n-1,a-1,c-2),t2=query(1,0,n-1,c-1,b-1),t3=query(1,0,n-1,b,d-1);
      ll ans=max({t2.sa,t2.sr+t3.sl,t1.sr+t2.sl,t1.sr+t2.ss+t3.sl});
      cout<<ans<<endl;
    }
  }
  return 0;
}