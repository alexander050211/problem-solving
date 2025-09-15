#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
bool dp[200005][105];
ll arr[100005];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  ll ans=0;
  ll st=1,en=1;
  dp[1][arr[1]]=true;
  while(st<n)
  {
    cout<<"st="<<st<<endl;
    while(en+1<=n && !dp[en][100-arr[en+1]])
    {
      for(int i=1; i<=100; i++) dp[en+1][i]=dp[en][i];
      dp[en+1][arr[en+1]]=true;
      for(int i=1; i<=100; i++)
        if(dp[en][i] && i+arr[en+1]<=100)
          dp[en+1][i+arr[en+1]]=true;
      en++;
    }
    if(en==n)
    {
      while(st<n)
      {
        if(dp[en][100]) ans++;
        for(int i=)
        ll temp=-arr[st];

        st++;
      }
      break;
    }
    cout<<"en="<<en<<endl;
    ans+=n-en;
    ll temp=(en+1<=n?arr[en+1]:0)-arr[st];
    for(int i=1; i<=99; i++)
      if(dp[en][i] && 1<=i+temp && i+temp<=99)
        dp[en+1][i]=true;
    if(en<n) en++;
    st++;
  }
  cout<<ans<<endl;
  return 0;
}