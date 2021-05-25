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
		//��һ�����԰�����ͳ�Ƴ���ÿ�����ʳ��ֵĴ���������Ĭ�ϵİ����ǰ���ASCII����������
		map<string, int> CountMap;
		//�����Ϳ���ͳ�Ƴ���ÿ�����ʳ��ֵĴ���
		for (auto& e : words)
		{
			CountMap[e]++;
		}

		//multimap����������ظ���Kֵ��,��ʱ���൱�ڰ����ǽ�����һ�����ִ������ٵ�����
		//multimap<int,string,lesser<int>> Ĭ�ϵķº����Ƚ��õ���lesser
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
