#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin>>k;
  stack <int> card;
  for(int i=0;i<k;i++)
  {
    int num;
    cin>>num;
    if(card.size()>0)
    {
      int check=card.top();
      card.push(num);
      if((check+card.top())%2==0)
      {
        card.pop();
        card.pop();
      }
    }
    else
    {
      card.push(num);
    }
  }
  cout<<card.size();
  return 0;
}
