#include<bits/stdc++.h>

using namespace std;

int k;
char picture[101][101];

int find_flies(int start_x,int start_y)
{
    int res=0;
    for(int i=start_y+1;i<start_y+k-1;i++)
    {
        for(int j=start_x+1;j<start_x+k-1;j++)
        {
            if(picture[i][j]=='*')
            {
                //cout<<"Yes"<<endl;
                res++;
            }
        }
    }
    return res;
}

int main()
{
    int r,c;
    cin>>c>>r>>k;

    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>picture[i][j];
        }
    }
    int ans=0;
    int x,y;
    for(int i=0;i<=c-k;i++)
    {
        for(int j=0;j<=r-k;j++)
        {
            //cout<<i<<" "<<j<<endl;
            int check=find_flies(j,i);
            if(ans<check)
            {
                ans=check;
                x=j;
                y=i;
            }
        }
    }
    cout<<ans<<"\n";
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            if((i==y && j==x) || (i==y && j==x+k-1) || (i==y+k-1 && j==x )|| (i==y+k-1 && j==x+k-1))
            {
                cout<<"+";
            }
            else if(i>y && i<y+k-1 && (j==x || j==x+k-1))
            {
                cout<<"|";
            }
            else if(j>x &&j<x+k-1 && (i==y || i==y+k-1))
            {
                cout<<"-";
            }
            else
            {
                cout<<picture[i][j];
            }
        }
        cout<<"\n";
    }

}
