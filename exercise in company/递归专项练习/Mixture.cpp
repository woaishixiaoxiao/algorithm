/*
A��B��C�����C�����ҽ���������A��B�������ַ���������C������A���ַ�֮�䱣��ԭ����A�е�˳������B���ַ�֮�䱣��ԭ����B�е�˳����ô��C��A��B�Ļ�ࡣʵ��һ���������ж�C�Ƿ���A��B�Ļ�ࡣ

���������ַ���A,B��C�������ǵĳ��ȡ��뷵��һ��boolֵ������C�Ƿ���A��B�Ļ�ࡣ��֤�������ĳ��Ⱦ�С�ڵ���100��

����������
"ABC",3,"12C",3,"A12BCC",6
���أ�true
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
        for(int i = 0; i < v && str1_pos < n && str2_pos < m; i++) {   //��Ӧ��д�������Ϊ��Ȼ��һ��ֹͣ�� ���������Ŀ�����Ҫ�������������Ըĳ��������� 
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
    //����������������ģ���Ҫ�ǵ�������A�п��Ժ�C��ǰƥ�䣬B��Ҳ���ԣ���ʱ��֪���Ǻ�A���Ǻ�Bȥƥ�䡣
	//�ݹ�ķ��� ������ ���������ʱ�򣬵ݹ鷽�������ص������� 
	/*
	bool chkMixture(string A, int n, string B, int m, string C, int v) {
		if(n + m != v) return false;
		return chkMixture_recu(A, 0, n, B, 0, m, C, 0, v);
	}
	bool chkMixture_recu(string A, int pos1, int n, string B, int pos2, int m, string C, int pos3, int v) {
		if(pos1 == n && pos2 == m && pos3 == v) return true;
		if(pos1 < n && pos2 < m && pos3 < v && A[pos1] == B[pos2] && A[pos1] == C[pos3]) { 
			//����Ҫô����ȥ����A�������飬pos1���䣬Ҫô���ݵ���A���䣬pos+1 
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
	//��dp�ķ�ʽ�򲻴����ص������⡣
	 bool chkMixture(string A, int n, string B, int m, string C, int v) {
	 	//dp[i][j] ��ʾ��A[0 ~ i-1]��B[0 ~ j-1]��������ǲ��ǿ��Թ���C[0 ~ i+j-1] ����1<=i<=n && 1<=j<=m 
	 	//dp[i][j] = (dp[i-1][j] == true && A[i-1] == C[i+j-1]) || (dp[i][j-1] == true && B[j-1] == C[i+j-1])
		//��ʼ��dp[0][0]=true;ҲҪ��ʼ��dp[0][x] ��dp[x][0]
		if(n+m != v)return false;
		int dp[n+1][m+1] = {0};//��ʼ��Ϊfalse; 
		dp[0][0] = true;
		for(int i = 1; i <= n; i++) {
			if(dp[i-1][0] == true && A[i-1] == C[i-1]) {
				dp[i]][0] = true;
			}else {
				break;//��ʼ��Ϊfalse�����Ҳȫ��Ϊfalse����ֱ��break; 
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

