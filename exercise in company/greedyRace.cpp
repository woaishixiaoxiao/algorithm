/*
这个题目贪心的本质在于：*田忌只在有把握赢的情况下拿出快马和王拼，否则用最慢的马比掉王的快马最大程度削弱王的战斗力
贪心策略：
1，如果田忌的最快马快于齐王的最快马，则两者比。
（因为若是田忌的别的马很可能就赢不了了，所以两者比）
2，如果田忌的最快马慢于齐王的最快马，则用田忌的最慢马和齐王的最快马比。
（由于所有的马都赢不了齐王的最快马，所以用损失最小的，拿最慢的和他比）
3，若相等，则比较田忌的最慢马和齐王的最慢马
若田忌最慢马快于齐王最慢马，两者比。
（田忌的最慢马既然能赢一个就赢，而且齐王的最慢马肯定也得有个和他比，所以选最小的比他快得。）
其他，则拿田忌的最慢马和齐王的最快马比（注意两马战力相等的情况，不能算田忌输）。
（反正所有的马都比田忌的最慢马快了，所以这匹马必输，选贡献最大的，干掉齐王的最快马）
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
using namespace std;
//下面的方法可以确定出厂顺序了，然后根据对方出厂顺序，上对应的马就行了 
int greedy_race(vector<int> &myself, vector<int> &other) {
	int fin_score = 0;
	int i, j, k ,t;
	i = j = 0;
	k = t = myself.size() - 1;
	while(i <= k) {
		cout << k << " " << myself[k] <<endl;
		cout<<t<<" "<<other[t]<<endl;
		cout<<i<<" "<<myself[i]<<endl;
		cout<<j<<" "<<other[j]<<endl;
		if(myself[k] > other[t]) {
			fin_score += 1;
			--k;
			--t;
		}else if(myself[k] < other[t]) {
			fin_score -= 1;
		 	++i;
		 	--t;
		}else {
			if(myself[i] > other[j]) {
				++i;
				++j;
				fin_score += 1;
			}else {
				if(myself[i] < other[t]) {
					fin_score -= 1;
				}
				++i;
				--t;
			}
		}
		cout<<fin_score<<endl<<endl;
	}
	return fin_score;
}

int main() {
	vector<int> myself;
	vector<int> other;
	int res;
    int num, speed;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin>>speed;
        myself.push_back(speed);
    }
    for(int i = 0; i < num; i++) {
        cin>>speed;
        other.push_back(speed);
    }
	sort(myself.begin(), myself.end());
	sort(other.begin(), other.end()); 
	if((res = greedy_race(myself, other)) > 0) {
        cout<<"YES";
    }else {
        cout<<"NO";
    }
    cout << endl;
    cout<<res;
}


