#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll b[5000001];
void update(ll x,ll d)
{
  while(x < n)
  {
    b[x]+=d;
    //cout<<x<<" "<<d<<endl;
    x+=x&(-x);
  }
}

ll query(ll x)
{
  ll retur = 0;
  while(x > 0)
  {
    retur+=b[x];
    x-=x&(-x);
  }
  return retur;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll q;
  cin>>n>>q;
  n++;
  for(ll i=0;i<q;i++)
  {
    string s;
    cin>>s;
    if(s == "?")
    {
      ll x;
      cin>>x;
      x++;                              // x++,x-2
      ll ans = query(x-1);  // search for x-1
      cout<<ans<<"\n";
    }
    else if(s == "+")
    {
      ll x,d;
      cin>>x>>d;
      x++;
      update(x,d);
    }
  }
  return 0;
}
