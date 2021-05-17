// ACM2.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"

/*======================================================================   #41 - #48  Catalan数&超大整数   ======================================================================*/

//题目2-3-1 字符串加法

//#define N 1000
//void add(char*a, char*b, char*c) {
//	int i = 0, j = 0, k, re;
//	while (a[i])i++;
//	while (b[j])j++;
//	re = 0;
//	for (k = 0; k < i&&k < j; k++) {
//		re += a[i - k - 1] - 48; re += b[j - k - 1] - 48;
//		c[k] = 48 + re % 10;
//		re /= 10;
//	}
//	if (i >= j)	for (k = j; k < i; k++) {
//		re += a[i - k - 1] - 48;
//		c[k] = 48 + re % 10;
//		re /= 10;
//	}
//	else	for (k = i; k < j; k++) {
//		re += b[j - k - 1] - 48;
//		c[k] = 48 + re % 10;
//		re /= 10; 
//		}
//			if (re)c[k] = '1';
//		i = 0; while (c[i])i++; j = i;
//		char temp;
//		for (i = 0; i < j / 2; i++) {
//			temp = c[j - i - 1]; c[j - i - 1] = c[i]; c[i] = temp;
//		}
//		return;
//	}
//	void pr(int i, char*a, char*b, char*c) {
//		printf("Case %d:\n%s + %s = %s\n", i, a, b, c);
//		return;
//	}
//	int main() {
//		char a[N], b[N], c[N]; int n, i, j, isfirst = 1;
//		scanf("%d", &n);
//		for (i = 1; i <= n; i++) {
//			for (j = 0; j < N; j++) {
//				a[j] = '\0'; b[j] = '\0'; c[j] = '\0';
//			}
//			scanf("%s %s", a, b);
//			add(a, b, c);
//			if (isfirst)isfirst = 0;
//			else printf("\n");
//			pr(i, a, b, c);
//		}
//		return 0;
//	}

//题目2-3-2 求阶乘的位数

//#include "math.h"
//int main() {
//	int n, num; double dig;
//	scanf("%d", &n);
//	while (n--) {
//		scanf("%d", &num);
//		dig = 0;
//		while (num--)
//			dig += log10(1.0*(num + 1));
//		printf("%.0lf\n", floor(dig + 0.00001) + 1);
//	}
//	return 0;
//}


//题目2-3-345678  公共部分 C大数类 & C素数类

