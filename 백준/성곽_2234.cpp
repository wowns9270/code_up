#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
int arr[51][51];
int check[51][51];

int dx[] ={0,-1,0,1};
int dy[] ={-1,0,1,0};

int d_val[] = {1,2,4,8};

void gogo(int x,int y, int cnt)
{
    check[x][y] = cnt;
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

            int wall = arr[nx][ny];

            if(ux < 0 || uy <0 || ux>=n || uy >=m ) continue;
            if( (wall & d_val[i]) > 0) continue;
            
            if(check[ux][uy] == 0)
            {
                check[ux][uy] = cnt;
                q.push({ux,uy});
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    for(int i =0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>> arr[i][j];
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(check[i][j] == 0)
            {
                gogo(i,j,++cnt);
            }
        }
    }

    vector<int> ret_arr(cnt + 1);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            ret_arr[check[i][j]]++;

            //cout << check[i][j]  <<" ";
        }
        //cout <<"\n";
    }

    int max_ret =0;
    for(int i=1; i<=cnt; i++)
    {
        max_ret = max(max_ret, ret_arr[i]);
    }

    // 각 방을 부셨을 때 큰값
    int max_action_ret = max_ret;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {

            for(int k=0; k<4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];

                int wall = arr[i][j];
                if(x < 0 || y < 0 || x >=n || y >=m) continue;
                if((wall & d_val[k]) > 0 && check[i][j] != check[x][y])
                {
                    int a = ret_arr[check[i][j]];
                    int b = ret_arr[check[x][y]];
                    max_action_ret = max(max_action_ret, a+b);
                }
            }

        }
    }



    cout << cnt <<"\n";
    cout << max_ret <<"\n"; 
    cout << max_action_ret <<"\n";

}