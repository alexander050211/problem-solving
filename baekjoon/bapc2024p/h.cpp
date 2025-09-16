#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  ll m=(ll)floor((double)((double)sqrt(8*n+1)-1)/2);
  cout<<m<<endl;
  return 0;
}