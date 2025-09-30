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
const ll mod=(ll)1e9+7;
const ll INF=(ll)4e18;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll t;
  cin>>t;
  ll a[8]={1,2,4,3,7,8,6,5};
  while(t--)
  {
    ll n;
    cin>>n;
    ll k=(n-1)/8+1;
    for(int i=0; i<k-1; i++)for(int j=0; j<8; j++) cout<<(i*8+a[j])<<' ';
    if(n%8==1) cout<<n;
    else if(n%8==2) cout<<n-1<<' '<<n;
    else if(n%8==3) cout<<n-2<<' '<<n-1<<' '<<n;
    else if(n%8==4) cout<<n-3<<' '<<n-2<<' '<<n<<' '<<n-1;
    else if(n%8==5) cout<<n<<' '<<n-4<<' '<<n-3<<' '<<n-1<<' '<<n-2;
    else if(n%8==6) cout<<n<<' '<<n-2<<' '<<n-3<<' '<<n-4<<' '<<n-1<<' '<<n-5;
    else if(n%8==7) cout<<n-6<<' '<<n-5<<' '<<n-3<<' '<<n-4<<' '<<n<<' '<<n-1<<' '<<n-2;
    else for(int i=0; i<8; i++) cout<<(n-8+a[i])<<' ';
    cout<<endl;
  }
  return 0;
}