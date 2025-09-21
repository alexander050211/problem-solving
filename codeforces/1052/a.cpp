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
ll cnt[105];
void solve()
{
  ll n;
  cin>>n;
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  map<ll,ll> mp;
  for(int i=0; i<n; i++) mp[arr[i]]++;
  vector<ll> temp;
  for(auto x:mp) temp.pb(x.S);
  sort(all(temp));
  reverse(all(temp));
  ll ans=0;
  for(int i=0; i<temp.size(); i++) ans=max(ans,(i+1)*temp[i]);
  cout<<ans<<endl;
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