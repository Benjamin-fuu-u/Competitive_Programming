#include<bits/stdc++.h>

using namespace std;

int main()
{
  int goal;
  cin>>goal;
  goal*=2;
  int ans=0;
  stack<int> sockspiale;
  for(int i=0;i<goal;i++)
  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sock;
    cin>>sock;
    if(sockspiale.size()>0)
    {
      if(sockspiale.top() == sock)
      {
        ans++;
        sockspiale.pop();
      }
      else
      {
        ans++;
        sockspiale.push(sock);
      }
    }
    else
    {
      ans++;
      sockspiale.push(sock);
    }
  }

  if(sockspiale.size()!=0)
  {
    cout<<"impossible";
  }
  else
  {
    cout<<ans;
  }
  return 0;
}
