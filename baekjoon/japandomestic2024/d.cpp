#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll dp[105][105][5];
ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool check[105][105];
bool check_range(ll x,ll y)
{
  return 0<=x && x<=100 && 0<=y && y<=100;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  while(1)
  {
    ll n;
    cin>>n;
    if(!n) return 0;
    ll x,y,k;
    cin>>x>>y>>k;
    for(int i=0; i<=100; i++)for(int j=0; j<=100; j++)for(int a=0; a<4; a++) dp[i][j][a]=-1;
    for(int i=0; i<n; i++)
    {
      ll a,b;
      cin>>a>>b;
      check[a][b]=true;
    }
    dp[x][y][1]=0;
    ll tk=0,dir=1;
    while(tk<k)
    {
      ll tx=x+dx[dir],ty=y+dy[dir];
      while(check_range(tx,ty) && check[tx][ty])
      {
        dir=(dir+3)%4;
        tx=x+dx[dir],ty=y+dy[dir];
      }
      if(!check_range(tx,ty))
      {
        x+=(k-tk)*dx[dir];
        y+=(k-tk)*dy[dir];
        break;
      }
      x=tx,y=ty;
      tk++;
      if(dp[x][y][dir]!=-1)
      {
        ll t=tk-dp[x][y][dir];
        ll temp=(k-tk)%t;
        k=tk+temp;
      }
      dp[x][y][dir]=tk;
    }
    cout<<x<<' '<<y<<endl;
    for(int i=0; i<=100; i++)for(int j=0; j<=100; j++) check[i][j]=false;
  }
  return 0;
}