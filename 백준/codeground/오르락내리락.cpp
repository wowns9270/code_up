CODEGROUND
KOR ENG난한다 MyGround 로그아웃
About
Practice
OpenRound
Community
SCPC
Home MyGround Practice
MyGround
Point

Practice

OpenRound

SCPC

My Info
문제명	언어	결과	수행시간	메모리	점수	제출코드	공개여부	추천수	제출일시
오르락 내리락
C++ 14	Pass	0.61009	20332	100	Code	비공개	0	2020 - 02 - 28 04:01
오르락 내리락
C++ 14	Fail	0.00835	20328	0	Code	비공개	0	2020 - 02 - 28 03 : 57
오르락 내리락
C++ 14	Fail	0.00954	20328	0	Code	비공개	0	2020 - 02 - 28 03 : 54
오르락 내리락
C++ 14	Fail	0.00924	20328	0	Code	비공개	0	2020 - 02 - 28 03 : 43
방속의 거울
C++ 14	Pass	0.16519	17412	100	Code	비공개	0	2020 - 02 - 28 02 : 41
방속의 거울
C++ 14	Pass	0.00596	12520	5	Code	비공개	0	2020 - 02 - 28 02 : 40
개구리 뛰기
C++ 14	Pass	0.51185	16620	100	Code	비공개	0	2020 - 02 - 28 01 : 46
개구리 뛰기
C++ 14	Pass	0.52905	16620	20	Code	비공개	0	2020 - 02 - 28 01 : 43
시험 공부
C++ 14	Pass	0.12371	14572	100	Code	비공개	0	2020 - 02 - 28 00 : 01
시험 공부
C++ 14	Pass	0.12728	14572	33	Code	비공개	0	2020 - 02 - 27 23 : 57
Previous123Next
SAMSUNG
개인정보처리방침 이용약관 이메일무단수집거부
Google Chrome 브라우저를 권장합니다.(Internet Explorer 11 지원)
본 사이트의 콘텐츠는 저작권법의 보호를 받는바, 무단전제, 복사, 배포 등을 금합니다.
Copyrightⓒ 2015 - 2020 SAMSUNG ALL Rights Reserved.

Top 바로가기
×
제출코드
#include<bits/stdc++.h>
using namespace std;

int test, t_n = 1;
int dp[1000001];
int sum[1000001];
int main() {
	cin >> test;

	dp[1] = 0;
	dp[2] = 1;
	for (int i = 4; i <= 1000000; i += 2) {

		dp[i] = dp[i / 2] + 1;
		dp[i - 1] = dp[i] + 1;
	}
	sum[0] = 0;
	for (int i = 1; i <= 1000000; i++) {
		sum[i] = sum[i - 1] + dp[i];
	}



	while (test--) {
		int ret = 0;
		int a, b; cin >> a >> b;

		ret = sum[b] - sum[a - 1];


		cout << "Case #" << t_n++ << "\n";
		cout << ret << "\n";
	}
	return 0;
}