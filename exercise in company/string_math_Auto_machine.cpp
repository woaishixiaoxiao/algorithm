/*
字符串匹配，有限自动机。有穷指的是当前状态输入一个字符a，转化后的状态是一定的。
描述一个状态机，可以用五个元素 （Q, q0, A, ∑，δ）
Q代表所有状态的集合 q0代表初始状态 A是接受状态集合 ∑是所有字符的集合 δ称为转移函数
模式串为P(ababaca)  文本串为(abababacaba)
自动机是根据模式串和文本串的字符创建的，以上述两个文本举例子
Q=（0 1 2 3 4 5 6 7） 从0到字符串的长度
q0=0
A=7
∑=(abc)
δ
实际上在文本串中匹配模式串，只要文本串的子串的后缀是模式串，即匹配成功。
用自动机匹配的模式串的方法是：事先记录所有的状态转移，将文本串按顺序输入到表
中，如果得到的当前状态是可接受状态那么匹配成功。
状态表的意义是 将所有可能的转化的状态记录下来。
数值代表的含义是  当前输入的字符串和模式串匹配的最长后缀，也是模式串的最长前缀。
上述举例的状态表，
   a    b   c     p
0  1    0   0     a
1  1    2   0     b
2  3    0   0     a
3  1    4   0     b
4  5    0   0     a
5  1    4   6     c
6  7    0   0     a
7  1    2   0
用q代表当前状态,a为当前输入的字符 则状态转移后的值 δ(q,a)=&(Pqa) q当前状态(某个数值) a为输入字符
Pq代表模式串P的前q位。Pqa代表Pq加上a组成的字符串。&(Pqa)得到的就是状态表中的数值。比如当前状态是3，
下一个输入字符是a，在输入a之前已经输入的所有的字符串中最长后缀为Pq 现在又要输入一个字符a了，那么要
检验Pqa是不是模式串的最长前缀，是则δ(q,a)=q+1 不是的话就要截取模式串的0~q子串和Pqa试，找到模式串的
最长子串。从状态为0开始推，状态表 将∑字符集*q的状态全部记下来了。
文本顺序将字符输入到状态机中，每输入一个字符就会根据状态机得到一个数值，此数值就是当前文本子串和模式串的
最长后缀/前缀，当数值等于模式串的长度也就是可接受状态的时候，此模式串被字符串匹配。
*/

