////C大数类
//struct lint { int len; int size; int* v = NULL; };//length、size、value
//#define lenstep 8
//#define lintbase 100000000
////lint_basic
//void lintreset(struct lint *a) {
//	int i; for (i = 0; i < a->len; i++)
//		a->v[i] = 0;
//	a->len = 0; return;
//}
//void lintnew(struct lint**a, int size) {
//	if (*a == NULL)*a = new struct lint;
//	(*a)->len = size; (*a)->size = size;
//	(*a)->v = new int[size];
//	lintreset(*a); return;
//}
//void lintdelete(struct lint **a) {
//	delete[](*a)->v; (*a)->v = NULL; return;
//}
//void lintresize(struct lint *a, int sizenew) {
//	int*temp = NULL, lenold = 0, i;
//	if (a->len) {
//		temp = new int[a->len]; lenold = a->len;
//		for (i = 0; i < lenold; i++)
//			temp[i] = a->v[i];
//	}
//	lintdelete(&a); 
//	lintnew(&a, sizenew);
//	if (sizenew < lenold) { lenold = sizenew; a->len = sizenew; }
//	for (i = 0; i < lenold; i++)a->v[i] = temp[i];
//	a->len = lenold;
//	delete[]temp; return;
//}
//void lintcopy(struct lint *a, struct lint *b) {
//	if (b->len >a->size)lintresize(a, b->len);
//	lintreset(a);
//	int i; for (i = 0; i < b->len; i++) a->v[i] = b->v[i];
//	a->len = b->len; return;
//}
//int lintcmp(struct lint *a, struct lint *b) {
//	//不支持负数
//	if (a->len > b->len)return 1;
//	if (a->len < b->len)return -1;
//	int i = a->len;
//	while (i--) {
//		if (a->v[i] > b->v[i])return 1;
//		if (a->v[i] < b->v[i])return -1;
//	}
//	return 0;
//}
////lint_print
//void lintprintf(struct lint *a) {
//	int isfirst = 1, i;
//	for (i = a->len - 1; i >= 0; i--)
//		if (isfirst) {
//			if (a->v[i])printf("%d", a->v[i]);
//			isfirst = 0;
//		}
//		else printf("%08d", a->v[i]);
//		if (isfirst)printf("0");
//		printf("\n");
//		return;
//}
//void lintsprint(struct lint *a, char* temp0, int tempsize = -1) {
//	int isfirst = 1, i; char* temp = temp0;
//	if (tempsize != -1) {
//		i = tempsize - 1;
//		while (temp[i] == '\0'&&i >= 0)i--;
//		temp += i + 1;
//	}
//	for (i = a->len - 1; i >= 0; i--) {
//		if (isfirst) {
//			if (a->v[i])temp += sprintf(temp, "%d", a->v[i]);
//			isfirst = 0;
//		}
//		else temp += sprintf(temp, "%08d", a->v[i]);
//		if (tempsize != -1 && temp - temp0 > tempsize - 8)return;
//	}
//		if (isfirst)temp+=sprintf(temp, "0");
//		temp += sprintf(temp, "\n");
//		return;
//}
////lint_add
//void linta(struct lint *a, struct lint *b) {
//	int temp, base = lintbase;
//	int n = b->len, i = 0;
//	if (a->size <= b->len)lintresize(a, b->len + lenstep - 1);
//	temp = 0;
//	while (1) {
//		if (i < n)temp += b->v[i];
//		if (i >= n&&temp == 0)break;
//		if (i >= a->size)lintresize(a, i + lenstep - 1);
//		temp += a->v[i];
//		a->v[i] = temp%base; temp /= base; i++;
//	}
//	if (a->len < b->len)a->len = b->len;
//	if (a->v[a->len] && a->len < a->size)a->len++;
//	while (a->size - a->len > lenstep)lintresize(a, a->size - lenstep);
//	return;
//}
//void linta(struct lint *a, int num, int section = 0) {
//	int temp, base = lintbase;
//	int i = section;
//	temp = num;
//	while (1) {
//		if (temp == 0)break;
//		if (i >= a->size)lintresize(a, i + lenstep - 1);
//		temp += a->v[i];
//		a->v[i] = temp%base; temp /= base; i++;
//	}
//	if (a->len < 1)a->len = 1;
//	if (a->v[a->len] && a->len < a->size)a->len++;
//	while (a->size - a->len > lenstep)lintresize(a, a->size - lenstep);
//	return;
//}
////lint_sub
//void lints(struct lint *a, struct lint *b) {
//	//不支持负数
//	int temp = 0, base = lintbase;
//	int n = a->len, i;
//	for (i = 0; i < n; i++) {
//		temp += a->v[i];
//		if (i < b->len)temp -= b->v[i];
//		if (temp >= 0) { a->v[i] = temp; temp = 0; if (i >= b->len)break; }
//		else { a->v[i] = temp + base; temp = -1; }
//	}
//	i = a->len - 1; while (a->v[i] == 0 && i >= 0)i--; a->len = i + 1;
//	while (a->size - a->len > lenstep)lintresize(a, a->size - lenstep);
//	return;
//}
////lint_muti
//void lintm(struct lint *a, struct lint *b) {
//	static struct lint*c = NULL; static int isfirst = 1;
//	if (isfirst) { lintnew(&c, lenstep); isfirst = 0; }
//	else { if (c->size < a->len + b->len)lintresize(c, a->len + b->len + lenstep); lintreset(c); }
//	int i, j; long long temp, temp2, base = lintbase;
//	temp = 0;
//	for (i = 0; i < c->size; i++) {
//		for (j = 0; j <= i; j++) {
//			temp2 = 1;
//			if (j < a->len)temp2 *= a->v[j]; else temp2 = 0;
//			if (i - j < b->len)temp2 *= b->v[i - j]; else temp2 = 0;
//			temp += temp2;
//		}
//		c->v[i] = temp%base; temp /= base;
//	}
//	i = c->size - 1; while (c->v[i] == 0)i--; c->len = i + 1;
//	lintcopy(a, c);
//	return;
//}
//void lintm(struct lint *a, int num) {
//	static struct lint *c = NULL; static int isfirst = 1;
//	if (isfirst) { lintnew(&c, 1); isfirst = 0; }
//	else { lintreset(c); }
//	linta(c, num);
//	lintm(a, c); return;
//}
////lint_div
//int lintd(struct lint *a, struct lint *b) {
//	static struct lint *c = NULL, *d = NULL, *e = NULL; static int isfirst = 1;
//	if (isfirst) { lintnew(&c, a->size); lintnew(&d, a->size); lintnew(&e, a->size); isfirst = 0; }
//	else {
//		if (c->size < a->len) {
//			lintresize(c, a->len + lenstep);
//			lintresize(d, a->len + lenstep);
//			lintresize(e, a->len + lenstep);
//		}lintreset(c); lintreset(d); lintreset(e);
//	}
//	int i;
//	while (lintcmp(a, b) != -1) {
//		lintreset(d); linta(d, 1);
//		while (1) {
//			lintcopy(e, b); lintm(e, d); lintm(e, 10);
//			if (lintcmp(a, e) == -1)break;
//			lintm(d, 10);
//		}
//		i = 1;
//		while (1) {
//			lintcopy(e, b); lintm(e, d); lintm(e, i + 1);
//			if (lintcmp(a, e) == -1)break;
//			i++;
//		}
//		lintcopy(e, b); lintm(d, i); lintm(e, d); 
//		linta(c, d); 
//		lints(a, e); 
//	}
//	int re = 0;
//	lintreset(d);
//	if (lintcmp(a, d) == 0)re = 0; else re = 1;
//	i = c->len - 1; while (c->v[i] == 0 && i >= 0)i--; c->len = i + 1;
//	lintcopy(a, c);
//	return re;
//}
//void lintd(struct lint *a, int num) {
//	static struct lint *c = NULL; static int isfirst = 1;
//	if (isfirst) { lintnew(&c, 1); isfirst = 0; }
//	else { lintreset(c); }
//	linta(c, num);
//	lintd(a, c); return;
//}

