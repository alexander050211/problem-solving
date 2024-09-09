#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
typedef pair<pll, ll> Node;
ll n, q;
ll arr[500005];
stack<Node> st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    Node temp = {{n, n}, arr[n]};
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] == arr[i + 1] + 1)
        {
            temp.F.F--;
            temp.S++;
            continue;
        }
        st.push(temp);
        temp = {{i, i}, arr[i]};
    }
    st.push(temp);
    while (q--)
    {
        ll a, b;
        cin >> a;
        if (a == 2)
        {
            Node node = st.top();
            cout << node.S << endl;
            continue;
        }
        cin >> b;
        Node node1 = st.top();
        st.pop();
        Node node2 = st.top();
        ll target = (node1.F.S - node1.F.F + 1) * (node2.S + node1.F.S - node1.F.F + 1 - node1.S);
        Node node;
        if (b >= target)
        {
            node = {{node1.F.F, node2.F.S}, node2.S + node1.F.S - node1.F.F + 1};
            b -= target;
        }
        else
        {
            st.push(node2);
            node = node1;
        }
        ll x = b / (node.F.S - node.F.F + 1);
        node.S += x;
        b %= (node.F.S - node.F.F + 1);
    }
}