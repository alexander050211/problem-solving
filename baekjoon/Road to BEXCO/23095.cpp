  #include <bits/stdc++.h>
  #define endl '\n'
  #define pb push_back
  using namespace std;
  typedef long long ll;
  typedef pair<ll,ll> pll;
  bool arr[105][105];
  vector<ll> adj[10005];
  bool visited[10005];
  vector<pll> ans;
  void dfs(ll par,ll x)
  {
    visited[x]=true;
    for(auto y:adj[x])
    {
      if(visited[y]) continue;
      dfs(x,y);
    }
    ans.pb({x,par});
  }
  int main()
  {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n; char c;
    cin>>n>>c;
    for(int i=0; i<n; i++)
    {
      string s;
      cin>>s;
      for(int j=0; j<n; j++) arr[i][j]=(s[j]==c);
    }
    auto check_range=[&](const ll& x,const ll& y){
      return 0<=x && x<n && 0<=y && y<n;
    };
    auto f=[&](const ll& x,const ll& y){
      return x*n+y;
    };
    ll cnt=0;
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(arr[i][j]) cnt++;
    ll nx[8]={-1,-2,-2,-1,1,2,2,1};
    ll ny[8]={-2,-1,1,2,2,1,-1,-2};
    ll kx[8]={-1,-1,-1,0,1,1,1,0};
    ll ky[8]={-1,0,1,1,1,0,-1,-1};
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)
    {
      if(!arr[i][j]) continue;
      ll t=f(i,j);
      if(c=='R')
      {
        for(int k=0; k<n; k++)if(arr[k][j]) adj[t].pb(f(k,j));
        for(int k=0; k<n; k++)if(arr[i][k]) adj[t].pb(f(i,k));
      }
      else if(c=='Q')
      {
        for(int k=0; k<n; k++)if(arr[k][j]) adj[t].pb(f(k,j));
        for(int k=0; k<n; k++)if(arr[i][k]) adj[t].pb(f(i,k));
        for(int k=-n; k<=n; k++)if(check_range(i+k,j+k) && arr[i+k][j+k]) adj[t].pb(f(i+k,j+k));
        for(int k=-n; k<=n; k++)if(check_range(i+k,j-k) && arr[i+k][j-k]) adj[t].pb(f(i+k,j-k));
      }
      else if(c=='B')
      {
        for(int k=-n; k<=n; k++)if(check_range(i+k,j+k) && arr[i+k][j+k]) adj[t].pb(f(i+k,j+k));
        for(int k=-n; k<=n; k++)if(check_range(i+k,j-k) && arr[i+k][j-k]) adj[t].pb(f(i+k,j-k));
      }
      else if(c=='N')
      {
        for(int k=0; k<8; k++)if(check_range(i+nx[k],j+ny[k]) && arr[i+nx[k]][j+ny[k]]) adj[t].pb(f(i+nx[k],j+ny[k]));
      }
      else if(c=='K')
      {
        for(int k=0; k<8; k++)if(check_range(i+kx[k],j+ky[k]) && arr[i+kx[k]][j+ky[k]]) adj[t].pb(f(i+kx[k],j+ky[k]));
      }
    }
    bool flag=false;
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(!flag && arr[i][j])
    {
      dfs(-1,f(i,j));
      flag=true;
    }
    if(ans.size()!=cnt)
    {
      cout<<"NO"<<endl;
      return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0; i<cnt-1; i++)
    {
      auto [t1,t2]=ans[i];
      cout<<t1/n+1<<' '<<t1%n+1<<' '<<t2/n+1<<' '<<t2%n+1<<endl;
    }
    return 0;
  }