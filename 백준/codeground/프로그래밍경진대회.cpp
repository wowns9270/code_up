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
프로그래밍 경진대회
C++ 14	Pass	0.3001	14576	100	Code	비공개	0	2020 - 02 - 27 23:51
프로그래밍 경진대회
C++ 14	Fail	0.28733	14576	0	Code	비공개	0	2020 - 02 - 27 23 : 46
프로그래밍 경진대회
C++ 14	Fail	0.2949	14576	0	Code	비공개	0	2020 - 02 - 27 23 : 42
프로그래밍 경진대회
C++ 14	Fail	0.2987	14576	0	Code	비공개	0	2020 - 02 - 27 23 : 40
프로그래밍 경진대회
C++ 14	Fail	0.29359	14576	0	Code	비공개	0	2020 - 02 - 27 22 : 21
숫자 골라내기
C++ 14	Pass	0.18215	17404	100	Code	비공개	0	2020 - 02 - 27 21 : 35
숫자 골라내기
C++ 14	Pass	0.1028	12520	50	Code	비공개	0	2020 - 02 - 27 21 : 35
숫자 골라내기
C++ 14	Pass	0.09954	12520	100	Code	비공개	0	2020 - 02 - 27 21 : 34
숫자 골라내기
C++ 14	Compile Error	0	0	0	Code	비공개	0	2020 - 02 - 27 21 : 34
숫자 골라내기
C++ 14	Pass	0.09906	12520	100	Code	비공개	0	2020 - 02 - 27 21 : 34
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

int test, t_n = 1, ret;

int main() {
	cin >> test;

	while (test--) {
		ret = 0;
		int n; cin >> n;
		int max_ret = 0;
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			arr.push_back(k);
		}
		sort(arr.begin(), arr.end());


		for (int i = 0; i < n; i++) {
			max_ret = max(max_ret, arr[i] + n - i);
		}

		for (int i = 0; i < n; i++) {
			if (max_ret <= arr[i] + n) {
				ret++;
			}
		}


		cout << "Case #" << t_n++ << "\n";
		cout << ret << "\n";
	}
}