////素数&素数因子
//struct pri { int*prik = NULL, *priflag = NULL, *priv = NULL, prisize = 0; };
//void priset(struct pri**a,int prisize) {
//	if (*a == NULL)*a = new struct pri;
//	(*a)->priflag = new int[prisize];
//	int i = 0, j = 0, k = 1;
//	for (i = 0; i < prisize; i++)(*a)->priflag[i] = 0;
//	for (i = 2; i < 230; i++)
//		if (!(*a)->priflag[i]) {
//			for (j = i * 2; j < prisize; j += i)
//				(*a)->priflag[j] = k;
//			k++;
//		}
//	j = 0;
//	for (i = 2; i < prisize; i++)if ((*a)->priflag[i] == 0)j++;
//	(*a)->prik = new int[j];
//	i = 0; j = 2;
//	while (j < prisize) { if ((*a)->priflag[j] == 0) { (*a)->prik[i] = j; i++; }j++; }
//	prisize = i;
//
//	(*a)->priv = new int[prisize];
//	for (i = 0; i < prisize; i++)
//		(*a)->priv[i] = 0;
//	(*a)->prisize = prisize;
//	return;
//}
//void privreset(struct pri*a) {
//	int i; for (i = 0; i < a->prisize; i++)a->priv[i] = 0; return;
//}
////素数因子计数-一个数字
//void prif1(struct pri *a,int num,int mode=1) {
//	while (a->priflag[num]) {
//		a->priv[a->priflag[num] - 1] += mode;
//		num /= a->prik[a->priflag[num] - 1];
//	}
//	int i = 0;
//	while (a->prik[i] != num)i++;
//	if (i < a->prisize)a->priv[i]++;
//	return;
//}
////素数因子计数-排列数
//void prifcnm(struct pri *a,int n, int m) {
//	if (n - m < m)m = n - m; int i;
//	privreset(a);
//	//re=n!/(n-m)!
//	for (i = n - m + 1; i <= n; i++)
//		prif1(a, i, 1);
//	//re=re/m!
//	for (i = 1; i <= m; i++)
//		prif1(a, i, -1);
//}
////素数因子导出
//void pri2lint(struct pri *a, struct lint *b) {
//	int i, j;
//	for (i = 0; i < a->prisize; i++)
//		if(a->priv[i])
//			for (j = 0; j < a->priv[i]; j++)
//				lintm(b, a->prik[i]);
//	return;
//}

//题目2-3-3 斐波那契数列 但是是前四项的和

//void reset(struct lint **a) {
//	int i;	for (i = 0; i < 4; i++) { lintreset(a[i]); linta(a[i], 1); }
//}
//void fun(struct lint **a, int n) {
//	//默认n>4
//	int i;
//	for (i = 4; i < n; i++) {
//		linta(a[i % 4], a[(i + 1) % 4]);
//		linta(a[i % 4], a[(i + 2) % 4]);
//		linta(a[i % 4], a[(i + 3) % 4]);
//	}
//	if ((n - 1) % 4 != 0)
//		lintcopy(a[0], a[(n - 1) % 4]);
//	return;
//}
//int main() {
//	int i, n;
//	struct lint *a[4] = { NULL,NULL,NULL,NULL };
//	for (i = 0; i < 4; i++) { lintnew(a+i, lenstep); linta(a[i], 1); }
//	while (~scanf("%d", &n)) 
//	{
//		if (n <= 4)lintprintf(a[n - 1]);
//		else {
//			fun(a, n);
//			lintprintf(a[0]);
//		}
//		reset(a);
//	}
//	return 0;
//}

//题目2-3-4 计算二叉树种类

//void reset_main(struct lint *a, struct pri*b) {
//	lintreset(a); linta(a, 1);
//	privreset(b); return;
//}
//int main() {
//	int n;
//	struct lint *lint = NULL; lintnew(&lint, 10);
//	struct pri *pri = NULL; priset(&pri, 50000);
//	n = 0;
//	while (~scanf("%d", &n)) {
//		reset_main(lint, pri);
//		prifcnm(pri, n * 2, n);
//		prif1(pri, n + 1, -1);
//		pri2lint(pri, lint);
//		lintprintf(lint);
//	}
//	return 0;
//}

//题目2-3-6 划线问题

//void reset_main(struct lint *a, struct pri*b) {
//	lintreset(a); linta(a, 1);
//	privreset(b); return;
//}
//int main() {
//	int i, n;
//	struct lint *lint = NULL; lintnew(&lint, 10);
//	struct pri *pri = NULL; priset(&pri, 50000);
//	n = 0;
//	while (1) {
//		scanf("%d", &n);
//		if (n == -1)break;
//		reset_main(lint, pri);
//		prifcnm(pri, n * 2, n);
//		prif1(pri, n + 1, -1);
//		pri2lint(pri, lint);
//		lintprintf(lint);
//	}
//	return 0;
//}

