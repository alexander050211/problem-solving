#include <bits/stdc++.h>
#define endl '\n'
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
using namespace std;
typedef long long ll;
#define mod 1000000007
ll cnt[5];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  scanf("%d",&n);
  double ans=0;
  for(int i=1; i<=n; i++)
  {
    double temp;
    scanf("%lf",&temp);
    ll tt=((ll)round(temp*100.0))%5;
    cnt[tt]++;
    ans+=temp;
  }
  ans-=(double)0.02*cnt[2];
  ans-=(double)0.01*cnt[1];
  ll m=min(cnt[3],cnt[4]);
  ans-=(double)0.02*m;
  cnt[3]-=m; cnt[4]-=m;
  if(cnt[3]) ans-=(double)0.01*((ll)(cnt[3]/2));
  else ans-=(double)0.02*((ll)(cnt[4]/3));
  printf("%.2lf",ans);
  return 0;
}