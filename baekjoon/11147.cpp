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
const ll INF=(ll)4e16;
ll cost[205][205];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll tt=1;
  cin>>tt;
  while(tt--)
  {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n; i++)for(int j=0; j<n; j++) cin>>cost[i][j];
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(cost[i][j]==-1) cost[i][j]=INF;
    for(int k=0; k<n; k++)for(int i=0; i<n; i++)for(int j=0; j<n; j++) cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
    ll ans=0;
    for(int i=1; i<n; i++) ans+=cost[arr[i-1]][arr[i]];
    ans+=cost[arr[n-1]][arr[0]];
    if(ans>=INF) cout<<"impossible"<<endl;
    else cout<<ans<<endl;
  }
  return 0;
}