#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
#define all(x) x.begin(),x.end()
ll sum1[100005],sum2[100005],cnt1[1<<20],cnt2[1<<20],ans[100005];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,k,rn;
  cin>>n>>k;
  rn=(ll)floor(sqrt(n));
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  ll m;
  cin>>m;
  vector<pair<pll,ll>> brr(m);
  for(int i=0; i<m; i++)
  {
    ll a,b;
    cin>>a>>b;
    brr[i]={{a-1,b-1},i};
  }
  sort(all(brr),[&](const pair<pll,ll>& a,const pair<pll,ll>& b){
    ll ta=a.F.F/rn,tb=b.F.F/rn;
    return (ta==tb)?(a.F.S<b.F.S):(ta<tb);
  });
  sum1[0]=arr[0];
  for(int i=1; i<n; i++) sum1[i]=sum1[i-1]^arr[i];
  sum2[n-1]=arr[n-1];
  for(int i=n-2; i>=0; i--) sum2[i]=sum2[i+1]^arr[i];
  ll st=brr[0].F.F,en=brr[0].F.S;
  ll tans=0;
  auto f1=[&](ll x){
    if(!x) cnt1[0]++;
    else cnt1[sum1[x-1]]++;
    tans+=cnt1[sum1[x]^k];
    if(x==n-1) cnt2[0]++;
    else cnt2[sum2[x+1]]++;
  };
  auto f2=[&](ll x){
    tans-=cnt1[sum1[x]^k];
    if(!x) cnt1[0]--;
    else cnt1[sum1[x-1]]--;
    if(x==n-1) cnt2[0]--;
    else cnt2[sum2[x+1]]--;
  };
  auto f3=[&](ll x){
    if(x==n-1) cnt2[0]++;
    else cnt2[sum2[x+1]]++;
    tans+=cnt2[sum2[x]^k];
    if(!x) cnt1[0]++;
    else cnt1[sum1[x-1]]++;
  };
  auto f4=[&](ll x){
    tans-=cnt2[sum2[x]^k];
    if(x==n-1) cnt2[0]--;
    else cnt2[sum2[x+1]]--;
    if(!x) cnt1[0]--;
    else cnt1[sum1[x-1]]--;
  };
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
  for(int i=0; i<m; i++) cout<<ans[i]<<endl;
  return 0;
}