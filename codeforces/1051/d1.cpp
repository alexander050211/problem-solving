#include <bits/stdc++.h>
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
ll dp[305][305],dp2[305][305];
void solve()
{
  ll n;
  cin>>n;
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  for(int i=0; i<=n; i++)for(int j=0; j<=n; j++) dp[i][j]=0;
  dp[0][0]=1;
  for(int i=0; i<n; i++)
  {
    for(int x=0; x<=n; x++)for(int y=0; y<=n; y++) dp2[x][y]=dp[x][y];
    for(int x=0; x<=n; x++)for(int y=0; y<=n; y++)
    {
      ll temp=dp[x][y];
      if(!temp) continue;
      if(arr[i]>=x)
      {
        dp2[arr[i]][y]=(dp2[arr[i]][y]+temp)%mod;
      }
      else if(arr[i]>=y)
      {
        dp2[x][arr[i]]=(dp2[x][arr[i]]+temp)%mod;
      }
    }
    for(int x=0; x<=n; x++)for(int y=0; y<=n; y++) dp[x][y]=dp2[x][y];
  }
  ll ans=0;
  for(int x=0; x<=n; x++)for(int y=0; y<=n; y++) ans=(ans+dp[x][y])%mod;
  cout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll tt=1;
  cin>>tt;
  while(tt--)
  {
    solve();
  }
  return 0;
}