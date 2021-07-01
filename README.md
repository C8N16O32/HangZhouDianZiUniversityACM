# HangZhouDianZiUniversityACM
## 10万的阶乘 130ms
* 相关文件有2个: 
    *大数-数组形式、素数与快捷分解质因数
* 相关使用例有1个: 
    *使用例-计算n!或2^n
## 大数-数组形式
* 数组大数-基本内容
    * 功能：数组大数基本功能
    * 主要数据类型：结构体指针 lint*
    * 操作说明：使用函数为结构体申请空间、执行运算、变更空间大小、释放空间
    * 结构体lint（largeint）的定义：
      *     struct lint { int len = 0; int size = 0; int* v = NULL; };//length、size、value
    * 为此结构体提供基本功能：申请空间，释放空间，清零
      *     lintnew (1个重定义) lintdelete (1个重定义) lintresetv
    * 为此结构体提供基本功能：改变空间大小，改变空间大小相关的宏
      *     lintresetsize lintchecksize(a, tsize)
    * 为此结构体提供基本运算：亿级移位，复制，比较，连续置数
      *     lintshift lintcopy lintcmp lintsetnum
    * 为此结构体提供基本功能：从字符串大数导入，导出为字符串大数，打印实际值，打印实际长度
      *     lintsscan lintsprintf lintprintfvalue lintprintfstrlen lintprintf
    * 为此结构体提供四则运算：加减乘除，乘法专用带双偏移的lld数加
      *     linta (1个重定义) lints (1个重定义) lintm0 lintm (1个重定义) lintd (1个重定义) lintafast
    * 为此结构体提供一个高级乘法：分治递归乘法
      *     lintm1div lintm1sum lintm1
* 数组大数-高级内容-二分法连乘
    * 功能：将直接连乘改进为二分法连乘
    * 主要数据类型：二级结构体指针 lint**
    * 操作说明：使用函数为大数数组申请空间、乘入、导出、释放空间
    * 为此结构提供基本功能：申请空间、释放空间、初始置1
      *     lintmsnew (1个重定义) lintmsdelete (1个重定义) lintmsresetv
    * 为此结构提供乘入功能：int乘入、数组大数乘入、另一结构乘入
      *     lintms (2个重定义)
    * 为此结构提供导出功能：导出为数组大数
      *     lintms2lint
* 数组大数-高级内容-优化的FFT乘法
    * 功能：提供一个高级乘法
    * 主要数据类型：结构体指针 comp*
    * 操作说明：删去旧的封装函数lintm 即可完成升级
    * 额外说明：通过一些数学方法减少了一次正变换。通过一些测试得到了激进的压位表。
    * 复数类及其运算：struct comp { double x, y; };
      *     coswap coadd cosub comuti
    * FFT乘法部分：
      *     lintm2_scan lintm2_rev lintm2_FFT lintm2
    * 乘法封装函数：
      *     lintm
      
## 素数与快捷分解质因数
* 基本功能
    * 功能：创建一个含有质数表，质因数表，筛查表的结构体
    * 主要数据类型：结构体指针 pri*
      *     struct pri { int*prik = NULL, *priflag = NULL, *priv = NULL, prisize = 0; };
    * 操作说明：使用函数为指针申请空间、生成三个数组、一些质因数表的操作、释放空间
    * 基本功能：申请空间同时完成三个数组的建立、释放空间、清空质因数表、复制质因数表的一部分
      *     prinewandset (1个重定义) pridelete (1个重定义) prireserv pricopy
    * 分解质因数：分解一个数组，分解阶乘，分解排列数
      *     prif1 priffact prifcnm
    * 质因数表导出为大数 并且使用快速幂与二分法连乘
      *     pri2lintms pri2lint

