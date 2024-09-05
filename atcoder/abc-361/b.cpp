#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ll> arr(6), brr(6);
    for (int i = 0; i < 6; i++)
        cin >> arr[i];
    for (int i = 0; i < 6; i++)
        cin >> brr[i];
    bool check = true;
    if (arr[3] <= brr[0] || brr[3] <= arr[0])
        check = false;
    if (arr[4] <= brr[1] || brr[4] <= arr[1])
        check = false;
    if (arr[5] <= brr[2] || brr[5] <= arr[2])
        check = false;
    if (check)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}