#include<iostream>
#include<vector>
using namespace std;

struct pp
{
    int number;
    int x, y, ok;
};
vector<pp> list;

int check[10004];
int map[21][21];

int n, m, q;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void order(int a)
{
    bool bret = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != 0)
            {
                bret = false;
                break;
            }
        }
    }

    if (bret == true)
    {
        map[0][0] = a;
        list.push_back({ a,0,0,1 });
        check[a] = 1;
        cout << a << " gets the seat (" << 1 << ", " << 1 << ").\n";
        return;
    }

    int best_x = -1;
    int best_y = -1;
    int best_dist = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != 0) continue;
            bool bret = true;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                if (map[nx][ny] != 0) bret = false;
            }

            if (bret == false) continue;


            // 후보와의 거리중 최대로 먼놈 
            int dist = 1e9;
            for (int k = 0; k < list.size(); k++)
            {
                int nx = list[k].x;
                int ny = list[k].y;
                if (list[k].ok == 0) continue;

                dist = min(dist, abs(i - nx) * abs(i - nx) + abs(j - ny) * abs(j - ny));
            }

            if (dist > best_dist)
            {
                best_x = i;
                best_y = j;
                best_dist = dist;
            }
            else if (dist == best_dist)
            {
                if (best_x > i)
                {
                    best_x = i;
                    best_y = j;
                    best_dist = dist;
                }
                else if (best_x == i)
                {
                    if (best_y > j)
                    {
                        best_x = i;
                        best_y = j;
                        best_dist = dist;
                    }
                }
            }
        }
    }

    if (best_x != -1)
    {
        map[best_x][best_y] = a;
        check[a] = 1;
        list.push_back({ a,best_x,best_y,1 });
        cout << a << " gets the seat (" << best_x + 1 << ", " << best_y + 1 << ").\n";
    }
    else
    {
        cout << "There are no more seats.\n";
    }

}

int main()
{
    cin >> n >> m >> q;

    for (int i = 0; i < q; i++)
    {
        string a; cin >> a;
        int b; cin >> b;

        if (a == "In")
        {
            if (check[b] == 0)
            {
                order(b);
            }
            else if (check[b] == 1)
            {
                cout << b << " already seated.\n";
            }
            else
            {
                cout << b << " already ate lunch.\n";
            }
        }
        else
        {
            if (check[b] == 0)
            {
                cout << b << " didn't eat lunch.\n";
            }
            else if (check[b] == 1)
            {
                int x, y;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (map[i][j] == b)
                        {
                            x = i + 1;
                            y = j + 1;
                            break;
                        }
                    }
                }
                cout << b << " leaves from the seat (" << x << ", " << y << ").\n";

                check[b] = 2;
                map[x - 1][y - 1] = 0;

                for (int i = 0; i < list.size(); i++)
                {
                    if (list[i].number == b) list[i].ok = 0;
                }
            }
            else if (check[b] == 2)
            {
                cout << b << " already left seat.\n";
            }
        }
    }


}