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
  ll tt;
  cin>>tt;
  while(tt--)
  {
    ll n; char c; string s,t;
    cin>>n>>c>>s>>t;
    vector<char> ans(n,0);
    bool used=false;
    ll idx=0;
    while(idx<n && s[idx]==t[idx])
    {
      ans[idx]==s[idx];
      if(s[idx]==c) used=true;
      idx++;
    }
    if(idx==n || s[idx]>t[idx])
    {
      cout<<"NO"<<endl;
      continue;
    }
    if(t[idx]-s[idx]>1)
    {
      ans[idx]=s[idx]+1;
      for(int i=idx+1; i<n; i++) ans[i]=c;
    }
    else
    {
      
    }
  }
  return 0;
}