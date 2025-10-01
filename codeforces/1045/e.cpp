#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
void solve()
{
    ll n;
    cin>>n;
    vector<pair<pll,ll>> arr(n+1);//a_i,d_i,i
    for(int i=1; i<=n; i++) arr[i].S=i;
    cout<<"throw "<<n-1<<endl;
    cout.flush();
    cin>>arr[n-1].F.S;
    if(arr[n-1].F.S==1) arr[n-1].F.F=2;
    else arr[n-1].F.F=1;
    cout<<"swap "<<n-1<<endl;
    cout.flush();
    swap(arr[n-1],arr[n]);
    arr[n].F.S=1;
    cout<<"throw "<<n-1<<endl;
    cout.flush();
    cin>>arr[n-1].F.S;
    if(arr[n-1].F.S==1) arr[n-1].F.F=2;
    else arr[n-1].F.F=1;
    for(int i=n-2; i>0; i--)
    {
        if(arr[i+1].F.S!=arr[i+2].F.S)
        {
            cout<<"throw "<<i<<endl;
            cout.flush();
            cin>>arr[i].F.S;
            if(arr[i].F.S==arr[i+1].F.S+1) arr[i].F.F=1;
            else arr[i].F.F=2;
        }
        else
        {
            arr[i].F.S=arr[i+1].F.S+1;
            if(i==1)
            {
                cout<<"swap 1"<<endl;
                cout.flush();
                swap(arr[1],arr[2]);
                arr[1].F.S++;
                cout<<"throw 2"<<endl;
                cout.flush();
                cin>>arr[2].F.S;
                if(arr[2].F.S==arr[3].F.S+1) arr[2].F.F=1;
                else arr[2].F.F=2;
            }
            else
            {
                cout<<"throw "<<i-1<<endl;
                cout.flush();
                cin>>arr[i-1].F.S;
                if(arr[i-1].F.S==arr[i].F.S+1) arr[i-1].F.F=1;
                else arr[i-1].F.F=2;
                cout<<"swap "<<i-1<<endl;
                cout.flush();
                swap(arr[i-1],arr[i]);
                arr[i].F.S=arr[i+1].F.S+1;
                arr[i-1].F.S=arr[i-1+arr[i-1].F.F].F.S+1;
                cout<<"throw "<<i-1<<endl;
                cout.flush();
                cin>>arr[i-1].F.S;
                if(arr[i-1].F.S==arr[i].F.S+1) arr[i-1].F.F=1;
                else arr[i-1].F.F=2;
                i--;
            }
        }
    }
    vector<ll> ans(n+1);
    for(int i=1; i<=n; i++) ans[arr[i].S]=arr[i].F.F;
    cout<<"! ";
    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
    cout<<endl;
    cout.flush();
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tc=1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
