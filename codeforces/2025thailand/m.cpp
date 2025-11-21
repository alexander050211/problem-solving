#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll arr[200005],pos[200005],tree[800005];
ll init(ll node,ll st,ll en) {
  if(st==en) return tree[node]=arr[st];
  ll mid=(st+en)>>1;
  return tree[node]=init(node<<1,st,mid)+init(node<<1|1,mid+1,en);
}
void upd(ll node,ll st,ll en,ll idx) {
  if(idx<st || en<idx) return;
  if(st==en) {
    arr[idx]=tree[node]=0;
    return;
  }
  ll mid=(st+en)>>1;
  upd(node<<1,st,mid,idx); upd(node<<1|1,mid+1,en,idx);
  tree[node]=tree[node<<1]+tree[node<<1|1];
}
ll query(ll node,ll st,ll en,ll l,ll r) {
  if(l>r) return 0;
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return query(node<<1,st,mid,l,r)+query(node<<1|1,mid+1,en,l,r);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  for(int i=0; i<n; i++) arr[i]=1;
  for(int i=0; i<n; i++) {
    ll a;
    cin>>a;
    pos[a]=i;
  }
  init(1,0,n);
  vector<ll> ans(n,0);
  ll nxt=n;
  for(int i=n; i>0; i--) {
    ll temp=pos[i];
    if(temp<nxt) ans[i-1]=query(1,0,n,temp+1,nxt-1)+1;
    else ans[i-1]=query(1,0,n,0,n)-query(1,0,n,nxt,temp)+1;
    upd(1,0,n,temp);
    nxt=temp+1;
  }
  for(auto x:ans) cout<<x<<' ';
  cout<<endl;
  return 0;
}