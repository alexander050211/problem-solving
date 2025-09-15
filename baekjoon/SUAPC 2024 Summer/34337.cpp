#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll a[5],b[5];
ll f()
{
  if(b[0]==b[1] && b[1]==b[2] && b[2]==b[3] && b[3]==b[4]) return 50;
  ll c[7]={};
  for(int i=0; i<5; i++) c[b[i]]++;
  ll ret=0;
  for(int i=1; i<=6; i++) ret=max(ret,i*c[i]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  for(int i=0; i<5; i++) cin>>a[i];
  ll ans=0;
  for(int i=0; i<32; i++)
  {
    ll temp=0;
    for(int aa=1; aa<=6; aa++)
    for(int bb=1; bb<=6; bb++)
    for(int cc=1; cc<=6; cc++)
    for(int dd=1; dd<=6; dd++)
    for(int ee=1; ee<=6; ee++)
    {
      b[0]=(i&1)?aa:a[0];
      b[1]=((i>>1)&1)?bb:a[1];
      b[2]=((i>>2)&1)?cc:a[2];
      b[3]=((i>>3)&1)?dd:a[3];
      b[4]=((i>>4)&1)?ee:a[4];
      temp+=f();
    }
    ans=max(ans,temp);
  }
  cout<<ans<<endl;
  return 0;
}