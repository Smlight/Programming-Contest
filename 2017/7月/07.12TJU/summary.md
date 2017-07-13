### A. find the princessI
感觉题意比较难理解，其实就是跳一次必须是上升2下降2，才到100随便模拟一下。

### B. find the princessII
~~大胆猜测。~~

考虑sg函数，根据题意。

 - n=1无后继，即sg[1]=0；
 - n=2可以转移到n=1，sg[2]=1。

假设n=2k+1时sg[n]=0，n=2k时sg[n]>0，则：

 - n=2k+2时，由于x|n，x可以取1,2，即可以转移到n=2k+1,n=2k，sg[n]>0；
 - n=2k+3时，由于x|n，则x为奇数，n-x为偶数，即只能转移到偶数。
 根据假设，之前的所有偶数n=2k',sg[n]>0，所以sg[n]=0。

结合第一步，假设成立，即答案只跟奇偶性有关。

【当然比赛的时候还是大胆猜测最重要

### C. find the princessIII
计算几何，可以算圆心到线段的最近最远距离。
考虑到误差/没模板啥的我就先判了All in。

### D. God Le wants to know the directory
模拟。注意点：..多组?

### E. The implementation problem
模拟。注意点：~~枚举题意；~~存正方形复杂度太高；pattern是`.`的位置矩阵无所谓；N/S转180°还是N/S不能算两次。

### G. The brute force problem
先介绍一个小结论。

如果当前能覆盖[1,x]，新增一个数y，那么一定能覆盖[1,x]+{y}+[1+y,x+y]。

显然地，当y>x+1时会产生空缺，将ai排序判断即可。

### I. The math problem
维护前缀最小值，扫一遍。

### J. The dynamic programming problem1
sg打表。两段不相连的1相当于两个独立的游戏。

### K. The dynamic programming problem2
因为mi<=mi+1，所以只会是新的区间包含旧的区间。

被包含的区间显然是右端点<=当前的右端点，左端点>=当前的左端点，用两个树状数组维护即可。

注意：a cancel operation does not count as a book operation