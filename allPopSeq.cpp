/*
题目描述
已知某一个字母序列，把序列中的字母按出现顺序压入一个栈，在入栈的任意过程中，允许栈中的字母出栈，求所有可能的出栈顺序

提示：可以用递归方法实现。

输入
字符串，如：abcdefg

输出
每行一个可能的输出字符串
样例输入
abc
样例输出
abc
acb
bac
bca
cba
*/
#include <iostream>
#include <stack>
using namespace std;
/*
void print_stack(stack<int>q, char c) {
	stack<int>r_s;
	while(!q.empty()) {
		int tmp = q.top();
		q.pop();
		r_s.push(tmp);
	}
	cout<<c<<": ";
	while(!r_s.empty()) {
		int tmp = r_s.top();
		r_s.pop();
		cout<<tmp<<" ";
	}
	cout<<endl;
}*/
//q 存放入栈序列
//stk 用于模拟入栈过程
//output 用于存放可能的出栈序列
void allPopSeq(stack<char> q, stack<char> stk, string output, int sz){
	/*
	cout<<"the "<<i<<" input: "<<endl;
    print_stack(q, 'q');
    print_stack(stk, 's');
    print_stack(output,'o');
	*/
    if((q.size() == 0)&&(stk.size()==0)&&(output.size() == sz)) {
        cout<<output<<endl;
        return;
    }	
    if(q.size()!=0){//入栈
        int v = q.top();   
        stk.push(v);   
        q.pop();
        allPopSeq(q,stk,output,sz);
        stk.pop();
        q.push(v);//回溯恢复
		/*
        cout<<"the "<<i<<" after: "<<endl;
    	print_stack(q, 'q');
    	print_stack(stk, 's');
    	print_stack(output,'o');
		*/
    }
    if(stk.size()!=0) //出栈
    {
        int v = stk.top();
        stk.pop();
        output.push_back(v);
        allPopSeq(q,stk,output,sz);
        //output.pop();
        //stk.push(v);//回溯恢复
        /*
		cout<<"the "<<i<<" after: "<<endl;
    	print_stack(q, 'q');
    	print_stack(stk, 's');
    	print_stack(output,'o');
		*/
    }
    return;
}
int main(int argc,char** argv){
	int i;
	string str;
	cin>>str;
	int sz = str.size();
    stack<char> stkValues;
    string output;
    stack<char> tmp;
    for(i = sz - 1; i >= 0; --i){
        stkValues.push(str[i]);
    }
    allPopSeq(stkValues,tmp,output,sz);
}