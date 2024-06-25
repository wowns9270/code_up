#include<iostream>
#include<vector>
#include<queue>


using namespace std;

int n;
int check[200002];
vector<pair<int, char>> car;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

queue<int> north;
queue<int> east;
queue<int> south;
queue<int> west;

void processing(int time)
{
    bool bnorth = false;
    bool beast = false;
    bool bsouth = false;
    bool bwest = false;

    if (!north.empty())
    {
        if (west.empty())
        {
            int x = north.front();
            check[x] = time;

            bnorth = true;
        }
    }

    if (!east.empty())
    {
        if (north.empty())
        {
            int x = east.front();
            check[x] = time;

            beast = true;
        }
    }

    if (!south.empty())
    {
        if (east.empty())
        {
            int x = south.front();
            check[x] = time;

            bsouth = true;
        }
    }

    if (!west.empty())
    {
        if (south.empty())
        {
            int x = west.front();
            check[x] = time;

            bwest = true;
        }
    }

    if (bnorth == true) north.pop();
    if (beast == true) east.pop();
    if (bsouth == true) south.pop();
    if (bwest == true) west.pop();
}

int main(int argc, char** argv)
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a; char b; cin >> a >> b;
        car.push_back({ a,b });
        check[i] = -1;
    }

    int time = car[0].first;

    int idx = 0;
    while (1)
    {
        if (north.empty() && east.empty() && south.empty() && west.empty() && idx >= n)
        {
            break;
        }

        for (int i = idx; i < n; i++) // 시간에 해당하는 차는 대기상태로 저장 
        {
            if (car[i].first == time)
            {
                if (car[i].second == 'A')
                {
                    north.push(i);
                }
                else if (car[i].second == 'B')
                {
                    east.push(i);
                }
                else if (car[i].second == 'C')
                {
                    south.push(i);
                }
                else
                {
                    west.push(i);
                }
                idx = i + 1;

            }
            else
            {
                break;
            }
        }



        if (north.empty() && east.empty() && south.empty() && west.empty())
        {
            time = car[idx].first;
        }
        else
        {
            processing(time);

            time = time + 1;
        }

        if (!north.empty() && !east.empty() && !south.empty() && !west.empty())
        {
            break;
        }

    }


    for (int i = 0; i < n; i++)
    {
        cout << check[i] << "\n";
    }




}