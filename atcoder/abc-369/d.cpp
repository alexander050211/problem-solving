#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll dp[200005][2];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    dp[0][1]=arr[0];
    for(int i=1; i<n; i++)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+arr[i]*2);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]+arr[i]);
    }
    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
    return 0;
}