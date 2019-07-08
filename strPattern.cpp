#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int strMatch(const string &str, int i, const string &pattern, int j) {
	int k;
    if(i == str.size() && j == pattern.size()) return 0;
    if(i > str.size() || j > str.size()) return -1;
    if(pattern[j] == '?' || str[i] == pattern[j]) return strMatch(str, i + 1, pattern, j + 1);
    if(pattern[j] == '*') {
        for(k = i; k < str.size(); k++) {
            if(strMatch(str, k, pattern, j + 1) == 0) {
                return 0;
            }
        }
        return -1;
    }
    return -1;
}
/*bool match(const string &str, const string &pattern) {
	int i, j, k, m;
	int str_len = str.size();
	int pattern_len = pattern.size();
	if(!strlen && !pattern_len) return 0;
	for(i = 0, j = 0;j < pattern_len && i < str_len;) {
		if(pattern[j] == '?' || pattern[j] == str[i]) {
			++i;
			++j;
		}else if(pattern[j] == '*') {
			for(k = j; k < pattern_len && (pattern[k + 1] != '*' || pattern[k + 1] != '?'); ++k);
			while(k < pattern_len && i < str_len) {
				
			}
			
		}else {
			return -1;
		}
	}
	
}*/
int main() {
	string str, pattern;
	cin>>str;
	cin>>pattern;
    if(strMatch(str, 0, pattern, 0) == 0) {
        cout<<"match";
    }else {
    	cout<<"unmatch";
    }
}
