#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
#define all(x) x.begin(),x.end()
ll cnt[200005],ccnt[100005],ans[100005];
ll tans;
void f1(ll x)
{
  ccnt[cnt[x]++]--;
  ccnt[cnt[x]]++;
  if(ccnt[tans+1]) tans++;
}
void f2(ll x)
{
  ccnt[cnt[x]--]--;
  ccnt[cnt[x]]++;
  if(!ccnt[tans]) tans--;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m,rn;
  cin>>n>>m;
  rn=(ll)floor(sqrt(n));
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  vector<pair<pll,ll>> brr(m);
  for(int i=0; i<m; i++)
  {
    ll a,b;
    cin>>a>>b;
    brr[i]={{a-1,b-1},i};
  }
  sort(all(brr),[&](const pair<pll,ll>& a,const pair<pll,ll>& b) {
    ll ta=a.F.F/rn,tb=b.F.F/rn;
    return (ta==tb)?(a.F.S<b.F.S):(ta<tb);
  });
  ll st=brr[0].F.F,en=brr[0].F.S;
  for(int i=st; i<=en; i++) cnt[arr[i]+100000]++;
  for(int i=0; i<=200000; i++)
  {
    ccnt[cnt[i]]++;
    tans=max(tans,cnt[i]);
  }
  ans[brr[0].S]=tans;
  for(int i=1; i<m; i++)
  {
    while(brr[i].F.F<st) f1(arr[--st]+100000);
    while(en<brr[i].F.S) f1(arr[++en]+100000);
    while(st<brr[i].F.F) f2(arr[st++]+100000);
    while(brr[i].F.S<en) f2(arr[en--]+100000);
    ans[brr[i].S]=tans;
    st=brr[i].F.F,en=brr[i].F.S;
  }
  for(int i=0; i<m; i++) cout<<ans[i]<<endl;
  return 0;
}