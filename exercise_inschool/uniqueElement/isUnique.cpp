#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
template<typename T>
bool isUnique(vector<T>&vec)
{
	if(vec.empty())
	{
		return false;
	}
	unordered_set<T>_set;
	for(auto e:vec)
	{
		if(_set.find(e)!=_set.end())
		{
			return false;
		}
		else
		{
			_set.insert(e);
		}
	}
	return true;
}
main(){
	vector<int>ivec={1,2,3,1};
	cout<<isUnique(ivec)<<endl;
}