//题目2-3-8 棋盘游戏

//void reset_main(struct lint *a, struct pri*b) {
//	lintreset(a); linta(a, 1);
//	privreset(b); return;
//}
//int main() {
//	int i, n, isfirst = 1;
//	struct lint *lint = NULL; lintnew(&lint, 10);
//	struct pri *pri = NULL; priset(&pri, 50000);
//	n = 0; i = 0;
//	while (1) {
//		scanf("%d", &n);
//		if (n == -1)break;
//		i++;
//		if (isfirst)isfirst = 0;
//		else printf("\n");
//		printf("%d %d ", i, n);
//		reset_main(lint, pri);
//		prifcnm(pri, n * 2, n);
//		prif1(pri, 2, 1);
//		prif1(pri, n + 1, -1);
//		pri2lint(pri, lint);
//		lintprintf(lint);
//	}
//	return 0;
//}


//题目2-3-57  公共部分 递推特殊catalan数

////字符串加法 & 特殊catalan数 递推法
//#define straddmax 1000
//void stradd(char*a,char*b) {
//	//检查长度
//	int ae = straddmax - 1, be = straddmax - 1;
//	while (a[ae] == 0)ae--; while (b[be] == 0)be--;
//	int ce = ae; if (be > ae)ce = be;
//	//加法
//	int s = 0, i = ce;
//	for (i = 0; i <= ce; i++) {
//		if (i <= ae)s += a[ae - i] - 48;
//		if (i <= be)s += b[be - i] - 48;
//		a[ce - i] = 48 + s % 10;
//		s /= 10;
//	}
//	//进位
//	if (s) { for (i = ce; i >= 0; i--)a[i + 1] = a[i]; a[0] = 49; }
//	return;
//}
//void lintsscan(char*p, int plen, struct lint*a) {
//	//检查长度
//	int pe = plen - 1, i, sum, muti;
//	while (p[pe] == 0)pe--;
//	i = 0; sum = 0; muti = 1;
//	while (1) {
//		sum += muti*(p[pe - i] - 48); muti *= 10;
//
//		if (i % 8 == 7 || i == pe) {
//			linta(a, sum, i / 8);
//			if (i == pe)break;
//			sum = 0; muti = 1;
//		}
//		i++;
//	}
//	return;
//}
//void catafun(int m, int n,struct lint *a) {
//	//初始化
//	char **p = new char*[n + 1];
//	int i, j;
//	for (i = 0; i <= n; i++) {
//		p[i] = new char[straddmax];
//		for (j = 0; j < straddmax; j++)p[i][j] = '\0';
//		p[i][0] = 48;
//	}
//	p[0][0] = 49;
//	//递推
//	for (i = 1; i <= m; i++)
//		for (j = 1; j <= n; j++) {
//			if (j <= i)stradd(p[j], p[j - 1]);
//		}
//	//传值&打印
//	lintsscan(p[n], straddmax, a);
//	//回收内存
//	for (i = 0; i <= n; i++)delete[]p[i];
//	delete[]p;
//	return;
//}
//

//题目2-3-5 买票队列问题

//void printmain(int i,struct lint *a) {
//	printf("Test #%d:\n", i);
//	lintprintf(a);
//}
//int main() {
//	int i, j, m, n;
//	struct lint *a = NULL; lintnew(&a, lenstep);
//	i = 1;
//	while (1) {
//		scanf("%d %d", &m, &n);
//		if (m == 0 && n == 0)break;
//		lintreset(a);
//		catafun(m, n, a);
//		for (j = 1; j <= m; j++)lintm(a, j);
//		for (j = 1; j <= n; j++)lintm(a, j);
//		printmain(i, a);
//		i++;
//	}
//	return 0;
//}

//题目2-3-7 HU字符串排列问题

////字符串加法 & 特殊catalan数 递推法
//#define straddmax 1000
//void stradd(char*a,char*b) {
//	//检查长度
//	int ae = straddmax - 1, be = straddmax - 1;
//	while (a[ae] == 0)ae--; while (b[be] == 0)be--;
//	int ce = ae; if (be > ae)ce = be;
//	//加法
//	int s = 0, i = ce;
//	for (i = 0; i <= ce; i++) {
//		if (i <= ae)s += a[ae - i] - 48;
//		if (i <= be)s += b[be - i] - 48;
//		a[ce - i] = 48 + s % 10;
//		s /= 10;
//	}
//	//进位
//	if (s) { for (i = ce; i >= 0; i--)a[i + 1] = a[i]; a[0] = 49; }
//	return;
//}
//void catafun(int m, int n) {
//	//初始化
//	char **p = new char*[n + 1];
//	int i, j;
//	for (i = 0; i <= n; i++) {
//		p[i] = new char[straddmax];
//		for (j = 0; j < straddmax; j++)p[i][j] = '\0';
//		p[i][0] = 48;
//	}
//	p[0][0] = 49;
//	//递推
//	for (i = 1; i <= m; i++)
//		for (j = 1; j <= n; j++) {
//			if (j <= i)stradd(p[j], p[j - 1]);
//		}
//	//传值&打印
//	printf("%s\n", p[n]);
//	//回收内存
//	for (i = 0; i <= n; i++)delete[]p[i];
//	delete[]p;
//	return;
//}
//int main() {
//	int m, n;
//	while (~scanf("%d %d", &m, &n)) {
//		catafun(m, n);
//	}
//	return 0;
//}



