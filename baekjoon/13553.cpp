#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define endl '\n'
#define F first
#define S second
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll cnt[100005],tree[400005],ans[100005];
ll tans,k;
struct Fenwick
{
  ll n;
  vector<ll> tree;
  Fenwick(ll n=0): n(n), tree(n+1,0) {}
  inline void add(ll i,ll val) { for(; i<=n; i+=i&-i)tree[i]+=val; }
  inline ll sum(ll i) { ll ret=0; for(; i>0; i-=i&-i)ret+=tree[i]; return ret; }
  inline ll query(ll l,ll r) { if(r<l) return 0; return sum(r)-sum(l-1); }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n>>k;
  ll rn=(ll)floor(sqrt(n));
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  ll q;
  cin>>q;
  vector<pair<pll,ll>> brr(q);
  for(int i=0; i<q; i++)
  {
    ll a,b;
    cin>>a>>b;
    brr[i]={{a-1,b-1},i};
  }
  sort(all(brr),[&](const pair<pll,ll>& a,const pair<pll,ll>& b)
  {
    ll ta=a.F.F/rn,tb=b.F.F/rn;
    return (ta==tb)?(a.F.S<b.F.S):(ta<tb);
  });
  ll st=brr[0].F.F,en=brr[0].F.S;
  Fenwick fw((ll)1e5);
  for(int i=st; i<=en; i++)
  {
    tans+=fw.query(max(arr[i]-k,1LL),min(arr[i]+k,(ll)1e5));
    fw.add(arr[i],1);
  }
  ans[brr[0].S]=tans;
  auto f1=[&](ll x){
    tans+=fw.query(max(x-k,1LL),min(x+k,(ll)1e5));
    fw.add(x,1);
  };
  auto f2=[&](ll x){
    fw.add(x,-1);
    tans-=fw.query(max(x-k,1LL),min(x+k,(ll)1e5));
  };
  for(int i=1; i<q; i++)
  {
    while(brr[i].F.F<st) f1(arr[--st]);
    while(en<brr[i].F.S) f1(arr[++en]);
    while(st<brr[i].F.F) f2(arr[st++]);
    while(brr[i].F.S<en) f2(arr[en--]);
    st=brr[i].F.F,en=brr[i].F.S;
    ans[brr[i].S]=tans;
  }
  for(int i=0; i<q; i++) cout<<ans[i]<<endl;
  return 0;
}