#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n , m , a , c, x;
    cin>>n>>m>>a>>c>>x;
    vector<long long int> arr;

    arr.push_back(x);

    for(long long int i=1;i<=n;i++)
    {
        arr.push_back( (a * arr[i-1] + c) % m );
        //cout<<arr[i]<<endl;
        //cout<<a<<" "<<arr[i-1]<<" "<<m<<" "<<arr[i]<<endl;
    }
    //cout<<endl;
    long long int ans = 0;

    for(long long int i=1;i<=n;i++)
    {
        long long int goal = arr[i];
        long long int left = 1;
        long long int right = n;
        //cout<<i<<endl;
        while(left <= right)
        {

            long long int mid = (left + right) / 2;
            //cout<<mid<<endl;

            if(arr[mid] == goal)
            {
                ans++;
                //cout<<arr[i]<<endl;
                //cout<<endl;
                break;
            }

            else if(arr[mid] > goal)
            {
                right = mid  - 1;
            }

            else if(arr[mid] < goal)
            {
                left = mid + 1;
            }
        }
    }

    cout<<ans<<"\n";
    return 0;
}
