#include<bits/stdc++.h>
using namespace std;


vector<vector<int> > arr;
vector<int> temp2;
bool check = false;
int idx = 0;
string temp = "";

bool check2[100001];

bool cmp(vector<int> x, vector<int> y) {
    if (x.size() < y.size()) {
        return true;
    }
    return false;

}

vector<int> solution(string s) {
    vector<int> answer;
    for (int i = 1; i < s.size() - 1; i++) {


        if (s[i] == '{') {
            check = true;
        }
        else if (s[i] == ',') {
            if (check == true) {
                temp2.push_back(atoi(temp.c_str()));
                temp = "";
            }
            else {
                arr.push_back(temp2);
                temp2.clear();
            }
        }
        else if (s[i] == '}') {
            temp2.push_back(atoi(temp.c_str()));
            temp = "";
            check = false;
        }
        else {
            temp += s[i];
        }
    }
    arr.push_back(temp2);

    sort(arr.begin(), arr.end(), cmp);


    for (int i = 0; i < arr.size(); i++) {

        for (int j = 0; j < arr[i].size(); j++) {
            if (check2[arr[i][j]] == false) {
                check2[arr[i][j]] = true;
                answer.push_back(arr[i][j]);
            }
        }

    }



    return answer;
}
//
//
//int main() {
//    vector <int> k = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
//    return 0;
//}