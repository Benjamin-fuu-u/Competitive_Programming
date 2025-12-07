#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    int snapper,bounce;
    cin>>snapper>>bounce;
    int k=1;
    k=(k<<snapper)-1;

    if((bounce & k ) == k)
    {
      cout<<"case #"<<i+1<<": ON\n";
    }
    else if((bounce & k) !=k)
    {
      cout<<"case #"<<i+1<<": OFF\n";
    }
  }
  return 0;
}
