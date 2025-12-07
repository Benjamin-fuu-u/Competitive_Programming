#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  while(cin>>k)
  {
    if(k==0)
    {
      break;
    }
    int pile1=0,pile2=0;
    for(int i=0;i<k;i++)
    {
      string action;
      cin>>action;
      int plant;
      cin>>plant;
      if(action=="DROP")
      {
        pile2+=plant;
        cout<<"DROP 2 "<<plant<<"\n";
      }
      else if(action=="TAKE")
      {
        if(pile1>=plant)
        {
          pile1-=plant;
          cout<<"TAKE 1 "<<plant<<"\n";
        }
        else if(pile1<plant && pile1!=0)
        {
          plant-=pile1;
          cout<<"TAKE 1 "<<pile1<<"\n";
          pile1=0;
          pile1=pile2;
          pile2=0;
          cout<<"MOVE 2->1 "<<pile1<<"\n";
          pile1-=plant;
          cout<<"TAKE 1 "<<plant<<"\n";
        }
        else if(pile1==0)
        {
          pile1=pile2;
          pile2=0;
          cout<<"MOVE 2->1 "<<pile1<<"\n";
          pile1-=plant;
          cout<<"TAKE 1 "<<plant<<"\n";
        }
      }
    }
    cout<<"\n";
  }
  return 0;
}
