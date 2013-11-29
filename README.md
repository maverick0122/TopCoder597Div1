TopCoder597Div1
===============

TopCoder SRM 597 Div1

第1题解题报告

类型：字符串  难度：2.5

题意：给出A,B两个字符串，长度相同，允许对A做一种操作：将A中任意位置字符放到第一个位置，问对A做几次这个操作，A和B相同，若不可能，返回-1。

分析：最长公共子序列的变形问题，dp解决即可。即从A的尾部反向遍历，dp[i]表示从A末尾到第i个位置 与 B从末尾开始匹配的最大长度，A匹配字符可以不连续，B匹配字符位置连续，且必须从末尾开始匹配，即A[m]=B[n],i<m<len(A),n=j,j+1,...,len(B)。

递推方程：dp[i] = max(dp[j]+1)，i<j<len(A)，A[i]==B[len(B)-dp[j]-1]

答案就是len(A)减去最大匹配长度。



第3题解题报告

类型：数论  难度：3.5

题意：给出M,R,G,B，2M=R+B+G，M代表一个2*M区域的列数，RGB分别代码红绿蓝格子的个数，要求：每个2*2格子中，三种颜色每种至少有一个格子，且相邻格子颜色不同，问有多少种排列方式

 

分析：比较复杂的一道数学问题。纠结了很多天。。

先将问题转化：

由于要满足上述要求，观察可得，每列的格子有6种状态，(RG,GB,BR),(RB,BG,GR)，前三个看成一组，后三个看成一组，每组的三个状态可以互相转化，但是同种状态不相邻

可见第二组实际上是第一组每个情况上下互换位置所得，所以两组计算出的排列数相同，算出其中一种*2即可。

设第一组每个状态的个数为x,y,z，可得：x=M-B, y=M-R, z=M-G

那么问题转化为：给出三种颜色的球，个数为x,y,z，将其排成一行，要求同颜色球不相邻，问有多少种排列方式

 

考虑用插空法解决问题，设x>=y>=z，解法如下：

1、若y+z<x-1，返回0。即yz加起来都无法填补x个球的空隙，没有合法情况。

2、设yz所填的x的空隙数目为x1,x1=x-1,x,x+1，因为左右两边的空隙可放可不放，所以实际是四种情况，填左边x个空，右边x个空，中间x-1个空，填满x+1个空

遍历x1，累加结果，x1=x时，由于是两种情况，累加两次

3、在x1个位置中，设有y的位置为y1，y1<=y，那么先要从x1中选y1个位置，数量为c(x1,y1)

4、然后，还剩x1-y1个位置，这些位置每个位置都要放1个z，设为z1=x1-y1

5、那么，剩余的y（多出来的y）是y2=y-y1，将y2个y放到y1个位置上的数目是c(y1+y2-1,y1-1)（可以看成一个长度为y2+y1-1的序列，挑出y1-1个分割点）剩余的z是z2=z-z1，填充这些y的空隙需要y2个z，那么最后剩余的z就是z3=z2-y2

6、这z3个z能够放入的位置是每个yzyz...zy序列的两侧，这样的序列有y1个，那么z3个z的放法就是c(2y1,z3)，至此，所有球分配完毕

由于M,R,G,B的范围为10^6，要在O(1)计算出c(m,n)%mod必须使用数组记录辅助数据，这段代码是参照别人的，就不细讲了。。
