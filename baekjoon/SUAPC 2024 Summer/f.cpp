#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
double x[5],y[5],v[5];
ll w[5];
double d[3];
double ans[5];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout<<fixed<<setprecision(7);
  for(int i=1; i<=3; i++) cin>>x[i]>>y[i]>>v[i];
  d[1]=sqrt(pow(x[1]-x[2],2)+pow(y[1]-y[2],2));
  d[2]=sqrt(pow(x[2]-x[3],2)+pow(y[2]-y[3],2));
  d[3]=sqrt(pow(x[3]-x[1],2)+pow(y[3]-y[1],2));
  for(int i=1; i<=3; i++) cout<<d[i]<<endl;
  double dd=d[1]+d[2]+d[3];
  for(int i=1; i<=3; i++) cin>>w[i];
  ll a,b,c;
  if(!v[1]) a=1, b=2, c=3;
  else if(!v[2]) a=2, b=3, c=1;
  else a=3, b=1, c=2;
  if(v[b]<v[c])
  {
    double t1=(double)d[b]/v[b];
    double t2=(double)dd/v[c];
    if(w[b]==1 && t2<t1)
    {
      
      ans[b]=(double)dd/v[b];
      double x=(double)v[b]*(d[c]+d[a])/(v[c]-v[b]);
      ans[c]=(double)(d[c]+d[a]+x)/v[c]+(double)(d[b]-x)/v[b];
    }
    else
    {
      ans[b]=(double)dd/v[b];
      ans[c]=(double)dd/v[c];
    }
  }
  else if(v[b]==v[c])
  {
    ans[b]=(double)dd/v[b];
    ans[c]=(double)dd/v[c];
  }
  else // v[b] > v[c]
  {
    double t1=(double)(d[b]+d[c])/v[b];
    double t2=(double)d[c]/v[c];
    if(t1<t2 && w[c]==1)
    {
      ans[c]=(double)dd/v[c];
      double x=(double)v[c]*d[b]/(v[b]-v[c]);
      ans[b]=(double)(d[b]+x+d[a])/v[b]+(double)(d[c]-x)/v[c];
    }
    else if(t1==t2)
    {     
      ans[c]=(double)dd/v[c];
      ans[b]=(double)dd/v[b]; 
    }
    else
    {
      double t3=(double)dd/v[b];
      double t4=(double)(d[c]+d[a])/v[c];
      if(t3<t4 && w[a]==1)
      {
        ans[c]=(double)dd/v[c];
        double y=(double)((double)v[c]*d[b]+(double)(v[c]-v[b])*d[c])/(v[b]-v[c]);
        ans[b]=(double)(d[b]+d[c]+y)/v[b]+(double)(d[a]-y)/v[c];
      }
      else
      {
        ans[c]=(double)dd/v[c];
        ans[b]=(double)dd/v[b];
      }
    }
  }
  for(int i=1; i<=3; i++)
  {
    if(v[i]==(double)0) cout<<"-"<<endl;
    else cout<<ans[i]<<endl;
  }
  return 0;
}