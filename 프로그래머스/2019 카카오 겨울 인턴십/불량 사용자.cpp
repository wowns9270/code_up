#include<bits/stdc++.h>

using namespace std;
int ans;
vector<string> temp;

set<vector<string>> q;

bool check[9];

bool checking(vector<string> y) {

    bool check2 = false;
    for (int i = 0; i < temp.size(); i++) {

        if (temp[i].size() != y[i].size()) {
            return false;
        }

        for (int j = 0; j < temp[i].size(); j++) {

            if (y[i][j] != '*' && temp[i][j] != y[i][j]) {
                return false;
            }

        }
    }
    return true;
}

void gogo(int cur, int ret, vector<string> x, vector<string> y) {

    if (cur >= ret) {

        bool k = checking(y);

        if (k == true) {

            vector<string> temp3 = temp;

            sort(temp3.begin(), temp3.end());

            if (q.find(temp3) == q.end()) {
                q.insert(temp3);
                ans++;
            }
            return;
        }
    }

    for (int i = 0; i < x.size(); i++) {

        if (check[i] == false) {
            check[i] = true;
            temp.push_back(x[i]);
            gogo(cur + 1, ret, x, y);
            temp.pop_back();
            check[i] = false;
        }

    }

}


int solution(vector<string> user_id, vector<string> banned_id) {
    int cnt = banned_id.size();
    gogo(0, cnt, user_id, banned_id);
    return ans;
}

//int main() {
//    int k = solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" });
//        return 0;
//}