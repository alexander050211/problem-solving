#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll,ll> pll;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll t;
  cin>>t;
  while(t--)
  {
    ll n,m;
    cin>>n>>m;
    ll temp=(n*(n+1))%m;
    if(1<=temp && temp<=n) cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
  }
  return 0;
}