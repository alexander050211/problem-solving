#include <bits/stdc++.h>
#define endl '\n'
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
using namespace std;
typedef long long ll;
#define mod 1000000007
bool arr[100005];
ll dp[100005][455];
ll f(ll x)
{
  return (ll)floor((sqrt(8*x+1)-3)/2)+1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  string s;
  cin>>n>>s;
  for(int i=1; i<=n; i++) arr[i]=(s[i-1]=='#');
  dp[1][0]=1;
  for(int i=2; i<=n; i++)
  {
    if(arr[i]) continue;
    for(int j=0; j<=f(i); j++)
    {
      if((j+1)*(j+2)/2>i) break;
      dp[i][j]=dp[i-1][j];
      if(j && i-j-1>0) dp[i][j]+=dp[i-j-1][j-1];
      dp[i][j]%=mod;
    }
  }
  ll ans=0;
  ll idx1=n,idx2=n;
  while(arr[idx1]) idx1--,idx2--;
  if(!idx1)
  {
    cout<<0<<endl;
    return 0;
  }
  while(idx1>1 && !arr[idx1-1]) idx1--;
  for(int i=1; i<=n; i++)
  {
    for(int j=0; j<=f(i); j++)
    {
      if(n-i+1<=j+2) ans=(ans+dp[i][j])%mod;
    }
  }
  if(!arr[n])for(int j=0; j<=f(n); j++) ans=(ans+dp[n][j])%mod;
  cout<<ans%mod<<endl;
  return 0;
}