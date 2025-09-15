#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll ans[55][55];
ll arr[55];
ll n;
bool check[55];
void f(ll x,ll y,ll v)
{
  ans[x][y]=ans[n-1-y][x]=ans[n-1-x][n-1-y]=ans[y][n-1-x]=v;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  while(1)
  {
    cin>>n;
    if(!n) return 0;
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n; i++) check[i]=false;
    ll t1=n-1;
    while(t1>0 && arr[t1]!=arr[0]) t1--;
    ll t2=0;
    while(t2<n-1 && arr[t2]!=arr[n-1]) t2++;
    if(t1<t2)
    {
      cout<<"No"<<endl;
      continue;
    }
    for(int i=0; i<n; i++)for(int j=0; j<n; j++) ans[i][j]=0;
    f(t1,0,arr[0]); f(t2,0,arr[n-1]);
    check[0]=check[t1]=check[n-1]=check[t2]=true;
    for(int i=0; i<n; i++)
    {
      if(check[i]) continue;
      if(i<t2) f(t1,i,arr[i]);
      else if(t2<i && i<t1) f(n-1,i,arr[i]);
      else if(t1<i) f(n-t2-1,i,arr[i]);
      check[i]=true;
    }

    cout<<"Yes"<<endl;
    for(int i=0; i<n; cout<<endl,i++)for(int j=0; j<n; j++) cout<<ans[i][j]<<' ';
  }
  return 0;
}