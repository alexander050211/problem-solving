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
ll dp[105][105],ncr[105][105];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,a,b;
  cin>>n>>a>>b;
  for(int i=0; i<=n; i++)for(int j=0; j<=n; j++)
  {
    if(i==j) ncr[i][j]=1;
    else if(!j) ncr[i][j]=1;
    else if(i<j) ncr[i][j]=0;
    else ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
  }
  
  ll ans=0;
  for(int i=a; i<=n-b+1; i++)
  {
    ll temp=(((ncr[n][i-1]*dp[i-1][a-1])%mod)*dp[n-i][b-1])%mod;
    ans=(ans+temp)%mod;
  }
  cout<<ans<<endl;
  return 0;
}