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
  vector<ll> arr(2*n,0);
  arr[0]=arr[n]=n;
  for(int i=n-1; i>0; i--) arr[n-i]=arr[2*n-(n-i)]=i;
  for(int i=0; i<2*n; i++) cout<<arr[i]<<' ';
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