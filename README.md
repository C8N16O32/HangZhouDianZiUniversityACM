# HangZhouDianZiUniversityACM
## 10万的阶乘 130ms
* 使用例: 
    *使用例-计算n!或2^n
* 使用例涉及的文件: 
    *大数-数组形式、素数与快捷分解质因数
## 大数-数组形式
* 数组大数-基本内容
    * 功能：数组大数的基本功能与基本运算
    * 主要数据类型：
      *     struct lint { int len = 0; int size = 0; int* v = NULL; };//length、size、value
    * 使用示例：
      *     lint *a = NULL; lintnew(&a); /*运算*/ lintdelete(&a);
    * 申请空间，释放空间，清零
      *     lintnew (1个重定义) lintdelete (1个重定义) lintresetv
    * 改变空间大小，改变空间大小相关的宏
      *     lintresetsize lintchecksize(a, tsize)
    * 亿级移位，复制，比较，连续置数
      *     lintshift lintcopy lintcmp lintsetnum
    * 从字符串大数导入，导出为字符串大数，打印实际值，打印实际长度
      *     lintsscan lintsprintf lintprintfvalue lintprintfstrlen lintprintf
    * 加减乘除，乘法专用带双偏移的lld数加
      *     linta (1个重定义) lints (1个重定义) lintm0 lintm (1个重定义) lintd (1个重定义) lintafast
    * 分治递归乘法
      *     lintm1div lintm1sum lintm1
* 数组大数-高级内容-二分法连乘
    * 功能：将直接连乘改进为二分法连乘
    * 主要数据类型：
      *     struct lint { int len = 0; int size = 0; int* v = NULL; };//length、size、value
    * 操作说明：
      *     lint**temp = NULL; lintmsnew(&temp); /*乘入与导出*/ lintmsdelete(&temp);
    * 申请空间、释放空间、初始置1
      *     lintmsnew (1个重定义) lintmsdelete (1个重定义) lintmsresetv
    * int乘入、数组大数乘入、另一结构乘入
      *     lintms (2个重定义)
    * 导出为数组大数
      *     lintms2lint
* 数组大数-高级内容-优化的FFT乘法
    * 功能：FFT乘法
    * 主要数据类型：
      *     struct comp { double x, y; };
    * 操作说明：
      *     代码添加到基本内容的后面。删除基本内容中的lintm。保留此代码中的lintm。
    * 额外说明：
      *     通过一些数学方法减少了一次正变换。通过一些测试得到了激进的压位表。
    * 复数类及其运算
      *     coswap coadd cosub comuti
    * FFT乘法
      *     lintm2_scan lintm2_rev lintm2_FFT lintm2
    * 乘法封装函数
      *     lintm
      
## 素数与快捷分解质因数
* 基本功能
    * 功能：质数表生成，较高效率的分解质因数，质因数式导出为大数
    * 主要数据类型：结构体指针 pri*
      *     struct pri { int*prik = NULL, *priflag = NULL, *priv = NULL, prisize = 0; };
    * 操作说明：
      *     pri *p = NULL; prinewandset(&p, 50000+1); /*分解质因数与质因数式导出*/ pridelete(&p);
    * 申请空间同时完成筛查表、质因数表、质数表；释放空间、清空质因数表、复制质因数表的一部分
      *     prinewandset (1个重定义) pridelete (1个重定义) prireserv pricopy
    * 分解质因数：分解一个数组，分解阶乘，分解排列数
      *     prif1 priffact prifcnm
    * 质因数表导出为大数（其中使用了快速幂与二分法连乘）
      *     pri2lintms pri2lint

