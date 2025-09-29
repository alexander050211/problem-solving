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
void solve()
{
  ll n,m;
  cin>>n>>m;
  vector<ll> arr(m);
  for(int i=0; i<m; i++) cin>>arr[i];
  ll cnt=0;
  ll mm=0;
  for(int i=0; i<m; i++) mm=max(mm,arr[i]);  
  for(int i=0; i<m; i++)if(arr[i]==1) cnt++;
  if(cnt>1) cout<<1<<endl;
  else if(cnt==1 && arr[0]!=1) cout<<1<<endl;
  else cout<<(n-arr[m-1]+1)<<endl;
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