#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void onGetValue(string &math,vector<int>&next){
	next.push_back(-1);
	next.push_back(0);
	/*for(int i=2;i<math.size();i++){
		bool flag=false;
		for(int j=i-1;j>0;){
			int len=next[j];
			if(math[len]==math[i-1]){
				next.push_back(len+1);
				flag=true;
				break;
			}else{
				j=len;
			}
		}
		if(!flag){
			next.push_back(0);
		}
	}*/
	int cn=0;
	int pos=2;
	while(pos<math.size()){
		if(math[pos-1]==math[cn])next[pos++]=++cn;
		else if(cn>0)cn=next[cn];
		else next[pos++]=0;
	}
}
//��next[i]�����math[i-1]�Ǻ� math[cn]��cn����next[i-1]��Ҳ������һ���ַ���ǰ׺�ͺ�׺����ĳ��ȣ�����Ҫ������math[cn-1+1]��math[i-1]��С�Աȣ�
//��������ôpos�����ߣ�ҲҪ����cn�ĳ��ȣ�����++cn(����cn++)�����粻��ȣ���Ҫ����cn�����ǲ�����pos�����Է������������һ��math[i-1]Ӧ���Ǻ�math[0]
//���жԱȣ�cn=1��ʱ��next[cn]=0,����һ����i=1��ʱ��next[i]�Ż�Ϊ0������������i��=1��һ������,next[i]=0����֮����뻹����ȣ���ôpos��Ҫ���£����ҵ�ǰ
//next[pos]=0 ,��ǡ�õ��ǵ�ǰ��cn=0�������ǵ�ǰ��next[pos]
//֮����Ҫ�������Ԥ������Ϊ���ڲ�ƥ���ʱ�򣬲��ǻ����ĳ���Ϊ1����ƥ���ʱ��ǰ�ַ�����ȣ���ô��һ����ʼƥ��ĵط�i+j-next[j]��next����ĺ�����
//��ǰ�ַ�����һ���ַ����ǰ׺�ͺ�׺��i+j��ʾ��ǰƥ�䵽�Ĳ���ȵ��±�,��ͼ���Կ����������������ʱ�򣬵�j=0��ʱ��ҲΪ�������ƶ�һ������next[0]=-1
//������ǰ׺�ͺ�׺�ĳ��Ȳ���ȣ�Ҳ���ǲ��ص����м���������������Щ���ǲ����ܵģ��÷�֤������֤���������Щ�����ܵĻ�����ô��󳤶Ⱥ���С���ȾͲ���֮ǰ�������ô���� 
bool onMath(string &str,string &math,vector<int>&next,int &pos){
	if(str.size()<math.size())return false;
	int j=0;
	for(int i=0;i<str.size();){
		for(;(j<math.size())&&(str[i+j]==math[j]);j++);
		if(j==math.size()){
			pos=i;
			return true;
		}else{
			i=i+j-next[j];
			j=next[j]>0?next[j]:0;
		}
	}
	return false;
}
//ƥ���ʱ��ʱ�临�Ӷ�Ϊ���ΪO(N),NΪ�����ĳ��ȣ�������Ի�ͼ��һ�£�����Ҫ���ǲ����ݣ�(ÿ�λ����i��λ�ã��Լ�j��λ�ã�������λ��ʹ�ò������) 
main(){
	int pos;
	string str="1ab123123ab123";
	string math="123123";
	vector<int>next;
	onGetValue(math,next);
	for_each(next.begin(),next.end(),[](int num){cout<<num<<" ";});
	cout<<endl;
	if(onMath(str,math,next,pos)){
		cout<<pos<<endl;
	}
}
