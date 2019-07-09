####请实现一个函数，将一个字符串中的每个空格替换成“%20”。
#例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
#
#不能通过创建一个临时数组，赋值给参数数组，再返回，一个是 参数是传值的 另一个 即使是传递指针过来，函数结束的时候
#临时数组也会被释放的。而通过动态分配也不是很好的方法 可以转换思路，先将原数组复制到一个临时的缓冲区中，之后按上述的方法
#在字符串里面  sizeof = strlen + 1; 但是用sizeof就不知道为什么不对啊  
#正确做法是 先算出空格的数量，从后网前移动  这道题默认就是数组的长度够
class Solution {
public:
	void replaceSpace(char *str,int length) {
		if( str == NULL || !length ) return;
		const size_t size = 3 * length + 1;
		char str_temp[size];
		int i,j;
		for(i = 0, j = 0; i < length;) {
			if( str[i] != ' ' ) {
				str_temp[j++] = str[i++];
			}else {
				str_temp[j++] = '%';
				str_temp[j++] = '2';
				str_temp[j++] = '0';
				i++;
			}				
		}
		str_temp[j] = '\0';
		int length_new = strlen(str_temp);
		for(i = 0; i <= length_new; i++) {
			str[i] = str_temp[i];
		}
		return;
	}
};





