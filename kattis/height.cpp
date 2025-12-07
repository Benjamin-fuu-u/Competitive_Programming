#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin>>k;
  for(int i=0;i<k;i++)
  {
    int people[20];
    int which_case;
    cin>>which_case;
    for(int j=0;j<20;j++)
    {
      cin>>people[j];
    }
    set<int> line;
    int ans=0;
    for(int j=0;j<20;j++)
    {
      if(j==0)
      {
        line.insert(people[0]);
      }

      else
      {
        bool flag = false;
        auto it = line.begin();
        for(int k=0;k<line.size();k++)
        {
          if(*it>people[j])
          {
            ans+=line.size()-k;
            flag=true;
            line.insert(people[j]);
            break;
          }
          *it++;
        }
        if(flag==false)
        {
          line.insert(people[j]);
        }
      }
    }
    cout<<i+1<<" "<<ans<<"\n";
  }
}
