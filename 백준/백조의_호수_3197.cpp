#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<memory.h>
using namespace std;

int n,m;
vector<string> arr;
vector<pair<int,int>> man;

int check[1502][1502];
int man_check[1502][1502];

int dx[] ={1,0,-1,0};
int dy[] ={0,1,0,-1};

void goat()
{
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i][j] == 'L')
                {
                    man.push_back({i,j});
                }
            }
        }
}

void gogo(int x, int y )
{
    check[x][y] = 1; 
    queue<pair<int,int>> q; 
    q.push({x,y});


    while(!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int ux = nx + dx[i];
            int uy = ny + dy[i];

            if(ux < 0 || uy <0 || ux>=n ||uy>=m) continue;

            if(check[ux][uy] == 0)
            {
                if (arr[ux][uy] == '.' || arr[ux][uy] == 'L') 
                {
                    check[ux][uy] = 1; 
                    q.push({ux,uy});
                }
                else if(arr[ux][uy] == 'X')
                {
                    check[ux][uy] = 2;
                }
            }
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>> n>> m;

    for(int i=0; i<n; i++)
    {
        string a; cin>> a;
        arr.push_back(a);
    }

    goat();

    int ret = 0;
    while(1)
    {
        memset(check, 0 , sizeof(check));
        gogo(man[0].first, man[0].second);

        if(check[man[1].first][man[1].second] == 1) break;

        gogo(man[1].first, man[1].second);

        for(int i=0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(check[i][j] == 2)
                {
                    arr[i][j] ='.';
                }
            }
        }

        // cout <<"\n";
        // for(int i=0; i<n; i++)
        // {
        //     for(int j =0; j<m; j++)
        //     {
        //         cout << arr[i][j];
        //     }
        //     cout <<"\n";`
        // }
        // cout <<"\n";
        ret++;
    }
    cout << ret;
}