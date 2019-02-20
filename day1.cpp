########
#在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
#每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
########
####
#我的思路是从最外边网最里面渗透，简单的是从左下角开始
#
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        size_t row = array.size();
		if( row == 0 ) return false;
		size_t col = array[0].size();
		size_t init_row = 0, init_col = col;
		bool flag = true;
		while(init_row < row && init_col > 0) ) {
			if( array[init_row][0] > target ) return false;
		    if( array[row-1][init_col-1] < target ) return false;
			for(int j = 0; j < init_col; j++) {
				if(array[init_row][j] == target) return true;
				if(array[init_row][j] > target ) {
					flag = false;
					break;
				}
			}
			for(int i = init_row + 1; i < row && flag; i++) {
				if( array[i][init_col-1] == target ) return true;
				if( array[i][init_col-1] > target ) {
					flag = false;
					break;
				}
			}
			init_row++;
			init_col--;
			flag = true;
		}
		return false;
	}
};