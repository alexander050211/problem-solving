#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t, n, m;
  cin >> t;
  for (int i = 0; i < t; i++){
    cin >> n >> m;
    if (n == 2){
      if (m & 1) cout << 2 << ' ' << 1 << '\n';
      else cout << 1 << ' ' << 2 << '\n';
    }
    else{
      for (int i = 0; i < min(n, m); i++) cout << n - i << ' ';
      for (int i = min(n, m); i < n; i++) cout << i - min(n, m) + 1 << ' ';
      cout << '\n';
    }
  }
  return 0;
}