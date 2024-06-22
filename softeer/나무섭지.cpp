#include<iostream>
#include<vector>
#include<string>
#include<queue>



using namespace std;
vector<string> arr;
int n, m;

int st, ed;
int g_st, g_ed;
int g_ret = false;
vector<pair<int, int>> urang;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

struct obj
{
    int x; int y; int status;
};
int check[1001][1001];

void gogo(int x, int y)
{
    check[x][y] = 1;

    queue<obj> q;
    q.push({ x,y, 0 });

    for (int i = 0; i < urang.size(); i++)
    {
        q.push({ urang[i].first, urang[i].second, 1 });
    }

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int status = q.front().status;
        q.pop();

        if (x == g_st && y == g_ed && status == 0)
        { // 도착했을 경우,
            g_ret = true;
            break;
        }

        if (status == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                int ux = x + dx[i];
                int uy = y + dy[i];
                if (ux < 0 || uy < 0 || ux >= n || uy >= m) continue;
                if (arr[ux][uy] == '#') continue;
                if (check[ux][uy] == 1 || check[ux][uy] == 2) continue;

                check[ux][uy] = 1;
                q.push({ ux,uy, 0 });
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int ux = x + dx[i];
                int uy = y + dy[i];

                if (ux < 0 || uy < 0 || ux >= n || uy >= m) continue;
                if (check[ux][uy] != 2)
                {
                    check[ux][uy] = 2;
                    q.push({ ux,uy,1 });
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
        string a; cin >> a;
        arr.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'N')
            {
                st = i, ed = j;
            }
            else if (arr[i][j] == 'G')
            {
                urang.push_back({ i,j });
            }
            else if (arr[i][j] == 'D')
            {
                g_st = i, g_ed = j;
            }
        }
    }

    gogo(st, ed);

    if (g_ret == true)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}