//�����ȡһ�����ʽ����������ַ�6ƴ���ļ���������������ʹ������
//Ӣ�ľ�š��������
//��һ��Ϊһ������n����������n��,ÿ��һ�����ʽ
//30%�����ݣ����ʽ������"6������+������-�������ַ�
//����100%�����ݣ����ʽ������'6','+','-'��'*'�������ַ�
//1<=n<100�����ʽ���Ȳ�����100�������м����ڡ�-2^63,2^63-1],
//���ս����[0-2^63-1]��Χ��
#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;
void gen(vector<vector<string> >&cvec){
    cvec[0].assign({"66666","6...6","6...6","6...6","66666"});
    cvec[1].assign({"....6","....6","....6","....6","....6"});
    cvec[2].assign({"66666","....6","66666","6....","66666"});
    cvec[3].assign({"66666","....6","66666","....6","66666"});
    cvec[4].assign({"6...6","6...6","66666","....6","....6"});
    cvec[5].assign({"66666","6....","66666","....6","66666"});
    cvec[6].assign({"66666","6....","66666","6...6","66666"});
    cvec[7].assign({"66666","....6","....6","....6","....6"});
    cvec[8].assign({"66666","6...6","66666","6...6","66666"});
    cvec[9].assign({"66666","6...6","66666","....6","66666"});
}
int calcu(string backExpre){
	stack<int>res;
	int sum=0;
	for(int i=0;i<backExpre.size();i++){
		if(backExpre[i]>='0' && backExpre[i]<='9'){
			int num=backExpre[i]-'0';
			sum=sum*10+num;
		}else{
			if(backExpre[i]=='#'){
				//cout<<sum<<endl;
				res.push(sum);
				sum=0;
				continue;
			}
			int rightnum=res.top();
			res.pop();
			int leftnum=res.top();
			res.pop();
			char c=backExpre[i];
			if(c=='+'){
				leftnum+=rightnum;
			}else if(c=='-'){
				leftnum-=rightnum;
			}else{
				leftnum*=rightnum;
			}
			res.push(leftnum);
		}
	}
	return res.top();
}
//�����������ǣ�����׺��ɺ�׺��ʱ����Ҫ��һ���ַ�'#"����������������,�Ա���666��֪����һ�����������Ƕ������� .˼·��ÿ������һ����������ʱ��
//˵��֮ǰ�Ĳ��������ܽ����ˣ���ô��ʱ�ڲ������������'#'���ڼ����׺��ʱ��ÿ������"#"˵����һ�������������ˡ������и����⣬��׺���ʽ���һ���϶���
//��������������Ҫ��forѭ���������ڼӸ�"#".������дһ����������׺���׺���ҿ�����ֵ�á��ڿ�����׺����ֱ����ֵ�� 
int fun(string inExpre){
	string backexpre;
	stack<char>cstack;
	char topStack;
	for(int i=0;i<inExpre.size();i++){ 
		char temp=inExpre[i];  
		if(temp>='0' && temp<='9'){
			backexpre+=temp;
		}else{
			backexpre+='#';
			if(temp=='*'){
				cstack.push(temp);
			}else{
				while(!cstack.empty()){
					char c=cstack.top();
					backexpre+=c;
					cstack.pop();
				}
				cstack.push(temp);
			}
			/*if(cstack.empty()){
				cstack.push(temp);
			}else{
				do{
					topStack=cstack.top();
					if(temp=='*'){
						if(topStack=='*'){
							backExpre+=topStack;
							cstack.pop();
						}else{
							cstack.push(temp);
							break;
						}
					}else{
						while(!cstack.empty()){
							topStack=cstack.top();
							cstack.pop();
							backExpre+=topStack;
						}
						cstack.push(temp);
						break;
					}
				}while(!cstack.empty());	
			}*/
		}
	}
	backexpre+='#';
	while(!cstack.empty()){
		topStack=cstack.top();
		cstack.pop();
		backexpre+=topStack;
	}
	cout<<backexpre<<endl;
	return calcu(backexpre);
}
void print(string &str,vector<vector<string> >&cvec){
    unsigned long res=fun(str);
    vector<int>rvec;
    do{
        int num=res%10;
        rvec.push_back(num);
        res=res/10;
    }while(res);
    for(int i=0;i<5;i++){
        for(int j=rvec.size()-1;j>=0;j--){
            int num=rvec[j];
            cout<<cvec[num][i]<<"..";
        }
        cout<<endl;
    }
}
main(){
    vector<vector<string> >res;
    for(int i=0;i<10;i++){
    	vector<string>cvec;
        res.push_back(cvec);
    }
    gen(res);
    int n;
    cin>>n;
    getchar();
    vector<string>svec;
    for(int i=0;i<n;i++){
        string str;
        getline(cin,str);
        svec.push_back(str);
    }
    for(int i=0;i<svec.size();i++){
        print(svec[i],res);
    }
}
