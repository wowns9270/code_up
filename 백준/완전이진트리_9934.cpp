#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> arr;
int check[(1 << 10)];
int ret = 0;


void gogo(int x)
{
    if(x >= ( 1 << n-1) && x < (1 << n))
    {
        check[x] = arr[ret++];
        return;
    }

    gogo(x * 2 );

    check[x] = arr[ret++];

    gogo(x * 2  + 1) ; 

}

int main()
{
    cin>> n;

    gogo(1);

    for(int i=0; i<n -1 ; i++)
    {
        int k = (1 << i);
        int k_n = ( 1 << i + 1);

        for(int j = k; j <k_n; j++)
        {
            cout << check[j] <<" ";
        }
        cout <<"\n";
    }

}