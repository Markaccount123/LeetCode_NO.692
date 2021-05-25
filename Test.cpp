#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		//count 2 word 2 love 3 string 4 
		//count 2 love 3 string 4 word 2
		//这一步可以帮我们统计出来每个单词出现的次数，并且默认的帮我们按照ASCII进行了排序
		map<string, int> CountMap;
		//这样就可以统计出来每个单词出现的次数
		for (auto& e : words)
		{
			CountMap[e]++;
		}

		//multimap是允许出现重复的K值的,此时就相当于帮我们进行了一个出现次数多少的排序
		//multimap<int,string,lesser<int>> 默认的仿函数比较用的是lesser
		multimap<int, string, greater<int>> sortMap;
		for (auto& e : CountMap)
		{
			sortMap.insert(make_pair(e.second, e.first));
		}

		vector<string> v;
		auto it = sortMap.begin();
		while (k--)
		{
			v.push_back(it->second);
			++it;
		}
		return v;
	}
};
