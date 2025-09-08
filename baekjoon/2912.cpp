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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m;
  cin>>n>>m;
  ll sz=(ll)floor(sqrt(n));
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
  sort(all(brr),[&](const pair<pll,ll>& a,const pair<pll,ll>& b){
    ll ta=a.F.F/sz,tb=b.F.F/sz;
    return (ta==tb)?(a.F.S<b.F.S):(ta<tb);
  });
  ll st=brr[0].F.F,en=brr[0].F.S;
  vector<ll> cnt(m+1,0),ccnt(n+1,0),ans(q,0);
  ccnt[0]=m;
  ll tans=0;
  auto f1=[&](ll x){
    ccnt[cnt[x]++]--;
    ccnt[cnt[x]]++;
    if(ccnt[tans+1]) tans++;
  };
  auto f2=[&](ll x){
    ccnt[cnt[x]--]--;
    ccnt[cnt[x]]++;
    if(!ccnt[tans]) tans--;
  };
  auto f=[&](ll st,ll en){
    ll len=en-st+1;
    for(int i=1; i<=m; i++)if(cnt[i]*2>len) return i;
    return -1;
  };
  for(int i=st; i<=en; i++) f1(arr[i]);
  if(tans*2>en-st+1) ans[brr[0].S]=f(st,en);
  for(int i=1; i<q; i++)
  {
    while(brr[i].F.F<st) f1(arr[--st]);
    while(en<brr[i].F.S) f1(arr[++en]);
    while(st<brr[i].F.F) f2(arr[st++]);
    while(brr[i].F.S<en) f2(arr[en--]);
    st=brr[i].F.F,en=brr[i].F.S;
    if(tans*2>en-st+1) ans[brr[i].S]=f(st,en);
  }
  for(auto x:ans)
  {
    if(x) cout<<"yes "<<x<<endl;
    else cout<<"no"<<endl;
  }
  return 0;
}