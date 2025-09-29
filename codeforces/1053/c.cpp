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
  ll n;
  cin>>n;
  vector<ll> arr(2*n);
  for(int i=0; i<2*n; i++) cin>>arr[i];
  vector<ll> brr(2*n-1);
  brr[0]=arr[1]-arr[0];
  for(int i=1; i<2*n-1; i++) brr[i]=arr[i+1]-arr[i];
  vector<ll> crr(n);
  crr[0]=brr[0];
  for(int i=1; i<n; i++) crr[i]=crr[i-1]+brr[i*2];
  ll sum=crr[n-1];
  cout<<sum<<' ';
  if(n==1)
  {
    cout<<endl;
    return;
  }
  vector<ll> drr(n-1);
  drr[0]=brr[1];
  for(int i=1; i<n-1; i++) drr[i]=drr[i-1]+brr[i*2+1];
  for(int i=1; i<n; i++)
  {
    if(i==1) sum+=2*(drr[n-2]);
    else if(i%2) sum+=2*(drr[n-2-(i/2)]-drr[i/2-1]);
    else sum+=2*(crr[n-1-(i/2)]-crr[i/2-1]);
    cout<<sum<<' ';
  }
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