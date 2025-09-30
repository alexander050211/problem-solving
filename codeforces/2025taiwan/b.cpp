#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
bool pr[1000005];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  for(int i=2; i<=1000000; i++) pr[i]=true;
  for(int i=2; i<=1000000; i++)
  {
    if(!pr[i]) continue;
    for(int j=2*i; j<=1000000; j+=i)
      pr[j]=false;
  }
  ll t;
  cin>>t;
  while(t--)
  {
    ll a,b;
    cin>>a>>b;
    if(b-a==2 && pr[a] && pr[b]) cout<<"Y"<<endl;
    else cout<<"N"<<endl;
  }
  return 0;
}