/*
题目描述
函数match检查字符串str是否匹配模板pattern，匹配则返回0，否则返回-1。模板支持普通字符(a-z0-9A-Z)及通配符`?`和`*`。普通字符匹配该字符本身，`?`匹配任意一个字符，`*`匹配任意多个任意字符。比如字符串abc对下述模板的匹配结果为：

| 模板 | 结果 | 模板 | 结果 |
|------|------|------|------|
| abc  | 0    | a*b  | -1   |
| a*   | 0    | ab?  | 0    |
| a*c  | 0    | a?   | -1   |

提示：可以采用递归方法实现


输入
第一行为待匹配串

第二行为模板串

输出
匹配成功输出:match

匹配不成功输出：unmatch

样例输入
abc
a*c
样例输出
match
*/
#include<string>
#include<iostream>
using namespace std;
#define MAX_SIZE 1000
bool dp[MAX_SIZE][MAX_SIZE];
int main(){
	int i, j;
	string Str1, Str2;
	cin >> Str1 >> Str2;
	dp[0][0] = true;

	for(i = 0; i < Str2.size(); i++){
		if(Str2[i] == '*'){
			dp[0][i + 1] = true;
		}
		else break;
	}

	for(i = 0; i < Str1.size(); i++){
		for(j = 0; j < Str2.size(); j++){
			if(Str2[j] == Str1[i] || Str2[j] == '?'){
				dp[i+1][j+1] = dp[i][j];
				continue;
			}
			else if(Str2[j] == '*'){
				dp[i+1][j+1] = dp[i][j] | dp[i][j+1] | dp[i+1][j];
				continue;
			}
			dp[i+1][j+1] = false;
		}
	}

	if(dp[Str1.size()][Str2.size()] == true) cout<<"match"<<endl;
	else cout<<"unmatch"<<endl;
	return 0;
}
