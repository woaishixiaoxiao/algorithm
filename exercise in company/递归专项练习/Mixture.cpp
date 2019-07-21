/*
A、B和C。如果C包含且仅包含来自A和B的所有字符，而且在C中属于A的字符之间保持原来在A中的顺序，属于B的字符之间保持原来在B中的顺序，那么称C是A和B的混编。实现一个函数，判断C是否是A和B的混编。

给定三个字符串A,B和C，及他们的长度。请返回一个bool值，代表C是否是A和B的混编。保证三个串的长度均小于等于100。

测试样例：
"ABC",3,"12C",3,"A12BCC",6
返回：true
*/
#include<iostream>
using namespace std;
class Mixture {
public:
	/*
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
        if(n + m != v) return false;
        int str1_pos = 0, str2_pos = 0;
        /*
        for(int i = 0; i < v && str1_pos < n && str2_pos < m; i++) {   //不应该写到这里，因为虽然有一个停止了 但是其他的可能需要继续遍历，所以改成下面那种 
            if(C[i] == A[str1_pos]){
                ++str1_pos;
            }else if(C[i] == B[str2_pos])
            {
                ++str2_pos;
            }else {
                return false;
            }
        }
        */
        /*
        for(int i = 0; i < v; i++) {
            if(str1_pos < n && C[i] == A[str1_pos]){
                ++str1_pos;
            }else if(str2_pos < m && C[i] == B[str2_pos])
            {
                ++str2_pos;
            }else {
                return false;
            }
        }
        if(!(str2_pos == m && str1_pos == n)) return false;
        return true;
    }
    */
    //上述做法是有问题的，主要是当遇到了A中可以和C当前匹配，B中也可以，此时不知道是和A还是和B去匹配。
	//递归的方法 当出现 上面的问题时候，递归方法会有重叠子问题 
	/*
	bool chkMixture(string A, int n, string B, int m, string C, int v) {
		if(n + m != v) return false;
		return chkMixture_recu(A, 0, n, B, 0, m, C, 0, v);
	}
	bool chkMixture_recu(string A, int pos1, int n, string B, int pos2, int m, string C, int pos3, int v) {
		if(pos1 == n && pos2 == m && pos3 == v) return true;
		if(pos1 < n && pos2 < m && pos3 < v && A[pos1] == B[pos2] && A[pos1] == C[pos3]) { 
			//这里要么传下去的是A的子数组，pos1不变，要么传递的是A不变，pos+1 
			//return (chkMixture_recu(A.substr(pos1 + 1, n), pos1 + 1, n, B, pos2, m, C.substr(pos3 + 1, v), pos3 + 1, v) || chkMixture_recu(A, pos1 + 1, n, B.substr(pos2 + 1, m), pos2 + 1, m, C.substr(pos3 + 1, v), pos3 + 1, v));
			return (chkMixture_recu(A, pos1 + 1, n, B, pos2, m, C, pos3 + 1, v) || chkMixture_recu(A, pos1, n, B, pos2 + 1, m, C, pos3 + 1, v));
		}else if(pos1 < n && pos3 < v && A[pos1] == C[pos3]){
			return chkMixture_recu(A, pos1 + 1, n, B, pos2, m, C, pos3 + 1, v);
		}else if(pos2 < m && pos2 < v && B[pos2] == C[pos3]) {
			return chkMixture_recu(A, pos1, n, B, pos2 + 1, m, C, pos3 + 1, v);   
		}else {
			return false;
		}
	}
	*/ 
	//用dp的方式则不存在重叠子问题。
	 bool chkMixture(string A, int n, string B, int m, string C, int v) {
	 	//dp[i][j] 表示从A[0 ~ i-1]和B[0 ~ j-1]组合起来是不是可以构成C[0 ~ i+j-1] 这里1<=i<=n && 1<=j<=m 
	 	//dp[i][j] = (dp[i-1][j] == true && A[i-1] == C[i+j-1]) || (dp[i][j-1] == true && B[j-1] == C[i+j-1])
		//初始化dp[0][0]=true;也要初始化dp[0][x] 和dp[x][0]
		if(n+m != v)return false;
		int dp[n+1][m+1] = {0};//初始化为false; 
		dp[0][0] = true;
		for(int i = 1; i <= n; i++) {
			if(dp[i-1][0] == true && A[i-1] == C[i-1]) {
				dp[i]][0] = true;
			}else {
				break;//初始化为false后面的也全都为false所以直接break; 
			}
		} 
		for(int j = 1; j <= m; j++) {
			if(dp[0][j-1] == true && B[j-1] == C[i-1]) {
				dp[0][j] = true;
			}else {
				break;
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(dp[i-1][j] == true && A[i-1] == C[i+j-1]) {
					dp[i][j] = true;
				}
				if(dp[i][j-1] == true && B[j-1] == C[i+j-1]) {
					dp[i][j] = true;
				}
			}
		}
		return dp[n][m];
	 }
};
 
int main() {
	Mixture mix;
	string A = "bcbccabccacccbcac";
	int n = 17;
	string B = "abbbacaabccbccaaaabbcbcbaaacccbaaba";
	int m = 35;
	string C = "babbbacaabccbccaaaabbcbcbaaacccbaabacbccabccacccbcac";
	int v = 52;
	cout << mix.chkMixture(A, n, B, m, C, v);
}

