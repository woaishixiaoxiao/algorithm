//剑指OFFER中，数组中出现次数超过一半的数 
//在数组中找到出现次数大于N/K的所有数（515），将数组化为K个为一组，一共划分成N/K个组(最后可能会有剩余)，
//可以这么想如果找所有的数，这个数出现次数等于N/K，那么，要满足的条件是，N/K取整数，每组中所有的数应该不一样，
//那么大于N/K次的话，就应该是余数组中应该出现之前的组中的数。或者，就分不成N/K组个不同的数（因为假设每组的数不一样）
//可以分成N/K组，但是将某个组中的某个数换成这个组中另一个已经存在的数，那么这个数就肯定大于N/K了，但是这样划分是不行的。
//现在问题就是找不同的数将他们分成一组，用消的方法，有K-1个候选数,相应有K-1个出现的次数。之后将第K个数和K-1个数作比较，如果都不相同
//就将K-1个数的次数-1，如果出现次数为0，那么就要新加入新的候选元素。如果第K个数和K-1中某个数一样，那么就将这个数出现次数加一。 
// 这样就达到了K个不同的数一消的目的，而且相同的数加一，但是如果最后候选的元素的次数不为0，也不一定就是出现大于N/K的数，因为可能N/K不为整数，
//为余数。所以最好要检验一下 
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
void printMultiMajor(vector<int>&ivec,vector<int>&res,int &k){
	if(ivec.empty())return;
	unordered_map<int,int>u_map;
	for(int i=0;i<ivec.size();i++){
		int temp=ivec[i];
		if(u_map.size()<k){
			if(u_map.find(temp)==u_map.end()){
				u_map[temp]=1;
			}else{
				u_map[temp]++;
			}
		}else{
			if(u_map.size()==k){
				if(u_map.find(temp)==u_map.end()){
					for(auto e=u_map.begin();e!=u_map.end();){
						(e->second)--;
						if(e->second==0){
							auto temp=e;//这里注意，下次再遍历容器的时候在遇到删除，先将下一个记录下来，肯定不会有错误的 
							e++;
							u_map.erase(temp->first);
						}else{
							e++;
						}
					}
					/*for(auto e:u_map){
						e.second--;
						if(e.second==0){
							u_map.erase(e.first);
						}
					}*/
				}else{
					u_map[temp]++;
				}
			}else{
				exit(0);
			}
		}
	}
	for(auto &e:u_map){//还有这里一定要用引用啊！！！ 
		e.second=0;
	}
	for(int i=0;i<ivec.size();i++){
		int temp=ivec[i];
		if(u_map.find(temp)!=u_map.end()){
			u_map[temp]++;
		}
	} 
	int len=ivec.size()/k+1;
	for(auto e:u_map){
		if(e.second>len){
			int number=e.first;
			res.push_back(number);
		}
	}		
}
main(){
	vector<int>ivec={1,3,1,9,9,1,9,6};
	vector<int>res;
	int k;
	cin>>k;
	printMultiMajor(ivec,res,k);
	for_each(res.begin(),res.end(),[](int &s){cout<<s<" ";});
}
