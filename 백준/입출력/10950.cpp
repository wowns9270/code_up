#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int n; scanf("%d", &n);

	while (n--) {
		int a, b; scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}