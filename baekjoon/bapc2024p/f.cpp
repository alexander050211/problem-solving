#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<long double,long double> point;
point arr[1005];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cout<<setprecision(11);
  ll n;
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i].F>>arr[i].S;
  long double ans=(long double)sqrtl(3)/4;
  long double ls=0;
  for(int i=1; i<n; i++) ls+=(long double)powl((long double)arr[i].F-arr[i-1].F,(long double)2.0)+powl((long double)arr[i].S-arr[i-1].S,(long double)2.0);
  long double ds=0;
  for(int i=1; i<n; i++)
  {
    long double dx=(long double)arr[i].F-arr[i-1].F;
    long double dy=(long double)(arr[i].S+arr[i-1].S)/2.0;
    ds+=(long double)dx*dy;
  }
  long double temp;
  if(n>2) temp=(long double)3.0*ds/((long double)1.0-ls);
  else temp=0;
  cout<<((long double)ans+temp);
  return 0;
}