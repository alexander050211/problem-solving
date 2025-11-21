#include <bits/stdc++.h>
#define endl '\n'
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll mod=(ll)1e9+7;
const ll INF=(ll)4e18;
ll arr[1005],brr[1005],dp[1005][1005];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m,k;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  cin>>m;
  for(int i=1; i<=m; i++) cin>>brr[i];
  cin>>k;
  for(int i=0; i<=n; i++)for(int j=0; j<=m; j++) dp[i][j]=-INF;
  dp[0][0]=0;
  for(ll i=1; i<=n+m; i++)for(ll j=0; j<=min(i,n); j++)
  {
    if(i-j>m) continue;
    if(j) dp[j][i-j]=dp[j-1][i-j]+arr[j];
    if(i==j) continue;
    ll temp=dp[j][i-j-1];
    ll t=(temp%k+k)%k;
    if(!t) t=k;
    dp[j][i-j]=max(dp[j][i-j],temp-min(t,brr[i-j]));
  }
  cout<<dp[n][m]<<endl;
  return 0;
}