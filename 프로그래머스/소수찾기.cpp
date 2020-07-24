#include <string>
#include <vector>
#include<set>
#include<iostream>

using namespace std;

bool check[9999999];

string ret;
int cnt;
bool check2[8];
set<int> ans;

void gogo(string temp , int cnt) {

    
    if (cnt == temp.size()) {

    if (check[atoi(ret.c_str())] == false) {
        int  kk = atoi(ret.c_str());
        if (ans.count(kk) == 0) {
            ans.insert(kk);
        }
    }
         return;
    }

    for (int i = 0; i < temp.size(); i++) {
        if (check2[i] == false) {
            check2[i] = true;
            ret += temp[i];
            gogo(temp, cnt+1);
            check2[i] = false;
            ret.erase(ret.begin() + ret.size() - 1);
            gogo(temp, cnt+1);
        }
    }



}


int solution(string numbers) {
    int answer = 0;

    check[0] = true;
    check[1] = true;

    for (int i = 2; i <= sqrt(9999999); i++) {

        for (int j = i * i; j < 9999999; j += i) {
            check[j] = true;
        }
    }



    gogo(numbers , 0 );

    answer = ans.size();
    return answer;
}

int main() {
    cout << solution("17");
}