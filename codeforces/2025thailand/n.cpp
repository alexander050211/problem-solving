#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,a,b;
  cin>>n>>a>>b;
  ll ta=a+1,tb=n-b;
  cout<<llabs(ta-tb)-1<<endl;
  return 0;
}