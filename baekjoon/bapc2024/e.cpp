#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
double dabs(double x)
{
  return x>0?x:-x;
}
double f(double x,double y,double z)
{
  return (double)sqrt(dabs(x-y))+sqrt(dabs(y-z))+sqrt(dabs(z-x));
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  ll a,b;
  cout<<"? "<<1<<endl;
  cout.flush();
  cin>>a;
  cout<<"? "<<n<<endl;
  cout.flush();
  cin>>b;
  ll st=2,en=n-1;
  ll target=(a+b)>>1;
  while(st<en)
  {
    ll mid=(st+en)>>1;
    cout<<"? "<<mid<<endl;
    cout.flush();
    ll temp;
    cin>>temp;
    if(temp>=target) en=mid;
    else st=mid+1;
  }
  ll c,d,e;
  cout<<"? "<<st-1<<endl;
  cout.flush();
  cin>>c;
  cout<<"? "<<st<<endl;
  cout.flush();
  cin>>d;
  cout<<"? "<<st+1<<endl;
  cout.flush();
  cin>>e;
  double t1=f(a,c,b),t2=f(a,d,b),t3=f(a,e,b);
  if(st==2) t1=0;
  if(st==n-1) t3=0;
  if(t1>t2 && t1>t3) cout<<"! "<<1<<' '<<st-1<<' '<<n<<endl;
  else if(t2>t1 && t2>t3) cout<<"! "<<1<<' '<<st<<' '<<n<<endl;
  else cout<<"! "<<1<<' '<<st+1<<' '<<n<<endl;
  cout.flush();
  return 0;
}