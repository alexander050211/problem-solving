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
  for(int i=0; i<n; i++)
  {
    string s;
    cin>>s;
    ll h=s[0]-'0';
    ll m=(s[2]-'0')*10+(s[3]-'0');
    arr[i]=h*60+m;
  }
  for(int i=2; i<n; i++)if(arr[i]-arr[i-2]<=10)
  {
    cout<<0<<endl;
    return 0;
  }
  for(int i=1; i<n; i++)if(arr[i]-arr[i-1]<=10)
  {
    cout<<1<<endl;
    return 0;
  }
  cout<<2<<endl;
  return 0;
}