/*
和有限自动机匹配字符串相比，KMP算法预处理时间大大下降。
暴力匹配的方式就是 遍历文本中每个子串，从该字符往后和模式串挨个匹配，
如果匹配成功则文本被模式串匹配成功。每次匹配不成功或者成功，文本字符的
偏移量为1。KMP算法中文本中偏移量不是1。假设模式串为P=ababaca
引入一个函数记为y(x) Px为模式串的子串。y(x)=m，m意味着P的前m个字符和P的后m
个字符相等但是m!=x。那这样子无论本次字符匹配成功或者失败与否，下一次的偏移量为m，而不是1。
求y(x)的时候可以用左移法。
*/