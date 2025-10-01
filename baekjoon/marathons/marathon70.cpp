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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  if(n*(n-1)/2>131072)
  {
    cout<<"Yes"<<endl;
    return 0;
  }
  vector<ll> cnt(131072,0);
  for(int i=0; i<n; i++)for(int j=i+1; j<n; j++) cnt[arr[i]^arr[j]]++;
  for(int i=0; i<131072; i++)if(cnt[i]>1)
  {
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
  return 0;
}