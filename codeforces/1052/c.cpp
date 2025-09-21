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
void solve()
{
  ll n;
  cin>>n;
  string s;
  cin>>s;
  vector<ll> arr(n);
  vector<ll> ans(n,0);
  for(int i=0; i<n; i++) arr[i]=s[i]-'0';
  ll temp=0;
  for(int i=0; i<n; i++)
  {
    if(!arr[i]) temp++;
    else
    {
      if(temp==1)
      {
        cout<<"NO"<<endl;
        return;
      }
      temp=0;
    }
  }
  if(temp==1)
  {
    cout<<"NO"<<endl;
    return;
  }
  ll st=0,en=0;
  while(st<n)
  {
    if(arr[st])
    {
      ans[st]=st+1;
      st++;
      en=st;
      continue;
    }
    else
    {
      while(en<n && !arr[en]) en++;
      for(int i=st; i<en-1; i++) ans[i]=i+2;
      ans[en-1]=st+1;
      st=en;
      continue;
    }
  }
  cout<<"YES"<<endl;
  for(int i=0; i<n; i++) cout<<ans[i]<<' ';
  cout<<endl;
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