#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
struct Fenwick
{
  ll n;
  vector<ll> tree;
  Fenwick(ll n=0): n(n),tree(n+1,0) {}
  inline void add(ll i,ll val) { for(; i<=n; i+=i&-i)tree[i]+=val; }
  inline ll sum(ll i) { ll ret=0; for(; i>0; i-=i&-i)ret+=tree[i]; return ret; }
  inline ll query(ll l,ll r) { if(r<l) return 0; return sum(r)-sum(l-1); }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m;
  cin>>n>>m;
  ll sz=(ll)floor(sqrt(n));
  vector<ll> arr(n),crr(n);
  for(int i=0; i<n; i++)
  {
    cin>>arr[i];
    crr.push_back(arr[i]);
  }
  sort(all(crr));
  crr.erase(unique(all(crr)),crr.end());
  for(auto& x:arr) x=lower_bound(all(crr),x)-crr.begin();
  vector<pair<pll,ll>> brr(m);
  for(int i=0; i<m; i++)
  {
    ll a,b;
    cin>>a>>b;
    brr[i]={{a-1,b-1},i};
  }
  sort(all(brr),[&](const pair<pll,ll>& a,const pair<pll,ll>& b){
    ll ta=a.F.F/sz,tb=b.F.F/sz;
    return (ta==tb)?(a.F.S<b.F.S):(ta<tb);
  });
  Fenwick fw(n);
  vector<ll> ans(m,0);
  ll tans=0;
  auto f1=[&](ll x){
    tans+=fw.query(arr[x]+1,n);
    fw.add(arr[x],1);
  };
  auto f2=[&](ll x){
    fw.add(arr[x],-1);
    tans-=fw.query(arr[x]+1,n);
  };
  auto f3=[&](ll x){
    tans+=fw.query(0,arr[x]-1);
    fw.add(arr[x],1);
  };
  auto f4=[&](ll x){
    fw.add(arr[x],-1);
    tans-=fw.query(0,arr[x]-1);
  };
  ll st=brr[0].F.F,en=brr[0].F.S;
  for(int i=st; i<=en; i++) f1(i);
  ans[brr[0].S]=tans;
  for(int i=1; i<m; i++)
  {
    while(brr[i].F.F<st) f3(--st);
    while(en<brr[i].F.S) f1(++en);
    while(st<brr[i].F.F) f4(st++);
    while(brr[i].F.S<en) f2(en--);
    st=brr[i].F.F,en=brr[i].F.S;
    ans[brr[i].S]=tans;
  }
  for(auto x:ans) cout<<x<<endl;
  return 0;
}