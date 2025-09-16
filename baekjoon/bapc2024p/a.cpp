#include <bits/stdc++.h>
#define endl '\n'
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
using namespace std;
typedef long long ll;
ll dp[405][405];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,b;
  cin>>n>>b;
  for(int i=1; i<=n; i++) dp[i][i]=i;
  for(int k=1; k<n; k++)for(int i=1; i+k<=n; i++)
  {
    dp[i][i+k]=dp[i][i+k-1]+i+k;
    for(int j=i; j<i+k; j++)
    {
      ll temp=max(j+dp[i][j-1],b+dp[j+1][i+k]);
      dp[i][i+k]=min(dp[i][i+k],temp);
    }
  }
  cout<<dp[1][n]<<endl;
  return 0;
}