/*======================================================================   #33 - #40  递归与同余   ======================================================================*/

//题目2-2-8 mod(阶乘,2009) 2009=7*287

//int main() {
//	int n, i, re;
//	while (~scanf(""%d"", &n)) {
//		re = 1;
//		if (n >= 41)n = 41;
//		for (i = 1; i <= n; i++)
//			re = (re % 2009)*(i % 2009);
//		re %= 2009;
//		printf(""%d\n"", re);
//	}
//	return 0;
//}

//题目2-2-7 仓库保管员问题(第一类斯特林数)

//int main() {
//	int n, i, j, N, K;
//	long long S[21][21] = { {0} }, sum;
//	//斯特林
//	for (i = 1; i <= 20; ++i)
//	{
//		S[i][i] = 1;
//		S[i][0] = 0;
//		for (j = 1; j < i; ++j)
//			S[i][j] = (i - 1)*S[i - 1][j] + S[i - 1][j - 1];
//	}
//	//main
//	scanf(""%d"", &n);
//	while (n--) {
//		scanf(""%d%d"", &N, &K);
//		sum = 0;
//		for (i = 1; i <= K; ++i)
//			sum += S[N][i] - S[N - 1][i - 1];
//		printf(""%.4lf\n"", 1.0*sum / N / S[N][1]);
//	}
//	return 0;
//}

//题目2-2-6 累加每一位的数字

//int shrink(int n) {
//	int re = 0, muti = 1;
//	while (muti<n&&muti<1000000000)muti *= 10;
//	if (muti>n)muti /= 10;
//	while (n) { re += n / muti; n %= muti; muti /= 10; }
//	return re;
//}
//int main() {
//	char c; int n;
//	while (1) {
//		c = '0', n = 0;
//		do {
//			n += c - '0';
//			scanf(""%c"", &c);
//		} while (c != '\n');
//		if (n == 0)break;
//		while (n>9)n = shrink(n);
//		printf(""%d\n"", n);
//	}
//	return 0;
//}

//题目2-2-5 求此数列的第n项

//int next(int a,int b,int n1, int n2) {
//	return (a*n1 + b*n2) % 7;
//}
//int fun(int a,int b,int n) {
//	a = a % 7; b = b % 7;
//	//1 求出循环长度
//	static int len, d[50];
//	for (len = 0; len < 50; len++)d[len] = 0; len = 0;
//	d[0] = 1; d[1] = 1; len = 2;
//	while (1) {
//		d[len] = (a*d[len - 1] + b*d[len - 2]) % 7;
//		if (d[len] == d[3] && d[len - 1] == d[2] && len != 3)break;
//		len++;
//	}
//	len -= 3;
//	//2 求值
//	if (n < 3)return 1;
//	n -= 3; n %= len; n += 2;
//	return d[n];
//}
//int main() {
//	int a,b,n;
//	while (1) {
//		scanf(""%d%d%d"", &a, &b, &n);
//		if (a == 0)break;
//		printf(""%d\n"", fun(a, b, n));
//	}
//	return 0;
//}

//题目2-2-4 环内点名-判断能否点到全部

//int gcd(int a, int b) {
//	int temp;
//	if (a < b) { temp = b; b = a; a = temp; }
//	while (b) { temp = a%b; a = b; b = temp; }
//	return a;
//}
//int main() {
//	int P,m,n;
//	scanf(""%d"", &P);
//	while(P--){
//		scanf(""%d%d"", &m, &n);
//		if (gcd(m, n) == 1)
//			printf(""NO\n"");
//		else
//			printf(""YES\n"");
//	}
//	return 0;
//}

//题目2-2-3 汉诺塔问题-判断是否最优

//int fun(int g, int b) {
//	int i; for (i = 1; i <= 3; i++) if (g != i&&b != i)return i;
//}
//int judge(int *d, int n) {
//	int i, g, b;
//	b = 2;
//	for (i = n; i >= 1; i--) {
//		if (d[i] == b)return 0;
//		g = d[i]; b = fun(g, b);
//	}
//	return 1;
//}
//int main() {
//	int N, n, i, j, t, cur, d[65];
//	scanf(""%d"", &N);
//	while (N--) {
//		for (i = 0; i < 65; i++)d[i] = 0;
//		scanf(""%d"", &n);
//		for (j = 0; j < 3; j++) {
//			scanf(""%d"", &cur);
//			for (i = 0; i < cur; i++) {
//				scanf(""%d"", &t);
//				d[t] = j + 1;
//			}
//		}
//		if (judge(d, n))
//			printf(""true\n"");
//		else printf(""false\n"");
//	}
//	return 0;
//}

