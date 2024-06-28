#include<iostream>
#include<stack>
using namespace std;

int n;
int arr[1000003];
int dp[1000003];

int main()
{
    cin>> n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    stack<int> st;

    for(int i= n-1; i>=0 ; i--)
    {
        if(st.empty())
        {
            dp[i] = -1 ;
            st.push(arr[i]);
            continue;
        }

        while(!st.empty())
        {
            if(st.top() <= arr[i])
            {
                st.pop();
            }
            else
            {
                dp[i] = st.top();
                st.push(arr[i]);
                break;
            }
        }

        if(st.empty())
        {
            dp[i] = -1;
            st.push(arr[i]);
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << dp[i] <<" ";
    }

    return 0;
}