//程序读取一个表达式，并输出用字符6拼出的计算结果。相邻数字使用两个
//英文句号“。”相隔
//第一行为一个整数n，接下来的n行,每行一个表达式
//30%的数据，表达式仅包含"6“，”+“，”-“三种字符
//对于100%的数据，表达式仅包含'6','+','-'，'*'，四中字符
//1<=n<100，表达式长度不超过100，计算中间结果在【-2^63,2^63-1],
//最终结果在[0-2^63-1]范围内
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
//遇到的问题是，将中缀变成后缀的时候，需要加一个字符'#"将两个操作数分离,以避免666不知道是一个操作数还是多个的情况 .思路是每次遇到一个操作符的时候，
//说明之前的操作数肯能结束了，那么此时在操作数后面加上'#'，在计算后缀的时候，每次遇到"#"说明上一个操作数结束了。但是有个问题，中缀表达式最后一个肯定是
//操作数，所以需要在for循环结束后，在加个"#".明天来写一个完整的中缀变后缀并且可以求值得。在看看中缀可以直接求值嘛 
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
