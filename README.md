# HangZhouDianZiUniversityACM
## 10万的阶乘 130ms（阶乘研究）
* 数组形式存储大数：8位十进制数放进一个int
* 借助二分法的思路：维护一个大数数组，位数限制依次倍增，总是先与位数最少的大数做乘法，超出位数限制则向后乘。提升数千到数万倍的速度，借助这个技巧，不使用FFT也能做到4秒以内算出10万的阶乘。 在累乘结束之后要对数列额外做一轮乘法以得到最终答案
* 借助分治思路：47x52 拆分成 4*5 4*2 7*5 7*2 其中4x2和7x5可以通过一些手段处理成只需1次乘法。于是总体来说，每次对半拆分，都能从4次乘法节省到3次，极限情况下可以从O(n^2)优化到O(n^1.62)
* 借助FFT进行快速乘法：两个数字的乘法等效于两个数列先卷积后进行进位处理。其中卷积的部分可以用FFT进行加速。优化到O(logn)
* FFT压位技巧：把几位数字合并为一组 一起放进复数的实部 减少FFT序列的长度（压位） 提升几倍效率
* 多线程前置：二维级联FFT：例如1048576点FFT 可以放进1024x1024的矩阵 然后拆分为1024次1024点FFT(逐列进行) 矩阵数乘 逐行进行。计算量增大了2倍，但拆分后可以避免FFT点数过长造成的各种问题。
* 多线程：手写了一个简陋的多线程实例，还待优化
