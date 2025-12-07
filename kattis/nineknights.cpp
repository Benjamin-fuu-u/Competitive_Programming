#include<bits/stdc++.h>

using namespace std;


int main()
{
  char board[5][5];
  vector<pair<int,int>> knight;
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
      cin>>board[i][j];
      if(board[i][j]=='k')
      {
        knight.push_back(make_pair(i,j));   //i -- y j -- x
      }
    }
  }


  bool flag=false;
  int dx[4]={-2,-1,1,2};
  int dy[4]={-2,-1,1,2};

  for(int k=0;k<knight.size();k++)
  {
    if(knight.size()!=9)
    {
      cout<<"invalid\n";
      flag=true;
      break;
    }
    for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
      {
        if(i==0 && j==3 || i==3 && j==0 || i==1 && j==2 || i==2 && j==1 || i==j )
        {
          continue;
        }
          if(knight[k].first+dy[i]<0 || knight[k].first+dy[i]>=5 || knight[k].second+dx[j]<0 || knight[k].second+dx[j]>=5)
          {
            continue;
          }
          else if(board[knight[k].first+dy[i]][knight[k].second+dx[j]]=='k')
          {
            cout<<"invalid\n";
            flag=true;
            break;
          }
      }

      if(flag==true)
      {
        break;
      }
    }

    if(flag==true)
    {
      break;
    }
  }

  if(flag==false)
  {
    cout<<"valid\n";
  }
  return 0;
}
