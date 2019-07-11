/*
有n个物品，它们有各自的体积和价值，现有给定容量的背包，如何让背包里装入的物品具有最大的价值总和？
为方便讲解和理解，下面讲述的例子均先用具体的数字代入，即：eg：number＝4，capacity＝8
i（物品编号）	1	2	3	4
w（体积）		2	3	4	5
v（价值）		3	4	5	6
1、使用二维动态规划。dp[n][m]，n代表前n个物品，m代表背包所能容纳的重量。的最大价值 
2、 dp[i][j]代表当前要放第n个物品，背包所能容纳的总重量是j  求此值和d[i-1]有关系
2.1、当前的物品的W如果比j还要大，那d[i][j] = d[i-1][j]。这肯定有疑问，选i-1个商品，价值最大的也不一定是d[i-1][j]。这样想没错，但是要注意的是d[i][j]代表的是前i个总重量为j的最大价值。最后求的是前n个，最大量为m的最大价值。所以拆成的子问题不是找数量为i的时候而是前i个的时候。所以该问题和排列的顺序是没有关系的。 
2.2、 当前的物品的W小于J，也就是当前的物品i可以插进去。那么插入后的价值是V = d[i-1][j-w(i)] + v(j)，这个表达式代表两种可能，一个是不用取出来物品，一个是需要取出来物品将当前的放进去(可以拿两个举例子，a b。背包里面放了一个a了，放b的时候，要么将a取出来将b放进去，要么将ab一起放进去)。综上当前的最大利益是max(d[i-1][j], d[i-1][j-w(i)] + v(j)))
3、商品的顺序和最后的结果无关系
*/
#include<iostream>
#include<vector>
using namespace std;
#define MAXCOL 1000
#define MAXROW 1000
int main() {
	vector<vector<int>>thing;
	int num;
	int limit_w;
	int w, v;
	cin >> limit_w;
	cin>>num;
    thing.push_back({0,0});
	for(int i = 0; i < num; ++i) {
		cin >> w >> v;
		vector<int>tmp;
		tmp.push_back(w);
		tmp.push_back(v);
		thing.push_back(tmp);
	}
	int dp[MAXROW][MAXCOL] = {0}; //dp[0][j] dp[i][0]均等于0
	for(int i = 1; i <= num; ++i) {
		for(int j = 1; j <= limit_w; ++j) {
			int curr_w = thing[i][0];
			if(curr_w > j) {
				dp[i][j] = dp[i-1][j];
			}else {
				int last_v = dp[i-1][j - curr_w] + thing[i][1];
				dp[i][j] = dp[i-1][j] > last_v? dp[i-1][j] : last_v;
			}
		}
	}
	cout<<dp[num][limit_w];
}

