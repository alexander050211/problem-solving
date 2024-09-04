#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a,b;
    cin>>a>>b;
    if(a==b) cout<<1<<endl;
    else if((a-b)%2) cout<<2<<endl;
    else cout<<3<<endl;
    return 0;
}