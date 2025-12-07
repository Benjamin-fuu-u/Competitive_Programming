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
    string operation;
    int length;
    cin>>operation>>length;
    deque<int> arr;

    string s,inner,number;
    cin>>s;
    inner = s.substr(1,s.size()-2);
    stringstream ss(inner);
    while(getline(ss,number,','))
    {
      arr.push_back(stoi(number));
    }

    bool r = false;
    bool jump = false;
    for(int j=0;j<operation.size();j++)
    {
      if(operation[j]=='R')
      {
        r = !r;
      }
      else if(operation[j]=='D')
      {
        if(arr.size()==0)
        {
          cout<<"error";
          jump = true;
          break;
        }

        if(r==false)
        {
          arr.pop_front();
        }
        else if(r==true)
        {
          arr.pop_back();
        }
      }
    }
    if(jump==false)
    {
      cout<<"[";
      bool flag = false;
      while(arr.size()>0)
      {
        if(flag==true)
        {
          cout<<",";
        }
        flag = true;
        if(r==false)
        {
          cout<<arr.front();
          arr.pop_front();
        }
        else if(r==true)
        {
          cout<<arr.back();
          arr.pop_back();
        }
      }
      cout<<"]";
    }
    cout<<"\n";
  }

  return 0;
}
