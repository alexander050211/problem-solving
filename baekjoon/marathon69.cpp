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
bool arr[105][25];
ll cnt[105];
ll n,m;
bool f(ll x)
{
  for(int i=0; i<m; i++)
  {
    ll temp=0;
    for(int j=0; j<n; j++)if(arr[i][j] && (x>>j)&1LL) temp++;
    if(temp!=cnt[i]) return false;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  for(int i=0; i<m; i++)
  {
    string s;
    cin>>s>>cnt[i];
    for(int j=0; j<n; j++) arr[i][j]=(s[j]=='1');
  }
  vector<ll> ans;
  for(int i=0; i<(1LL<<n); i++)if(f(i)) ans.pb(i);
  if(ans.empty()) cout<<"IMPOSSIBLE"<<endl;
  else if(ans.size()>1) cout<<"NOT UNIQUE"<<endl;
  else
  {
    ll temp=ans[0];
    for(int i=0; i<n; i++)
    {
      if((temp>>i)&1LL) cout<<"1";
      else cout<<"0";
    }
  }
  return 0;
}