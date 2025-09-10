#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define all(X) x.begin().x.end()
#define pb push_back
using namespace std;
typedef unsigned long long ll;
typedef pair<ll,ll> pll;
const ll MOD=((ll)1<<32);
ll n;
vector<ll> adj[500005],bdj[500005];
ll sz[500005],dep[500005],par[500005],in[500005],out[500005],top[500005];
bool visited[500005];
void dfs(ll x=1)
{
    visited[x]=true;
    for(auto y:adj[x])
    {
        if(visited[y]) continue;
        bdj[x].pb(y);
        dfs(y);
    }
}
void dfs1(ll x=1)
{
    sz[x]=1;
    for(auto& y:bdj[x])
    {
        dep[y]=dep[x]+1;
        par[y]=x;
        dfs1(y);
        sz[x]+=sz[y];
        if(sz[y]>sz[bdj[x][0]]) swap(y,bdj[x][0]);
    }
}
ll cnt;
void dfs2(ll x=1)
{
    in[x]=++cnt;
    for(auto y:bdj[x])
    {
        top[y]=(y==bdj[x][0])?top[x]:y;
        dfs2(y);
    }
    out[x]=cnt;
}
ll tree[2000005];
pll lazy[2000005];
void update_lazy(ll node,ll st,ll en)
{
    pll t=lazy[node],zero={1,0};
    if(t==zero) return;
    tree[node]=(tree[node]*t.F+(en-st+1)*t.S)%MOD;
    if(st!=en)
    {
        pll t1=lazy[node<<1],t2=lazy[node<<1|1];
        lazy[node<<1]={(t1.F*t.F)%MOD,(t.F*t1.S+t.S)%MOD};
        lazy[node<<1|1]={(t2.F*t.F)%MOD,(t.F*t2.S+t.S)%MOD};
    }
    lazy[node]=zero;
}
void update_range(ll node,ll st,ll en,ll l,ll r,pll val)
{
    update_lazy(node,st,en);
    if(r<st || en<l) return;
    if(l<=st && en<=r)
    {
        tree[node]=(tree[node]*val.F+(en-st+1)*val.S)%MOD;
        if(st!=en)
        {
            pll t1=lazy[node<<1],t2=lazy[node<<1|1];
            lazy[node<<1]={(t1.F*val.F)%MOD,(val.F*t1.S+val.S)%MOD};
            lazy[node<<1|1]={(t2.F*val.F)%MOD,(val.F*t2.S+val.S)%MOD};
        }
        return;
    }
    ll mid=(st+en)>>1;
    update_range(node<<1,st,mid,l,r,val); update_range(node<<1|1,mid+1,en,l,r,val);
    tree[node]=(tree[node<<1]+tree[node<<1|1])%MOD;
}
ll tquery(ll node,ll st,ll en,ll l,ll r)
{
    update_lazy(node,st,en);
    if(r<st || en<l) return 0;
    if(l<=st && en<=r) return tree[node];
    ll mid=(st+en)>>1;
    return (tquery(node<<1,st,mid,l,r)+tquery(node<<1|1,mid+1,en,l,r))%MOD;
}
void update(ll a,ll b,pll val)
{
    while(top[a]!=top[b])
    {
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        update_range(1,1,n,in[top[a]],in[a],val);
        a=par[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    update_range(1,1,n,in[a],in[b],val);
}
ll query(ll a,ll b)
{
    ll ret=0;
    while(top[a]!=top[b])
    {
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        ret+=tquery(1,1,n,in[top[a]],in[a]);
        ret%=MOD;
        a=par[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    ret+=tquery(1,1,n,in[a],in[b]);
    return ret%MOD;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll q;
    cin>>n>>q;
    for(int i=1; i<n; i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b); adj[b].pb(a);
    }
    top[1]=1;
    dfs(); dfs1(); dfs2();
    for(int i=1; i<=4*n; i++) lazy[i]={1,0};
    while(q--)
    {
        ll a,b,c=0,d=0;
        cin>>a>>b;
        if(a!=5) cin>>c;
        if(a==2 || a==4) cin>>d;
        if(a==1) update_range(1,1,n,in[b],out[b],{1,c});
        else if(a==2) update(b,c,{1,d});
        else if(a==3) update_range(1,1,n,in[b],out[b],{c,0});
        else if(a==4) update(b,c,{d,0});
        else if(a==5) cout<<tquery(1,1,n,in[b],out[b])<<endl;
        else if(a==6) cout<<query(b,c)<<endl;
    }
    return 0;
}