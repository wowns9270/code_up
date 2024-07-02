#include<iostream>
#include<vector>
using namespace std;

int arr[11][11], n;
int check[11][11];
vector<pair<int,int>> flower;

int ret = 1e9;

int dx[] ={1,0,-1,0};
int dy[] ={0,1,0,-1};


int calc()
{
    int sum = 0; 
    for(int i=0; i<n; i++  )
    {
        for(int j=0; j<n; j++)
        {
            if(check[i][j] == 1)
            {
                sum +=arr[i][j];
            }
        }
    }
    return sum;
}

bool checking(int x, int y )
{
    if(check[x][y] == 1 ) return false;

    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(check[nx][ny] == 1)
        {
            return false;
        }
    }
    return true;
}

void checked(int x, int y, int val)
{
    check[x][y] = val; 
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        check[nx][ny] = val; 
    }
}

void gogo(int idx, int n)
{

    if(n == 3)
    {
        int sum = calc();
        ret = min(ret, sum);
        return ;
    }

    for(int i=idx; i<flower.size(); i++)
    {
        int x = flower[i].first;
        int y = flower[i].second;
        if(checking(x,y))
        {
            checked(x,y, 1);
            gogo(idx + 1, n + 1);
            checked(x,y,0);
        }
    }

}

int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=1; i< n-1; i++)
    {
        for(int j=1; j<n-1; j++)
        {
            flower.push_back({i,j});
        }
    }

    gogo(0,0);

    cout << ret;
}