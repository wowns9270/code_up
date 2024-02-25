#include<iostream>
#include<stack>


int n;

int arr[5005];


int main()
{

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int a; std::cin >> a; 
		arr[i] = a;
	}

	
	long long ret = 0;
	long long cnt = 0;

	for (int i = 0; i < n; i++)
	{
		
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				cnt++;
			}
			else
			{
				ret += cnt;
			}
		}
		cnt = 0;
	}


	std::cout << ret;

}