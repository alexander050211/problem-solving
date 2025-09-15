#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
bool arr[3005][3005];
ll deg[3005];
ll n;
ll f(ll x)
{
  return (x+n-1)%n+1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=0; i<n-3; i++)
  {
    ll a,b;
    cin>>a>>b;
    arr[a][b]=arr[b][a]=true;
    deg[a]++; deg[b]++;
  }
  for(int i=1; i<=n; i++) arr[i][f(i+1)]=arr[f(i+1)][i]=true;
  ll b=1;
  while(deg[b]) b++;
  ll a=f(b-1),c=f(b+1);
  cout<<a<<' '<<b<<' '<<c<<endl;
  for(int i=0; i<n-3; i++)
  {
    if(arr[a][f(c+1)])
    {
      cout<<a<<' '<<b<<' '<<c<<' '<<f(c+1)<<endl;
      b=c; c=f(c+1);
    }
    else
    {
      cout<<a<<' '<<b<<' '<<c<<' '<<f(a-1)<<endl;
      b=a; a=f(a-1);
    }
  }
  return 0;
}