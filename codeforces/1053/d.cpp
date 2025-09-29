#include <bits/stdc++.h>
#define endl '\n'
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll mod=(ll)998244353;
const ll INF=(ll)4e18;
ll fac[200005],invf[200005];

ll ppow(ll a,ll b)
{
    ll ret=1;
    a%=mod;
    while(b>0)
    {
        if(b&1) ret=(ret*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ret;
}
void init()
{
    fac[0]=1;
    for(int i=1; i<=200000; i++) fac[i]=(fac[i-1]*i)%mod;
    invf[200000]=ppow(fac[200000],mod-2);
    for(int i=199999; i>=0; i--) invf[i]=(invf[i+1]*(i+1))%mod;
}
ll ncr(ll a,ll b)
{
    if(b<0 || b>a) return 0;
    return (((fac[a]*invf[b])%mod)*invf[a-b])%mod;
}
void solve()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    ll sum=0;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        sum+=arr[i];
    }

    if(sum!=n)
    {
        cout<<0<<endl;
        return;
    }
    ll M = (n + 1) / 2;
    for (ll i = M; i < n; ++i) {
        if (arr[i] != 0) {
            cout << 0 << endl;
            return;
        }
    }
    ll ans=1;
    ll remaining_tasks=0;
    for(int i=M; i>0; i--)
    {
        ll j=i-1;
        ll new_tasks=0;
        if(i==M) new_tasks=n+2-2*M;
        else new_tasks=2;
        ll task_pool = remaining_tasks + new_tasks;
        if(task_pool < arr[j])
        {
            cout<<0<<endl;
            return;
        }
        ll temp=ncr(task_pool,arr[j]);
        ans=(ans*temp)%mod;
        remaining_tasks = task_pool - arr[j];
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tt=1;
    cin>>tt;
    init();
    while(tt--)
    {
        solve();
    }
    return 0;
}