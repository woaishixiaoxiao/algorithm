/*
��Ŀ����
��֪ĳһ����ĸ���У��������е���ĸ������˳��ѹ��һ��ջ������ջ����������У�����ջ�е���ĸ��ջ�������п��ܵĳ�ջ˳��

��ʾ�������õݹ鷽��ʵ�֡�

����
�ַ������磺abcdefg

���
ÿ��һ�����ܵ�����ַ���
��������
abc
�������
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
//q �����ջ����
//stk ����ģ����ջ����
//output ���ڴ�ſ��ܵĳ�ջ����
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
    if(q.size()!=0){//��ջ
        int v = q.top();   
        stk.push(v);   
        q.pop();
        allPopSeq(q,stk,output,sz);
        stk.pop();
        q.push(v);//���ݻָ�
		/*
        cout<<"the "<<i<<" after: "<<endl;
    	print_stack(q, 'q');
    	print_stack(stk, 's');
    	print_stack(output,'o');
		*/
    }
    if(stk.size()!=0) //��ջ
    {
        int v = stk.top();
        stk.pop();
        output.push_back(v);
        allPopSeq(q,stk,output,sz);
        //output.pop();
        //stk.push(v);//���ݻָ�
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