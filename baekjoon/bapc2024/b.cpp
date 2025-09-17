#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  string a,b,c;
  cin>>n>>a>>b>>c;
  for(int i=2; i<=16; i++)
  {
    if(n%(i*i)) continue;
    cout<<i<<' ';
    string ans;
    while(n)
    {
      ll temp=n%i;
      if(temp>9) ans+=(temp-10+'a');
      else ans+=(temp+'0');
      n/=i;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
  }
  cout<<"impossible"<<endl;
  return 0;
}