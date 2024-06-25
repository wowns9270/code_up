#include<iostream>
#include<queue>


using namespace std;

int n, m;
int arr[101][101];
int check[101][101];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool allMelt()
{
    bool bret = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                bret = false;
                break;
            }
        }
    }
    return bret;
}

void checkSpace()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            check[i][j] = 0;
        }
    }

    queue<pair<int, int>> q;
    check[0][0] = 1;
    q.push({ 0,0 });

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ux = x + dx[i];
            int uy = y + dy[i];

            if (ux < 0 || uy < 0 || ux > n || uy > m) continue;
            if (arr[ux][uy] == 1) continue;

            if (check[ux][uy] == 0)
            {
                check[ux][uy] = 1;
                q.push({ ux,uy });
            }
        }

    }
}

int main(int argc, char** argv)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a; cin >> a;
            arr[i][j] = a;
        }
    }

    int ret = 0;
    while (1)
    {
        if (allMelt()) break;

        checkSpace();

        vector<pair<int, int>> ice;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int ux = i + dx[k];
                        int uy = j + dy[k];

                        if (ux < 0 || uy <0 || ux > n || uy >m) continue;

                        if (arr[ux][uy] == 0 && check[ux][uy] == 1)
                        {
                            cnt++;
                        }
                    }

                    if (cnt >= 2) ice.push_back({ i,j });
                }
            }
        }

        for (int i = 0; i < ice.size(); i++)
        {
            arr[ice[i].first][ice[i].second] = 0;
        }
        ret++;
    }

    cout << ret;
}