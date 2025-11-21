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
  vector<ll> arr(3,0);
  for(int i=0; i<3; i++) cin>>arr[i];
  sort(all(arr));
  if(arr[2]-arr[0]>=10) cout<<"check again"<<endl;
  else cout<<"final "<<arr[1]<<endl;
  return 0;
}