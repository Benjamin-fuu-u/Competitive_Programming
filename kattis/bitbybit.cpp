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
    char bit[32];
    fill(bit,bit+32,'?');
    for(int i=0;i<k;i++)
    {
      string s;
      cin>>s;
      if(s=="CLEAR")
      {
        int ctrl;
        cin>>ctrl;
        bit[31-ctrl]='0';
      }
      else if(s=="SET")
      {
        int ctrl;
        cin>>ctrl;
        bit[31-ctrl]='1';
      }
      else if(s=="OR")
      {
        int x,y;
        cin>>x>>y;
        if(bit[31-x]=='1' || bit[31-y]=='1')
        {
          bit[31-x]='1';
        }
        else if(bit[31-x]=='0' && bit[31-y]=='0')
        {
          bit[31-x]='0';
        }
        else if(bit[31-x]=='0' && bit[31-y]=='?' || bit[31-y]=='0' && bit[31-x]=='?')
        {
          bit[31-x]='?';
        }
      }
      else if(s=="AND")
      {
        int x,y;
        cin>>x>>y;
        if(bit[31-x]=='1' && bit[31-y]=='1')
        {
          bit[31-x]='1';
        }
        else if(bit[31-x]=='0' || bit[31-y]=='0')
        {
          bit[31-x]='0';
        }
        else if(bit[31-x]=='1' && bit[31-y]=='?' || bit[31-x]=='?' && bit[31-y]=='1')
        {
          bit[31-x]='?';
        }
        else if(bit[31-x]=='?' && bit[31-y]=='?')
        {
          bit[31-x]='?';
        }
      }
    }
    for(int j=0;j<32;j++)
    {
      cout<<bit[j];
    }
    cout<<"\n";
  }

  return 0;
}