//题目2-2-2 环内点名-求符合要求的最小点名间隔

////A 计算
//int judge(int k, int n) {
//	int i, j, flag;
//	static int f[30];
//	flag = 0;
//	for (j = 0; j < 30; j++)f[j] = 1;
//	i = -1;
//	while (flag<k) {
//		j = (n - 1) % (2 * k - flag) + 1;
//		while (j) {
//			i++;
//			if (i == 2 * k)i = 0;
//			if (f[i])j--;
//		}
//		if (i < k)return 0;
//		f[i] = 0;
//		flag++;
//	}
//	return 1;
//}
//int main() {
//	int k, i;
//	while (1){
//		scanf(""%d"", &k); if (k == 0)break;
//		i = k + 1; while (judge(k, i) == 0)i++;
//		printf(""%d\n"", i);
//	}
//	return 0;
//}
////B 提交
//int main() {
//	int k, d[14] = { 0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881 };
//	while (1) {
//		scanf(""%d"", &k); if (k == 0)break;
//		printf(""%d\n"", d[k]);
//	}
//	return 0;
//}

//题目2-2-1 斐波那契数列

//#include ""math.h""
//double a[21] = { 0, 1, 1 };
//int main()
//{
//	int i, n;
//	double temp, result;
//	for (i = 2; i <= 20; i++)
//	{
//		a[i] = a[i - 1] + a[i - 2];
//	}
//	while (~scanf(""%d"", &n))
//	{
//		if (n <= 20)
//		{
//			printf(""%d\n"", a[n]);
//			continue;
//		}
//		temp = n * log((1.0 + sqrt(5.0)) / 2.0) / log(10.0) - 0.5 * log(5.0) / log(10.0);
//		result = pow(10.0, temp - floor(temp));
//
//		while (result < 1000)
//			result *= 10;
//		printf(""%d\n"", (int)result);
//	}
//	return 0;
//}

/*======================================================================   #25 - #32   素数，最大公因数  ======================================================================*/

//题目2-1-8 (无限循环)小数化为分数

//void lldivgcdll (long long *ia, long long *ib) {
//	long long a = *ia, b = *ib, temp;
//	if (a < b) { temp = b; b = a; a = temp; }
//	while (b != 0) {
//		temp=a%b;
//		a = b;
//		b = temp;
//	}
//	*ia /= a;
//	*ib /= a;
//	return;
//}
//void divs1(char*temp, int size,long long *result,long long*basediv) {
//	int i; int d1 = -1, k1 = -1, k2 = -1, e1 = -1;
//	for (i = 0; i < size; i++) {
//		if (temp[i] == '.')d1 = i;
//		if (temp[i] == '(')k1 = i; 
//		if (temp[i] == ')')k2 = i;
//		if (temp[i] == '\0') { e1 = i; break; }
//	}
//	long long muti = 1, base = 1, infbase = 1, re = 0, retemp = 0, infre = 0;
//	//无限
//	if (k1 != -1) {
//		for (i = k2 - 1; i > k1; i--) {
//			infre += muti*(temp[i] - 48);
//			muti *= 10;
//		}
//		infbase = muti - 1;
//	}
//	//有限
//	muti = 1;
//	for (i = d1 - 1; i >= 0; i--) {
//		re += muti*(temp[i] - 48);
//		muti *= 10;
//	}
//	muti = 1;
//	base = muti;
//	if (k1 == -1)k1 = e1;
//	for (i = k1 - 1; i >d1; i--) {
//		retemp += muti*(temp[i] - 48);
//		muti *= 10;
//	}
//	re *= muti; re += retemp;
//	base = muti;
//	//通分
//	long long re1, base1;
//	re1 = re*infbase + infre;
//	base1 = base*infbase;
//	if (re1 != 0)
//		lldivgcdll(&base1, &re1);
//	//传值
//	*result = re1;
//	*basediv = base1;
//	return;
//}
////有限：k/10^n->k/gcd / 10^n/gcd->整数部分
////无限：k/9999->//gcd 再和有限通分
//int main() {
//	long long re, base;
//	char temp[32]; int size = 32, i, j, n;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < size; j++)temp[j] = '\0';
//		scanf("%s", temp);
//		divs1(temp, size, &re, &base);
//		if(re==0)
//			printf("0\n");
//		else if(base==1)
//			printf("%lld\n", re);
//		else 
//		printf("%lld/%lld\n", re, base);
//	}
//	return 0;
//}

//题目2-1-7 N^N最左侧数字

