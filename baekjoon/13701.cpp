#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
bitset<(1<<25)> arr;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  while(cin>>n)
  {
    if(arr[n]) continue;
    arr.set(n);
    cout<<n<<' ';
  }
  return 0;
}