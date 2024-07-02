#include<iostream>
#include<vector>
#include<string>
using namespace std;

int r,c,k;

vector<string> arr;
int check[6][6];

int dx[] ={1,0,-1,0 };
int dy[] ={0,1,0,-1 };

int gogo(int x, int y , int cnt)
{

    if(cnt > k ) return 0;

    if(cnt == k && x == 0 && y == c-1 )
    {
        return 1;
    }

    int ret =0;
    check[x][y] = 1; 
    for(int i=0; i<4; i++)
    {
        int ux = x + dx[i];
        int uy = y + dy[i];

        if(ux<0 || uy <0 || ux >=r || uy>=c) continue;
        if(arr[ux][uy] == 'T') continue;

        if(check[ux][uy] == 0)
        {
            check[ux][uy] = 1; 
            ret += gogo(ux,uy, cnt +1);
            check[ux][uy] = 0;
        }
    }
    check[x][y] = 0;

    return ret;
}

int main()
{
    cin>>r>>c>>k;

    for(int i=0; i<r; i++)
    {
        string k; cin>> k;
        arr.push_back(k);
    }

    cout << gogo(r-1, 0, 1 );
}