//
// /*设n^n=a0*10^m+a1*10^(m-1)+...
//a0,a1...为相应位的系数,m为数字位个数,如4^4=256,a0=2,a1=5,a2=6,m=3
//a0*10^m<= n^n< (a+1)*10^m
//两边取对数m+lga0<= nlgn< m+lg(a0+1)即lga0<=nlgn - m<lg(a0+1)
//所以a0<=10^(nlgn-m)<a0+11<=a0<=9,
//所以0<=lga0<1
//由m+lga0<=nlgn<m+lg(a0+1)两边取整得m=[nlgn](表示nlgn的整数部分)
//所以a0=[10^(nlgn-[nlgn])]=pow(10,n*log10(n)-(int)n*log10(n))
//*/
////A
//#include "math.h"
//int cal(int n) {
//	return pow(10.0, n*1.0*log10(n) - (int)(n*1.0*log10(n)));
//}
//int main() {
//	int cn, n, i;
//	scanf("%d", &cn);
//	for (i = 0; i < cn; i++) {
//		scanf("%d", &n);
//		printf("%d\n", cal(n));
//	}
//	return 0;
//}
////B
//#include<cstdio>
//#include<cmath>
//using namespace std;
//int main()
//{
//	int T, i;
//	long long N, ans;
//	double n;
//	scanf("%d", &T);
//	while (T--)
//	{
//		scanf("%lld", &N);
//		n = (double)N;
//		n = n*log10(n);//printf("%lf\n",n);
//		n = n - (long long)n;//printf("%lf\n",n);
//		ans = (long long)pow(10, n);
//		printf("%lld\n", ans);
//	}
//	return 0;
//}

//题目2-1-6 最小公因数 3

//int pri2(int n) {
//	bool *pri = new bool[n];
//	bool *rec = new bool[n];
//	int i, j; for (i = 0; i < n; i++) { pri[i] = 0; rec[i] = 0; }
//	for (i = 2; i < n; i++)
//		if (pri[i] == 0){
//			for (j = i; j < n; j += i)
//				pri[j] = 1;
//			if (n%i == 0)for (j = i; j < n; j += i)
//				rec[j] = 1;
//	}
//	j = 0;
//	for (i = 1; i < n; i++)
//		if (rec[i] == 0)j++;
//	delete[]pri; delete[]rec;
//	return j;
//}
//int main() {
//	int cn, c, n, i;
//	scanf("%d", &cn);
//	for (c = 0; c < cn; c++) {
//		scanf("%d", &n);
//		printf("%d\n", pri2(n));
//	}
//	return 0;
//}

//题目2-1-5 最小公因数 2

////筛质数表
//int mapfun(int i) { return  i / 2 * 6 - 1 + i % 2 * 2; }
//int mapjudge(int cur, int i) {
//	int ca = cur / 2 * 6, cb = (-1 + cur % 2 * 2);
//	int ia = i / 2 * 6, ib = (-1 + i % 2 * 2);
//	int a = ca / 6 * (ia + ib) + ia / 6 * cb;
//	int b = cb*ib;
//	return a * 2 + (b + 1) / 2;
//}
//int mapnext(int*map, int old, int n) {
//	int i = old + 1;
//	if (i >= n)return -1;
//	while (i < n&&map[i] == 0)i++;
//	if (i == n)return -1;
//	return i;
//}
//int mapcreate(int**pmap, int max) {
//	if (max < 2)return 0;
//	//生成
//	int i, cur, n = max / 3 + 2;
//	int *map = new int[n];
//	map[0] = 2; map[1] = 3;
//	for (i = 2; i < n; i++)
//		map[i] = mapfun(i);
//	//筛
//	cur = 1;
//	while (1) {
//		cur = mapnext(map, cur, n);
//		if (cur == -1)break;
//		i = cur;
//		if (mapfun(cur)*mapfun(i) >= max)break;
//
//		i = (mapfun(n) / mapfun(cur) + 2) / 3 + 1;
//		while ((mapfun(cur)*mapfun(i)) > max)i--;
//		while (i >= cur) {
//			if (map[i]) {
//				map[mapjudge(cur, i)] = 0;//此群对乘法封闭 可以这么做
//			}
//			i--;
//		}
//	}
//	cur = 0; i = 0;
//	//整理
//	while (i<n) {
//		i = cur;
//		while (cur < n&&map[cur] != 0)cur++;
//		if (cur == n) { cur = i; break; }
//		i = cur;
//		while (i < n&&map[i] == 0)i++;
//		if (i == n)break;
//		map[cur] = map[i]; map[i] = 0;
//	}
//	n = cur;
//	if (map[n - 1] > max)n--;
//	//传值
//	delete[] * pmap;
//	*pmap = new int[n];
//	for (i = 0; i < n; i++)(*pmap)[i] = map[i];
//	delete[]map;
//	return n;
//}
//int gcd2(int*map,int size,int a, int b) {
//	int i = 0, c1 = a / b;
//	while (i < size&&c1%map[i] == 0)i++;
//	if (i == size)return 0;
//	return b*map[i];
//}
//int main() {
//	int *map = NULL, size = mapcreate(&map, 100000);
//	int n, a, b, i;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		scanf("%d%d", &a,&b);
//		printf("%d\n", gcd2(map, size, a, b));
//	}
//	return 0;
//}

