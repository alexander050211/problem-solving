#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll n,m,kk;
vector<pair<ll,pll>> arr;
ll dist[405][405];
bool visited[6];
vector<ll> temp;
vector<ll> tt;
ll ans;
void dfs(ll x)
{
    if(tt.size()==kk)
    {
        for(int i=0; i<(1<<kk); i++)
        {
            ll tc=0;
            vector<pll> brr(kk,{0,0});
            for(int j=0; j<kk; j++) brr[j]=arr[temp[tt[j]-1]-1].S;
            
            for(int j=0; j<kk; j++) if((i>>j)&1) swap(brr[j].F,brr[j].S);
            tc+=dist[1][brr[0].F]+dist[brr[kk-1].S][n];
            for(int j=0; j<kk; j++) tc+=arr[temp[tt[j]-1]-1].F;
            for(int j=1; j<kk; j++) tc+=dist[brr[j].F][brr[j-1].S];

            ans=min(ans,tc);
        }
    }
    visited[x]=true;
    for(int i=1; i<=kk; i++)
    {
        if(visited[i]) continue;
        tt.push_back(i);
        dfs(i);
        tt.pop_back();
    }
    visited[x]=false;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)
    {
        if(i==j) continue;
        dist[i][j]=(ll)1e18;
    }
    for(int i=0; i<m; i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        arr.push_back({c,{a,b}});
        dist[a][b]=min(dist[a][b],c);
        dist[b][a]=min(dist[b][a],c);
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    ll q;
    cin>>q;
    while(q--)
    {
        cin>>kk;
        temp.resize(kk);
        for(int i=0; i<kk; i++) cin>>temp[i];
        ans=(ll)1e18;
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}