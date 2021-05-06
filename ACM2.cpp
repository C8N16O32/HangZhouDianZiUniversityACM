// ACM2.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"

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

