#include <algorithm>
#include<set>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void dfs(string &str, int i, string st, string tmp, set<string> &ret)
{
    if (i == (int)str.size()) {
        reverse(st.begin(), st.end());
        ret.insert(tmp.append(st));
        return ;
    }
    st += str[i];
    dfs(str, i + 1, st, tmp, ret);
    while( !st.empty() ) {
        tmp += st[ st.size() - 1];
        st = st.substr(0, st.size() - 1);
        dfs(str, i + 1, st, tmp, ret);
    }
}

int main()
{
	string str;
	cin>>str;
	set<string>ret;
	dfs(str, 0, "", "", ret);
	for (set<string>::iterator it = ret.begin(); it != ret.end(); ++it)
            cout << *it << endl;
    return 0;
}
