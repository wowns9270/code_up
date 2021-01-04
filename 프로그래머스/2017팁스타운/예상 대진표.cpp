#include <iostream>
using namespace std;
int solution(int n, int a, int b)
{
    int round = 0;
    while (a != b) {

        if (a % 2 == 1) a += 1;
        if (b % 2 == 1) b += 1;

        a /= 2;
        b /= 2;

        round++;
    }

    return round;
}
//
//int main() {
//    cout<< solution(8, 1, 3);
//
//    return 0;
//}