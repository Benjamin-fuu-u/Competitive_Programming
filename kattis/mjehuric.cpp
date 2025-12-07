#include<bits/stdc++.h>

using namespace std;

int main()
{
  int wood[5];
  for(int i=0;i<5;i++)
  {
    cin>>wood[i];
  }

  while(!is_sorted(wood,wood+5))
  {
    for(int i=0;i<4;i++)
    {
      if(wood[i]>wood[i+1])
      {
        swap(wood[i],wood[i+1]);
        for(int j=0;j<5;j++)
        {
          cout<<wood[j]<<" ";
        }
        cout<<"\n";
      }
    }
  }
  return 0;
}
