#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    deque<int> now_card;
    int last;
    cin>>last;


    for(int j=last;j>=1;j--)
    {
      now_card.push_front(j);
      for(int k=0;k<j;k++)
      {
        now_card.push_front(now_card.back());
        now_card.pop_back();
      }
    }
    int Size  = now_card.size();
    for(int k=0;k<Size;k++)
    {
      cout<<now_card.front()<<" ";
      now_card.pop_front();
    }
    cout<<"\n";
  }
  return 0;
}
