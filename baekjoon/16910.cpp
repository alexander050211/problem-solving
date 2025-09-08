#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
pair<ll,pll> arr[100005];
ll tree[1600005];
pll lazy[1600005];
void update_lazy(ll node,ll st,ll en)
{
  pll t=lazy[node],zero={1,0};
  if(t==zero) return;
  tree[node]=tree[node]*t.F+(en-st+1)*t.S;
  if(st!=en)
  {
    pll t1=lazy[node<<1],t2=lazy[node<<1|1];
    lazy[node<<1]={t1.F*t.F,t.F*t1.S+t.S};
    lazy[node<<1|1]={t2.F*t.F,t.F*t2.S+t.S};
  }
  lazy[node]=zero;
}
void update_range(ll node,ll st,ll en,ll l,ll r,pll val)
{
  update_lazy(node,st,en);
  if(r<st || en<l) return;
  if(l<=st && en<=r)
  {
    tree[node]=tree[node]*val.F+(en-st+1)*val.S;
    if(st!=en)
    {
      pll t1=lazy[node<<1],t2=lazy[node<<1|1];
      lazy[node<<1]={t1.F*val.F,val.F*t1.S+val.S};
      lazy[node<<1|1]={t2.F*val.F,val.F*t2.S+val.S};
    }
    return;
  }
  ll mid=(st+en)>>1;
  update_range(node<<1,st,mid,l,r,val); update_range(node<<1|1,mid+1,en,l,r,val);
  tree[node]=tree[node<<1]+tree[node<<1|1];
}
ll tquery(ll node,ll st,ll en,ll l,ll r)
{
  update_lazy(node,st,en);
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree[node];
  ll mid=(st+en)>>1;
  return tquery(node<<1,st,mid,l,r)+tquery(node<<1|1,mid+1,en,l,r);
}
ll query(ll st,ll en,ll m)
{
  if(st==en)
  {
    if(tquery(1,1,m,st,st)) return st+1;
    return st;
  }
  ll mid=(st+en)>>1;
  ll temp=tquery(1,1,m,st,mid);
  if(temp==(mid-st+1)) return query(mid+1,en,m);
  return query(st,mid,m);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i].F>>arr[i].S.F>>arr[i].S.S;
  vector<ll> brr=vector<ll>(n<<1);
  for(int i=0; i<n; i++) brr[i<<1]=arr[i].S.F,brr[i<<1|1]=arr[i].S.S;
  brr.emplace_back(1);
  sort(all(brr));
  brr.erase(unique(all(brr)),brr.end());
  auto crr=brr;
  crr[0]=1;
  for(int i=1; i<crr.size(); i++)
  {
    if(brr[i]==brr[i-1]+1) crr[i]=crr[i-1]+1;
    else crr[i]=crr[i-1]+2;
  }
  ll m=crr.back();
  for(int i=1; i<=4*m; i++) lazy[i]={1,0};
  for(int i=0; i<n; i++)
  {
    arr[i].S.F=crr[lower_bound(all(brr),arr[i].S.F)-brr.begin()];
    arr[i].S.S=crr[lower_bound(all(brr),arr[i].S.S)-brr.begin()];
  }
  for(int i=0; i<n; i++)
  {
    if(arr[i].F==1) update_range(1,1,m,arr[i].S.F,arr[i].S.S,{0,1});
    else if(arr[i].F==2) update_range(1,1,m,arr[i].S.F,arr[i].S.S,{0,0});
    else if(arr[i].F==3) update_range(1,1,m,arr[i].S.F,arr[i].S.S,{-1,1});
    ll temp=query(1,m,m);
    if(temp==m+1) cout<<brr.back()+1<<endl;
    else
    {
      ll idx=lower_bound(all(crr),temp)-crr.begin();
      if(crr[idx]==temp) cout<<brr[idx]<<endl;
      else cout<<brr[idx-1]+1<<endl;
    }
  }
  return 0;
}