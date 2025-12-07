#include<bits/stdc++.h>

using namespace std;

int p[1000001];

int Find(int x)
{
  if(p[x] < 0)
  {
    return x;
  }
  else
  {
    return p[x] = Find(p[x]);
  }
}

void Union(int x,int y)
{
  int g1 = Find(x);
  int g2 = Find(y);

  if(g1 == g2)
  {
    return;
  }

  if(-p[g1] < -p[g2])
  {
    swap(g1,g2);
  }
  p[g1] += p[g2];
  p[g2] = g1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,q;
  cin>>n>>q;

  for(int i=0;i<1000001;i++)
  {
    p[i] = -1;
  }

  for(int i=0;i<q;i++)
  {
    string s;
    cin>>s;
    int a,b;
    cin>>a>>b;
    if(s == "?")
    {
      int find1 = Find(a);
      int find2 = Find(b);
      if(find1 == find2)
      {
        cout<<"yes\n";
      }
      else if(find1 != find2)
      {
        cout<<"no\n";
      }
    }
    else if(s == "=")
    {
      Union(a,b);
    }
  }
  return 0;
}
