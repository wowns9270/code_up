#include<bits/stdc++.h>
using namespace std;


char k[] = { '+','-','*' };
vector<int> t = { 0,1,2 };

long long temp = 0;
long long ret = 0;

vector<long long> num;
vector<char> oper;

long long gogo() {


    vector<long long> copy_num = num;
    vector<char> copy_oper = oper;

    for (int i = 0; i < 3; i++) {

        char kk = k[t[i]]; //우선순위 문자


        for (int j = 0; j < copy_oper.size(); j++) {

            if (kk != copy_oper[j]) continue;
            else {
                if (kk == '+') {
                    copy_num[j] = copy_num[j] + copy_num[j + 1];
                    copy_num.erase(copy_num.begin() + j + 1);
                    copy_oper.erase(copy_oper.begin() + j);
                }
                else if (kk == '-') {

                    copy_num[j] = copy_num[j] - copy_num[j + 1];
                    copy_num.erase(copy_num.begin() + j + 1);
                    copy_oper.erase(copy_oper.begin() + j);
                }
                else {

                    copy_num[j] = copy_num[j] * copy_num[j + 1];
                    copy_num.erase(copy_num.begin() + j + 1);
                    copy_oper.erase(copy_oper.begin() + j);
                }
                j--;
            }
        }
    }

    if (copy_num[0] < 0) return -copy_num[0];

    return copy_num[0];

}


long long solution(string expression) {

    string part = "";

    for (int i = 0; i < expression.size(); i++) {

        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            long long k = atol(part.c_str());
            num.push_back(k);
            part = "";
            oper.push_back(expression[i]);
        }
        else {
            part += expression[i];
        }
    }
    num.push_back(atol(part.c_str()));


    do {

        long long temp = gogo();


        ret = max(ret, temp);

    } while (next_permutation(t.begin(), t.end()));

    return ret;
}

//int main() {
//    cout << solution("100-200*300-500+20");
//}