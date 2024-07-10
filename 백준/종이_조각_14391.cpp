#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n,m;
vector<string> arr;

int check[5][5];

int gogo(int x, int y )
{

    if(x >=n || y>=m) return 0;

    //이미 포함된 칸은 넘어간다. 
    int nx = x + (( y + 1 ) / m);
    int ny = ( y + 1 ) % m ; 

    if(check[x][y] == 1)
    {
        return gogo(nx, ny);
    }

    //가로로 간다.
    string tmp = ""; 
    int ret = 0;
    for(int i=y; i< m; i ++)
    {
        check[x][i] = 1;
        tmp += arr[x][i];
        ret = max(ret, gogo(nx,ny) + atoi(tmp.c_str()));
        tmp.pop_back();
        check[x][i] = 0;
    }

    for(int i =x; i < n; i++)
    {
        check[i][y] = 1; 
        tmp+= arr[i][y] ;
        ret = max(ret, gogo(nx, ny) + atoi(tmp.c_str()));
        tmp.pop_back();
        check[i][y] = 0;
    }

    return ret;
}


int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        string a; cin>> a;
        arr.push_back(a);
    }

    cout << gogo(0,0);
}