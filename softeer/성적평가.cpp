

// 성적평가  3:23

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

vector < pair<int, int>> test1;  // a번째 사람의 대회에서 점수
vector < pair<int, int>> test2;
vector < pair<int, int>> test3;
vector < pair<int, int>> sum;

vector<int> test1_;
vector<int> test2_;
vector<int> test3_;
vector<int> sum_;

void calc(vector<pair<int,int>> &test, vector<int> &ret)
{
	// 정렬 

	std::sort(test.begin(), test.end(), [](const pair<int, int> tmp1, const pair<int, int> tmp2) -> bool {
		return tmp1.second > tmp2.second;
		});


	for (int i = 0; i < test.size(); i++)
	{
		if (i == 0)
		{
			ret[test[i].first] = 1; // 1등
		}
		else
		{
			if (test[i].second == test[i - 1].second)
			{
				//점수가 똑같다면 
				ret[test[i].first] = ret[test[i - 1].first];
			}
			else
			{
				ret[test[i].first] = i + 1; // 작은등수
			}
		}
	}
}


int main()
{

	cin >> n;
	test1.resize(n );  // a번째 사람의 대회에서 점수
	test2.resize(n);
	test3.resize(n);
	sum.resize(n );

	test1_.resize(n );
	test2_.resize(n );
	test3_.resize(n );
	sum_.resize(n );

	for (int i = 0; i < n; i++)
	{
		int score; cin >> score;

		test1[i] = { i, score };
		sum[i].first = i;
		sum[i].second += score;
	}

	for (int i = 0; i < n; i++)
	{
		int score; cin >> score;

		test2[i] = { i, score };
		sum[i].first = i;
		sum[i].second += score;
	}

	for (int i = 0; i < n; i++)
	{
		int score; cin >> score;

		test3[i] = { i, score };
		sum[i].first = i;
		sum[i].second += score;
	}

	// 정렬 
	calc(test1, test1_);
	calc(test2, test2_);
	calc(test3, test3_);
	calc(sum, sum_);

	for (const auto& ret : test1_)
	{
		std::cout << ret << " ";
	}
	std::cout << std::endl;
	
	for (const auto& ret : test2_)
	{
		std::cout << ret << " ";
	}
	std::cout << std::endl;
	for (const auto& ret : test3_)
	{
		std::cout << ret << " ";
	}
	std::cout << std::endl;
	for (const auto& ret : sum_)
	{
		std::cout << ret << " ";
	}
}