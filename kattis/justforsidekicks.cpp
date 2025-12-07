#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
ll gem[7][200001];

void update(ll kind,ll location,ll d)
{
  while(location<=n)
  {
    gem[kind][location]+=d;
    location+=location&(-location);
  }
}

ll query(ll kind,ll location)
{
  ll res = 0;
  while(location>0)
  {
    res+=gem[kind][location];
    location-=location&(-location);
    //cout<<kind<<" "<<res<<" "<<location<<endl;
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll q;
  cin>>n>>q;
  ll gem_price[7];
  for(ll i=1;i<=6;i++)
  {
    cin>>gem_price[i];
  }
  string s;
  cin>>s;
  vector<ll> gem_kind;
  gem_kind.push_back(0);
  for(ll i=0;i<s.size();i++)
  {
    char c = s[i];
    ll kind = c - '0';
    update(kind,i+1,1);
    gem_kind.push_back(kind);

  }

  for(ll i=0;i<q;i++)
  {
    ll control;
    cin>>control;
    if(control == 1)
    {
      ll i,t;
      cin>>i>>t;
      update(gem_kind[i],i,-1);
      update(t,i,1);
      gem_kind[i] = t;
    }
    else if(control == 2)
    {
      ll p,v;
      cin>>p>>v;
      gem_price[p] = v;
    }
    else if(control == 3)
    {
      ll l,r;
      cin>>l>>r;
      ll total_value = 0;
      for(ll i=1;i<=6;i++)
      {
        ll num1 = query(i,l-1);
        ll num2 = query(i,r);
        ll sum = num2 - num1;
        //cout<<i<<" "<<sum*gem_price[i]<<"price"<<endl;
        total_value += sum*gem_price[i];
      }
      cout<<total_value<<"\n";
    }
  }
  return 0;
}
