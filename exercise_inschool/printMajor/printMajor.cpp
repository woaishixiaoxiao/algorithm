//��ָOFFER�У������г��ִ�������һ����� 
//���������ҵ����ִ�������N/K����������515���������黯ΪK��Ϊһ�飬һ�����ֳ�N/K����(�����ܻ���ʣ��)��
//������ô����������е�������������ִ�������N/K����ô��Ҫ����������ǣ�N/Kȡ������ÿ�������е���Ӧ�ò�һ����
//��ô����N/K�εĻ�����Ӧ������������Ӧ�ó���֮ǰ�����е��������ߣ��ͷֲ���N/K�����ͬ��������Ϊ����ÿ�������һ����
//���Էֳ�N/K�飬���ǽ�ĳ�����е�ĳ�����������������һ���Ѿ����ڵ�������ô������Ϳ϶�����N/K�ˣ��������������ǲ��еġ�
//������������Ҳ�ͬ���������Ƿֳ�һ�飬�����ķ�������K-1����ѡ��,��Ӧ��K-1�����ֵĴ�����֮�󽫵�K������K-1�������Ƚϣ����������ͬ
//�ͽ�K-1�����Ĵ���-1��������ִ���Ϊ0����ô��Ҫ�¼����µĺ�ѡԪ�ء������K������K-1��ĳ����һ������ô�ͽ���������ִ�����һ�� 
// �����ʹﵽ��K����ͬ����һ����Ŀ�ģ�������ͬ������һ�������������ѡ��Ԫ�صĴ�����Ϊ0��Ҳ��һ�����ǳ��ִ���N/K��������Ϊ����N/K��Ϊ������
//Ϊ�������������Ҫ����һ�� 
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
							auto temp=e;//����ע�⣬�´��ٱ���������ʱ��������ɾ�����Ƚ���һ����¼�������϶������д���� 
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
	for(auto &e:u_map){//��������һ��Ҫ�����ð������� 
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
