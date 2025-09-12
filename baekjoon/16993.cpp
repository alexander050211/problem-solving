#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
struct Node
{
  ll ls,rs,as,ss;
};
const ll INF=(ll)1e15;
ll arr[100005];
Node tree[400005];
Node f(Node a,Node b)
{
  return {max(a.ls,a.ss+b.ls),max(b.rs,a.rs+b.ss),max({a.as,b.as,a.rs+b.ls}),a.ss+b.ss};
}
Node init(ll node,ll st,ll en)
{
  if(st==en) return tree[node]={arr[st],arr[st],arr[st],arr[st]};
  ll mid=(st+en)>>1;
  return tree[node]=f(init(node<<1,st,mid),init(node<<1|1,mid+1,en));
}
Node query(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return {-INF,-INF,-INF,0};
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return f(query(node<<1,st,mid,l,r),query(node<<1|1,mid+1,en,l,r));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  init(1,1,n);
  ll q;
  cin>>q;
  while(q--)
  {
    ll a,b;
    cin>>a>>b;
    cout<<query(1,1,n,a,b).as<<endl;
  }
  return 0;
}