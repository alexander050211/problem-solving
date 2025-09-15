#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  while(1)
  {
    ll n;
    cin>>n;
    if(!n) return 0;
    ll ret=0;
    for(int i=1; i<=n; i++)
    {
      ll temp;
      cin>>temp;
      if(ret+temp<=300) ret+=temp;
    }
    cout<<ret<<endl;
  }
  return 0;
}