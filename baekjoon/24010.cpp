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
ll cp[105];
ll fin(ll x)
{
  if(cp[x]==x) return x;
  return cp[x]=fin(cp[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll tc;
  cin>>tc;
  for(int j=1; j<=tc; j++)
  {
    cout<<"Case #"<<j<<": ";
    ll n;
    cin>>n;
    for(int i=0; i<n; i++) cp[i]=i;
    vector<ll> arr(n),brr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n; i++) cin>>brr[i];
    priority_queue<pair<ll,pll>> pq;
    for(int i=0; i<n; i++)for(int j=i+1; j<n; j++)
    {
      ll temp=min(arr[i]^brr[j],arr[j]^brr[i]);
      pq.push({-temp,{i,j}});
    }
    ll ans=0;
    for(int i=1; i<n; i++)
    {
      pair<ll,pll> temp;
      while(!pq.empty())
      {
        temp=pq.top();
        pq.pop();
        if(fin(temp.S.F)!=fin(temp.S.S)) break;
      }
      ans-=temp.F;
      cp[fin(temp.S.F)]=fin(temp.S.S);
    }
    cout<<ans<<endl;
  }
  return 0;
}