//题目2-1-4 最大素数因子

//#define N 1000000
//int main() {
//	int a[N] = { 0 };
//	int i, j, n = 0;
//	for (i = 2; i < N; i++) 
//	if(a[i]==0){
//		n++;
//		for (j = i; j < N; j += i)
//			a[j] = n;
//	}
//	while (~scanf("%d", &n))
//		printf("%d\n", a[n]);
//	return 0;
//}

//题目2-1-3 切分组合问题

//int gcd(int a, int b) {
//	int temp;
//	if (a < b) { temp = a; a = b; b = temp; }
//	while (b != 0) {
//		temp = a%b;
//		a = b; b = temp;
//	}
//	return a;
//}
//int cakesub(int *total, int *diva, int *divb) {
//	int a, b, temp;
//	if (*diva < *divb) { a = *diva; b = *divb; }
//	else {a = *divb; b = *diva;}
//	int am = *total / a, bm = *total / b;
//	temp = am / bm*a;
//	b -= temp;
//	*total = b*bm;
//	*diva = a; 
//	*divb = b;
//	return temp;
//}
//int cakesub2(int a0, int b0) {
//	int a = a0, b = b0;
//	if (a == 0 && b == 0)return 1;
//	if (a <= 0 || b <= 0)return 1;
//	if (a == b)return a;
//	int re = 0, total = 0;
//	int i;
//	total = a / gcd(a, b)*b;//特别注意
//	while (total != 0)
//		re += cakesub(&total, &a, &b);
//	return re;
//}
//int main() {
//	int a,b;
//	while (~scanf("%d%d", &a, &b)) {
//		printf("%d\n", cakesub2(a, b));
//	}
//	return 0;
//}

//题目2-1-2 质数判断

//筛质数表
//int mapfun(int i) { return  i / 2 * 6 - 1 + i % 2 * 2; }
//int mapjudge(int cur, int i) {
//	int ca = cur / 2 * 6, cb = (-1 + cur % 2 * 2);
//	int ia = i / 2 * 6, ib = (-1 + i % 2 * 2);
//	int a = ca / 6 * (ia + ib) + ia / 6 * cb;
//	int b = cb*ib;
//	return a * 2 + (b + 1) / 2;
//}
//int mapnext(int*map, int old, int n) {
//	int i = old + 1;
//	if (i >= n)return -1;
//	while (i < n&&map[i] == 0)i++;
//	if (i == n)return -1;
//	return i;
//}
//int mapcreate(int**pmap, int max) {
//	if (max < 2)return 0;
//	//生成
//	int i, cur, n = max / 3 + 2;
//	int *map = new int[n];
//	map[0] = 2; map[1] = 3;
//	for (i = 2; i < n; i++)
//		map[i] = mapfun(i);
//	//筛
//	cur = 1;
//	while (1) {
//		cur = mapnext(map, cur, n);
//		if (cur == -1)break;
//		i = cur;
//		if (mapfun(cur)*mapfun(i) >= max)break;
//
//		i = (mapfun(n) / mapfun(cur) + 2) / 3 + 1;
//		while ((mapfun(cur)*mapfun(i)) > max)i--;
//		while (i >= cur) {
//			if (map[i]) {
//				map[mapjudge(cur, i)] = 0;//此群对乘法封闭 可以这么做
//			}
//			i--;
//		}
//	}
//	cur = 0; i = 0;
//	//整理
//	while (i<n) {
//		i = cur;
//		while (cur < n&&map[cur] != 0)cur++;
//		if (cur == n) { cur = i; break; }
//		i = cur;
//		while (i < n&&map[i] == 0)i++;
//		if (i == n)break;
//		map[cur] = map[i]; map[i] = 0;
//	}
//	n = cur;
//	if (map[n - 1] > max)n--;
//	//传值
//	delete[] * pmap;
//	*pmap = new int[n];
//	for (i = 0; i < n; i++)(*pmap)[i] = map[i];
//	delete[]map;
//	return n;
//}
//int ispri(int* map,int size,int n) {
//	int i = 0; while (i < size) {
//		if (n%map[i] == 0)return 0;
//		if (map[i] * map[i] > n)return 1;
//		i++;
//	}
//	return 1;
//}
//int main() {
//	int i, n, temp, count = 0;
//	int*p = NULL, size = 50000;
//	size = mapcreate(&p, size);
//
//	while (~scanf("%d", &n)) {
//		count = 0;
//		for (i = 0; i < n; i++) {
//			scanf("%d", &temp);
//			if (ispri(p, size, temp))count++;
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}

//题目2-1-1 最小公倍数

//int gcd(int a, int b) {
//	int temp;
//	if (a < b) { temp = b; b = a; a = temp; }
//	while (b!=0) {
//		temp = a%b;
//		a = b;
//		b = temp;
//	}
//	return a;
//}
//int main()
//{
//	int a, b;
//	while (~scanf("%d%d", &a, &b)) {
//		printf("%d\n", a*b / gcd(a, b));
//	}
//    return 0;
//}

