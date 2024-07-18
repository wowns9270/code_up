#include<iostream>
using namespace std;


int check[2000003];
int arr[100002];
int n;
int main()
{
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];

        check[arr[i]] = 1;
    }

    int sum ; cin>> sum;
    int ret = 0;
    for(int i=0; i<n; i++)
    {
        int ret = sum - arr[i];
        if(ret >0 && check[ret] == 1)
        {
            ret++;
        }
    }

    cout << ret;
    
}