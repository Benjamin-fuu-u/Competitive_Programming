#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int person,ctrl;
  cin>>person>>ctrl;
  int location=0;
  stack<int> used;
  for(int i=0;i<ctrl;i++)
  {
    //cout<<location<<endl;
    string s;
    cin>>s;
    if(s=="undo")
    {
      int x;
      cin>>x;
      for(int i=0;i<x;i++)
      {
        int modify=used.top();
        used.pop();
        modify*=-1;
        //cout<<"modify "<<modify;
        if(modify>=0)
        {
          location+=modify;
          location=location%person;
        }
        else
        {
          location+=modify%person;
          location=location%person;
          if(location<0)
          {
            location=person+location;
          }
        }
      }
    }
    else
    {
      int use =stoi(s);
      used.push(use);
      if(use>=0)
      {
        location+=use;
        location=location%person;
      }
      else
      {
        location+=use;
        location=location%person;
        if(location<0)
        {
          location=person+location;
        }
      }
    }
  }
  cout<<location;
  return 0;
}
