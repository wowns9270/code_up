#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
struct pp
{
    int x, y, type;
};
int n, m;
int st, ed, hole_s, hole_e, ret_s, ret_e;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

vector<string> arr;
vector<pair<int, int>> sonagi;
int check[51][51];
int not_able[51][51];

void gogo(int x, int y)
{
    check[x][y] = 0;
    queue<pp> q;


    for (int i = 0; i < sonagi.size(); i++)
    {
        not_able[sonagi[i].first][sonagi[i].second] = 1;
        q.push({ sonagi[i].first, sonagi[i].second, 1 });
    }
    q.push({ x,y,0 }); // 사람은 0 , 소나기는 1 
    while (!q.empty())
    {
        int nx = q.front().x;
        int ny = q.front().y;
        int type = q.front().type;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ux = nx + dx[i];
            int uy = ny + dy[i];

            if (ux < 0 || uy < 0 || ux >= n || uy >= m) continue;

            if (type == 0) // 사람
            {
                if (arr[ux][uy] == 'X') continue;

                if (not_able[ux][uy] == 1) continue;

                if (check[ux][uy] == 0)
                {
                    check[ux][uy] = check[nx][ny] + 1;
                    q.push({ ux,uy, 0 });
                }
            }
            else // 소나기
            {
                if (arr[ux][uy] == 'X' || arr[ux][uy] == 'H') continue;
                if (not_able[ux][uy] == 0)
                {
                    not_able[ux][uy] = 1;
                    q.push({ ux,uy, 1 });
                }
            }

        }

    }


}

int main(int argc, char** argv)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        arr.push_back(s);
    }

    // w -> h 로 소나기 *, 강 x 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'W')
            {
                st = i, ed = j;
            }
            else if (arr[i][j] == 'H')
            {
                ret_s = i, ret_e = j;
            }
            else if (arr[i][j] == '*')
            {
                sonagi.push_back({ i,j });
            }
        }
    }

    gogo(st, ed);

    if (check[ret_s][ret_e] == 0)
    {
        cout << "FAIL\n";
    }
    else
    {
        cout << check[ret_s][ret_e];
    }

    return 0;
}