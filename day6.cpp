/*把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0
思路：先用二分查找:
当arr[mid] > arr[begin]的时候 begin = mid + 1
arr[mid] < arr[end]   end = mid
当arr[mid] == arr[begin] 还是 arr[mid] == arr[end] 
用之前的方法。
当end - beg <= 1 这时候返回最小的
*/
		
class Solution {
	public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0) return 0;
		size_t beg, end, mid;
		beg = 0,end = rotateArray.size() - 1;
		while( beg <= end ) {
			if( end - beg <= 1 ) return rotateArray[end] < rotateArray[beg]? rotateArray[end]: rotateArray[beg];
			mid = beg + ( end - beg ) / 2;
			if( rotateArray[mid] > rotateArray[beg] && rotateArray[mid] > rotateArray[end] ) {
                beg = mid;
            }
			else if( rotateArray[mid] < rotateArray[end] && rotateArray[mid] < rotateArray[beg] ) {
                end = mid;
            }
			else return Seq_search(rotateArray, beg, end);
		}
        return 0;
	}
	int Seq_search(vector<int> rotateArray, int beg, int end) {
		for (size_t i = beg; i < end; i++)
		{
			if (rotateArray[i + 1] < rotateArray[i]) {
                return rotateArray[i + 1];
            }
		}
		return rotateArray[beg];
	}
};

public:
    int Seq_search(vector<int> rotateArray, int beg, int end) {
		for (size_t i = beg; i < end; i++)
		{
			if (rotateArray[i + 1] < rotateArray[i]) return rotateArray[i + 1];
		}
		return rotateArray[beg];
	}
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0) return 0;
		size_t beg, end, mid;
		beg = 0,end = rotateArray.size() - 1;
		while( beg <= end ) {
			if( end - beg <= 1 ) return end < beg? end: beg;
			mid = beg + ( end - beg ) / 2;
			if( rotateArray[mid] > rotateArray[beg] ) beg = mid + 1;
			else if( rotateArray[mid] < rotateArray[end] ) end = mid;
			else return Seq_search(rotateArray, beg, end);
		}
	}