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
ifstream fin;
ofstream fout;
void solve()
{
  ll n;
  fin>>n;
  vector<ll> arr(n),dp1(n),dp2(n);
  for(int i=0; i<n; i++) fin>>arr[i];
  dp1[0]=arr[0];
  for(int i=1; i<n; i++) dp1[i]=min(arr[i],max(dp1[i-1],llabs(arr[i]-arr[i-1])));
  dp2[n-1]=arr[n-1];
  for(int i=n-2; i>=0; i--) dp2[i]=min(arr[i],max(dp2[i+1],llabs(arr[i+1]-arr[i])));
  ll ans=0;
  for(int i=0; i<n; i++) ans=max(ans,min(dp1[i],dp2[i]));
  fout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  fin.open("snake_scales_chapter_2_input.txt");
  fout.open("out2.txt");
  ll tt=1;
  fin>>tt;
  for(int i=1; i<=tt; i++)
  {
    if(fin.eof()) break;
    fout<<"Case #"<<i<<": ";
    solve();
  }
  fin.close();
  fout.close();
  return 0;
}