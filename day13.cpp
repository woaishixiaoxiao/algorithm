/*
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,
���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
��������:
����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��
*/
class Solution {
public:
    void Swap(string &s,int i,int j){
        char c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
    void PermutationRecu(vector<string>&res,string s,int n){
        if(n==s.size()-1)res.push_back(s);
        else{
            for(int i=n;i<s.size();i++){
                if(i==n||s[i]!=s[n]){
                    Swap(s,n,i);
                    PermutationRecu(res,s,n+1);
                }
            }
        }
    }
    vector<string> Permutation(string str) {
        vector<string>res;
        PermutationRecu(res,str,0);
        return res;
    }
   
};


