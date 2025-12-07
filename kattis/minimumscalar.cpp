#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long  t;
  cin>>t;
  for(long long  i=0;i<t;i++)
  {
    long long  n;
    cin>>n;
    vector<long long > v1 , v2;
    for(long long  j=0;j<n;j++)
    {
      long long  num;
      cin>>num;
      v1.push_back(num);
    }

    for(long long  j=0;j<n;j++)
    {
      long long  num;
      cin>>num;
      v2.push_back(num);
    }

    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end() , greater<long long >());
    long long  ans = 0;
    for(long long  j=0;j<v1.size();j++)
    {
      ans+=v1[j] * v2[j];
    }
    cout<<"Case #"<<i+1<<": "<<ans<<"\n";
  }
}
