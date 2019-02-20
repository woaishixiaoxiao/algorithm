/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
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


