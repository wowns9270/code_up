#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int arr[21][26];
bool check[26];
int max_ret;

vector<string>ret;
vector<string>sub_ret;
vector<int> temp;

void gogo(int idx , int cnt , int k , int n) {

    if (cnt == k) { //°³¼ö¸¸Å­°ñ¶úÀ¸´Ï±î
        int cnt_n = 0;
        for (int i = 0; i < n; i++) {

            bool check = true;
            for (int j = 0; j < temp.size(); j++ ) {

                if (arr[i][temp[j]] != 1) {
                    check = false;
                    break;
                }
            }

            if (check == true) cnt_n++;
        }
           
        if (cnt_n > max_ret && cnt_n >=2) {
                max_ret = cnt_n;
                sub_ret.clear();
                string ret_temp ="";
                for (int i = 0; i < temp.size(); i++) {

                    ret_temp += 'A' + temp[i];
                }
                sub_ret.push_back(ret_temp);
        }
        else if (cnt_n == max_ret && cnt_n >= 2) {
            string ret_temp = "";
            for (int i = 0; i < temp.size(); i++) {

                ret_temp += 'A' + temp[i];
            }
            sub_ret.push_back(ret_temp);
        }
        return;
    }

    if (idx >= 26) return;

     check[idx] = true;
     temp.push_back(idx);
     gogo(idx + 1, cnt + 1, k, n);
     temp.pop_back();
     check[idx] = false;
     gogo(idx + 1, cnt, k, n);
        

}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < orders[i].size(); j++) {
            arr[i][orders[i][j] - 'A'] = 1;
        }
    }

    for (int i = 0; i < course.size(); i++) {

        int k = course[i];
        max_ret = 0;

        gogo(0 , 0, k ,orders.size());

        for (int j = 0; j < sub_ret.size(); j++) {
            ret.push_back(sub_ret[j]);
        }
        sub_ret.clear();

    }

    sort(ret.begin(), ret.end());

    return ret;
}

int main() {
    solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
}