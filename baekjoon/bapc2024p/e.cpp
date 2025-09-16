#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,k,p;
  cin>>n>>k>>p;
  ll a=100*(n-k)+100+p*(n+4);
  ll b=100*(n-k)+200+(100-p)*(n+4);
  ll c=100*(n+4);
  if(a<b && a<c) cout<<"continue";
  else if(b<a && b<c) cout<<"backspace";
  else cout<<"restart";
  return 0;
}