// ACM1-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"

//题目1-3-8 组合数字卡片 并排序输出

//void csort(int *card,int size) {
//	int i, j, temp;//从小到大排序
//	for (i = 0; i < size - 1; i++){
//		temp = i;
//		for (j = i + 1; j < size; j++)
//			if (card[j] < card[temp])
//				temp = j;
//		j = card[temp];
//		card[temp] = card[i];
//		card[i] = j;
//	}
//	return;
//}
//int fchoose(int* f, int size, int n) {
//	int i = 0, c = 0;
//	while (1) {
//		if(f[i] == 1)if (i == size || c == n)break;
//		if (f[i] == 1)c++;
//		i++;
//	}
//	f[i] = 0;
//	return i;
//}
//void cchoose(int *temp, int *card, int size, int n) {
//	int i, div = 1;
//	int flag[4] = { 1,1,1,1 };
//	for (i = 1; i <= size; i++)div *= i;
//	for (i = 0; i < size; i++) {
//		div /= size - i;
//		temp[i] = card[fchoose(flag, size, n / div)];
//		n = n%div;
//	}
//	return;
//}
//int cjudge(int *temp,int *oldtemp, int size) {
//	int i;
//	if (temp[0] == 0)return -1;
//	if (oldtemp[0] == -1) {
//		ret1:
//		for (i = 0; i < size; i++)oldtemp[i] = temp[i];
//		return 1;
//	}
//	for (i = 0; i < size; i++) {
//		if (oldtemp[i] < temp[i])
//			goto ret1;
//		if (oldtemp[i] > temp[i])
//			return 0;
//	}
//	return 0;
//}
//void cprint(int *card, int size) {
//	int i, j, N = 1, temp[4], oldtemp[4] = { -1,-1,-1,-1 }, judge, jcount;
//	for (i = 0; i < size; i++)N *= i + 1;
//	for (i = 0; i < N; i++) {
//
//		if (i % 6 == 0)jcount = 0;
//
//		cchoose(temp, card, size, i);
//		judge = cjudge(temp, oldtemp, size);
//		if (judge==1) {
//			if (jcount != 0)printf(" ");
//			jcount++;
//			for (j = 0; j < size;j++)
//				printf("%d", temp[j]);
//		}
//		
//		if ((i + 1) % 6 == 0 && jcount != 0)printf("\n");
//	}
//}
//int cj2(int *card, int size) {
//	int sum = 0, i;
//	for (i = 0; i < size; i++)
//		sum += card[i];
//	return sum;
//}
//int main() {
//	int card[4], i;
//	int isnew = 1;
//	while (1) {
//		for (i = 0; i < 4; i++)
//			scanf("%d", card + i);
//		if (cj2(card, 4) == 0)break;
//		if(isnew==0)printf("\n");
//		else isnew = 0;
//		csort(card, 4);
//		cprint(card, 4);
//	}
//	return 0;
//}

//题目1-3-7 实时排行榜 拆解字符串

//struct _d { char id[12]; int solve; int score; };
////结构体创建,消除，交换,扩大
//void dcreate(struct _d**p, int size) {
//	*p = new struct _d[size];
//	int i, j; for (i = 0; i < size; i++) {
//		for (j = 0; j < 12; j++)(*p)[i].id[j] = '\0';
//		(*p)[i].score = 0;
//		(*p)[i].solve = 0;
//	}
//	return;
//}
//void ddelete(struct _d *p) {
//	delete[]p; return;
//}
//void dswap(struct _d*a, struct _d*b) {
//	struct _d temp {"",0,0};
//	int i = 0;
//	for (i = 0; i < 12; i++)
//	{
//		temp.id[i] = b->id[i];
//		b->id[i] = a->id[i];
//		a->id[i] = temp.id[i];
//	}
//	temp.score = b->score; b->score = a->score; a->score = temp.score;
//	temp.solve = b->solve; b->solve = a->solve; a->solve = temp.solve;
//	return;
//}
//void dgrow(struct _d**p, int sizeold,int sizenew) {
//	struct _d *temp=new struct _d[sizeold];
//	int i; for (i = 0; i < sizeold; i++)dswap(*p + i, temp + i);
//	delete[] * p;
//	dcreate(p, sizenew);
//	for (i = 0; i < sizeold; i++)
//		dswap(*p + i, temp + i);
//	delete[]temp;
//	return;
//}
////排序条件判断 优先级从高到低：solve(更高)，score(更低)，id(更低/少)
//int dcmpid(char*now, char*temp) {
//	int ne = 0, te = 0, i;
//	while (now[ne] != '\0')ne++;
//	while (temp[te] != '\0')te++;
//	if (ne < te)return 1; if (ne > te)return 0;
//	for (i = 0; i < ne; i++) {
//		if (now[i] < temp[i])return 1;
//		if (now[i] > temp[i])return 0;
//	}
//	return 0;
//}
//int dcmp(struct _d*now, struct _d*temp) {
//	if (now->solve > temp->solve)return 1;
//	if (now->solve < temp->solve)return 0;
//	if (now->score < temp->score)return 1;
//	if (now->score > temp->score)return 0;
//	return dcmpid(now->id, temp->id);
//}
////冒泡排序
//void dsort(struct _d*p,int I) {
//	int i, j, temp;
//	for (i = 0; i < I - 1; i++) {
//		temp = i;
//		for (j = i + 1; j < I; j++)
//			if (dcmp(p + j, p + temp))
//				temp = j;
//		dswap(p + i, p + temp);
//	}
//}
////拆解字符串 得到score
//int dwrite(char*temp,int m) {
//	int I = 0;
//	while (temp[I] != '\0')I++;
//	//是否是负数
//	int i = 0; while (i < I) {
//		if (temp[i] == '-')return 0; i++;
//	}
//	//是否左括号
//	int k = -1;
//	i = 0; while (i < I) {
//		if (temp[i] == '(') { k = i; break; }
//		i++;
//	}
//	//不含括号
//	int re = 0, muti = 1;
//	if (k == -1) {
//		for (i = I-1; i >= 0; i--) {
//			re += muti*(temp[i] - 48);
//			muti *= 10;
//		}
//		return re;
//	}
//	//括号
//	for (i = k - 1; i >= 0; i--) {
//		re += muti*(temp[i] - 48);
//		muti *= 10;
//	}
//	muti = 1;
//	for (i = I - 2; i > k; i--) {
//		re += m*muti*(temp[i] - 48);
//		muti *= 10;
//	}
//	return re;
//}
//
//int main() {
//	int i, j, I = 0, m, n, size = 0, sizestep = 32, re = 0;
//	char temp[12] = { 0 };
//	struct _d *p = NULL;
//	dcreate(&p, sizestep); size += sizestep;
//
//	//输入
//	scanf("%d%d", &n, &m);
//
//	while (1) {
//		scanf("%s", p[I].id);
//		for (i = 0; i < n; i++) {
//			for (j = 0; j < 12; j++)temp[j] = '\0';
//			scanf("%s", temp);
//			re = dwrite(temp, m);
//			if (re > 0) {
//				p[I].solve++;
//				p[I].score += re;
//			}
//		}
//		//动态扩大
//		I++; if (I == size) {
//			dgrow(&p, size, size + sizestep);
//			size += sizestep;
//		}
//		//排序
//		dsort(p, I);
//		//输出
//		printf("\n排序：\n");
//		for (i = 0; i < I; i++)
//			printf("%-10s %2d %4d\n", p[i].id, p[i].solve, p[i].score);
//		printf("\n\n");
//	}
//	//释放内存
//	ddelete(p);
//	return 0;
//}

//题目1-3-6 分割数字串然后排序

//void printanddel(char*p) {
//	int i = 0;
//	while (p[i] == '0') { p[i] = '\0'; i++; }
//	if (p[i] == '\0') { printf("0"); return; }
//	while (p[i] != '\0') { printf("%c", p[i]); p[i] = '\0'; i++; }
//	return;
//}
//char *nexthead(char*p, char*old, int size) {
//	int i = 0;
//	//寻找第一个
//	if (old == NULL) {
//		while (p[i] == '\0'&&i < size)i++;
//		if (i == size)return NULL;
//		return p + i;
//	}
//	//寻找下一个
//	i = old - p;
//	while (p[i] != '\0')i++;
//	while (p[i] == '\0'&&i < size)i++;
//	if (i == size)return NULL;
//	return p + i;
//}
////比较两个起头(input更小则输出1
//int ccmp(char*pi, char*pt) {
//	int ii = 0, ti = 0, ie = 0, te = 0, I, E;
//	int i = 0;
//	while (pi[ii] == '0')ii++;
//	while (pt[ti] == '0')ti++;
//	ie = ii; te = ti;
//	while (pi[ie] != '\0')ie++;
//	while (pt[te] != '\0')te++;
//	if (ti == te)return 0;//暂存是0
//	if (ii == ie)return 1;
//	if (ie - ii > te - ti)return 0;
//	if (ie - ii < te - ti)return 1;//输入的位数更少
//	for (i = 0; i < ie - ii; i++) {
//		if (pi[ii + i] > pt[ti + i])return 0;
//		if (pi[ii + i] < pt[ti + i])return 1;
//	}
//	return 0;
//}
//int main() {
//	int i, isfirst = 1;
//	char d[1024] = { '\0' }; 
//	char *cur = NULL, *temp = NULL;
//	while (~scanf("%s", d)) {
//		//处理字符5
//		for (i = 0; i < 1024; i++)
//			if(d[i]=='5')
//				d[i] = '\0';
//		//输出
//		isfirst = 1;
//		while (1) {
//			cur = nexthead(d, NULL, 1024);
//			if (cur == NULL) { printf("\n"); break; }
//			if (isfirst == 1)isfirst = 0;
//			else printf(" ");
//			temp = cur;
//			while (cur = nexthead(d, cur, 1024))
//				if (ccmp(cur, temp))
//					temp = cur;
//			printanddel(temp);
//		}
//		//初始化
//		for (i = 0; i < 1024; i++)
//			d[i] = '\0';
//	}
//}

//题目1-3-5 特定输出方法

//int main() {
//	int i, j, tempi, n;
//	int d[10000] = { 0 };
//	while (~scanf("%d", &n)) {
//		for (i = 0; i < 10000; i++)
//			d[i] = 0;
//		for (i = 0; i < n; i++)
//			scanf("%d", d + i);
//		for (i = 0; i < n - 1; i++) {
//			tempi = i;
//			for (j = i + 1; j < n; j++)
//				if (d[j] > d[tempi])
//					tempi = j;
//			j = d[tempi];
//			d[tempi] = d[i];
//			d[i] = j;
//		}
//		for (i = 0; i < n; i++) {
//			if (i % 2)
//				printf("%d", d[n - i / 2 - 1]);
//			else
//				printf("%d", d[i / 2]);
//			if (i < n - 1)printf(" ");
//			else printf("\n");
//		}
//	}
//	return 0;
//}

//题目1-3-4 时间字符串的排序

//struct _d { int solve; char time[9]; };
//void dcreate(struct _d **p, int size) {
//	*p = new struct _d[size];
//	int i, j; for (i = 0; i < size; i++) {
//		for (j = 0; j < 9; j++)(*p)[i].time[j] = '\0';
//		(*p)[i].solve = 0;
//	}
//	return;
//}
//void ddelete(struct _d *p) {
//	delete[] p;
//	return;
//}
//int timecmp(char*pi, char*pt) {
//	int i=0;
//	while (i < 9) {
//		if (pi[i] < pt[i])return 1;//pi更早
//		if (pi[i] > pt[i])return 0;
//		i++;
//	}
//	return 0;
//}
//int timep1(struct _d *p, int size, int solve) {
//	int i, re = 0; 
//	for (i = 0; i < size; i++)
//		if (p[i].solve == solve)re++;
//	return re;
//}
//void timep2(struct _d *p, int size, int solve) {
//	int i, j, tempi, re;
//	re = timep1(p, size, solve) / 2;
//	for (i = 0; i < re; i++) {
//		tempi = -1;
//		for (j = 0; j < size; j++)
//			if (p[j].solve == solve) {
//				if (tempi == -1)
//					tempi = j;
//				if (timecmp(p[j].time, p[tempi].time))
//					tempi = j;
//			}
//		if(tempi!=-1)
//			p[tempi].solve += 5;
//	}
//	return;
//}
//void timep3(struct _d*p, int size) {
//	int i; 
//	for (i = 0; i < size; i++)
//		p[i].solve = p[i].solve * 10 + 50;
//	for (i = 90; i >= 60; i-=10)
//		timep2(p, size, i);
//}
//int main() {
//	int i, n;
//	struct _d *p = NULL;
//	while (1) {
//		scanf("%d", &n);
//		if (n < 0)break;
//		dcreate(&p, n);
//		for (i = 0; i < n; i++) {
//			scanf("%*[^\n]"); scanf("%*c");
//			scanf("%d%s", &p[i].solve, p[i].time);
//		}
//		timep3(p, n);
//		for (i = 0; i < n; i++)
//			printf("%d\n", p[i].solve);
//		printf("\n");
//		ddelete(p);
//	}
//	return 0;
//}

//题目1-3-3 时间字符串的最值

//struct __d__ { char id[16]; char enter[9]; char out[9]; };
//void dcreate(struct __d__ **p, int size) {
//	*p = new struct __d__[size];
//	int i, j; for (i = 0; i < size; i++) {
//		for (j = 0; j < 16; j++)(*p)[i].id[j] = '\0';
//		for (j = 0; j < 9; j++)(*p)[i].enter[j] = '\0';
//		for (j = 0; j < 9; j++)(*p)[i].out[j] = '\0';
//	}
//	return;
//}
//void ddelete(struct __d__ *p) {
//	delete[] p;
//	return;
//}
//int timecmp(char*time1, char*time2) {
//	int i=0;
//	while (i < 8) {
//		if (time1[i] > time2[i])return 1;//时间1更晚
//		if (time1[i] < time2[i])return -1;//时间1更早
//		i++;
//	}
//	return 0;//输入保证不会出现同时情况
//}
//int timemain(struct __d__ *p, int size,int islarge) {
//	int i, tempi;
//	tempi = 0;
//	if (islarge == 0) {
//		for (i = 0; i < size; i++)
//			if (timecmp(p[i].enter, p[tempi].enter) == -1)
//				tempi = i;
//		return tempi;
//	}
//	else {
//		for (i = 0; i < size; i++)
//			if (timecmp(p[i].out, p[tempi].out) == 1)
//				tempi = i;
//		return tempi;
//	}
//}
//int main() {
//	int i, m, n, M, N;
//	struct __d__ *p = NULL;
//	scanf("%d", &M);
//	for (m = 0; m < M; m++) {
//		scanf("%d", &N);
//		dcreate(&p, N);
//		for (n = 0; n < N; n++) {
//			//scanf("%*[^\n]"); scanf("%*c");
//			scanf("%s%s%s", p[n].id, p[n].enter, p[n].out);
//		}
//		printf("%s %s\n", p[timemain(p, N, 0)].id, p[timemain(p, N, 1)].id);
//		ddelete(p);
//	}
//
//}

//题目1-3-2 字符串的排序

//int comp1(char* pj, char* pt) {
//	int i;
//
//	i = 0;
//	while (pj[i] != '\0'&&i < 21) {
//		if (pj[i] < pt[i])return 1;
//		if (pj[i] > pt[i])return 0;
//		i++;
//	}
//	return 0;
//}
//int main() {
//	int N, M, G;
//	int i, j, J, k;
//	char p[1000][21] = { {0} };
//	int re[1000] = { {0} };
//	int temp = 0;
//	int score[10] = { 0 };
//
//	int tempi; char tempp[21]; int tempre;
//
//	while (1) {
//		scanf("%d", &N);
//		if (N == 0)break;
//		scanf("%d %d", &M, &G);
//		//初始化
//		for (i = 0; i < 1000; i++) {
//			for (j = 0; j < 21; j++)p[i][j] = '\0';
//			re[i] = 0;
//		}
//		//各题满分
//		for (i = 0; i < M; i++)
//			scanf("%d", score + i);
//		//各考生信息
//		for (i = 0; i < N; i++) {
//			scanf("%*[^\n]"); scanf("%*c");
//			scanf("%s%d", p + i, &J);
//			for (j = 0; j < J; j++) {
//				scanf("%d", &temp);
//				re[i] += score[temp - 1];
//			}
//		}
//		//1 根据考号升序排序
//		for (i = 0; i < N; i++) {
//			tempi = i;
//			for (k = 0; k < 21; k++)tempp[k] = p[i][k];
//			for (j = i + 1; j < N; j++)
//				if (comp1(p[j], tempp)) {
//					tempi = j;
//					for (k = 0; k < 21; k++)tempp[k] = p[j][k];
//				}
//			//交换
//			tempre = re[tempi];
//
//			for (k = 0; k < 21; k++)p[tempi][k] = p[i][k];
//			re[tempi] = re[i];
//			for (k = 0; k < 21; k++)p[i][k] = tempp[k];
//			re[i] = tempre;
//			//交换 end
//		}
//		//2 根据成绩降序排序 最高项向前插入
//		for (i = 0; i < N; i++) {
//			tempi = i;
//			tempre = re[i];
//			for (j = i + 1; j < N; j++)
//				if (re[j]>tempre) {
//					tempi = j;
//					tempre = re[j];
//				}
//			//交换
//			for (k = 0; k < 21; k++)tempp[k] = p[tempi][k];
//
//			for (j = tempi; j > i; j--) {
//				for (k = 0; k < 21; k++)p[j][k] = p[j - 1][k];
//				re[j] = re[j - 1]; }
//			for (k = 0; k < 21; k++)p[i][k] = tempp[k];
//			re[i] = tempre;
//			//交换 end
//		}
//		//统计个数
//		temp = 0;
//		for (i = 0; i < N; i++)
//			if (re[i] >= G)temp++;
//		//打印
//		printf("%d\n", temp);
//		for (i = 0; i < temp; i++)
//			printf("%s %d\n", p[i], re[i]);
//
//	}
//	return 0;
//}

//题目1-3-1 简易最优交易问题

////链表单元
//struct __chain1__ { double key; int valueget; int valuepay; };
////数组链表_创建主链
//void chain1_create(struct __chain1__ **p, int size) {
//	*p = new struct __chain1__[size];
//	int i; for (i = 0; i < size; i++) {
//		//初始化
//		((*p) + i)->key = 0;
//		((*p) + i)->valueget = 0;
//		((*p) + i)->valuepay = 0;
//		//初始化 end
//	}
//	return;
//}
////数组链表_删除全部
//void chain1_remove(struct __chain1__ **p, int size) {
//	//删除主链
//	delete[] * p;
//	return;
//}
////数组链表_主链简单排序
//void chain1_swap1(struct __chain1__ *a, struct __chain1__ *b) {
//	struct __chain1__ temp;//主链是数组，不能单纯操作指针完成交换
//	//交换方法
//	temp.key = a->key;
//	a->key = b->key;
//	b->key = temp.key;
//	temp.valueget = a->valueget;
//	a->valueget = b->valueget;
//	b->valueget = temp.valueget;
//	temp.valuepay = a->valuepay;
//	a->valuepay = b->valuepay;
//	b->valuepay = temp.valuepay;
//	//交换方法 end
//	return;
//}
//void chain1_sort1(struct __chain1__ **p, int sortstart, int sortendplus1, int sortL2M) {
//	int i, j;
//	int tempi;
//	for (i = sortstart; i < sortendplus1 - 1; i++) {
//		tempi = i;
//		if (sortL2M) {
//			for (j = i + 1; j < sortendplus1; j++)
//				if ((*p + j)->key >(*p + tempi)->key) {
//					tempi = j;
//				}
//		}
//		else {
//			for (j = i + 1; j < sortendplus1; j++)
//				if ((*p + j)->key < (*p + tempi)->key) {
//					tempi = j;
//				}
//		}
//		chain1_swap1(*p + i, *p + tempi);
//	}
//	return;
//}
//int main() {
//	int m, n;
//	int i, a, b;
//	double get = 0;
//	struct __chain1__ *p = NULL;
//	while (1) {
//		scanf("%d%d", &m, &n);
//		if (m == -1)break;
//		chain1_create(&p, n);
//		for (i = 0; i < n; i++) {
//			scanf("%d%d", &a, &b);
//			p[i].key = a*1.0 / b;
//			p[i].valueget = a;
//			p[i].valuepay = b;
//		}
//		chain1_sort1(&p, 0, n, 1);
//
//		get = 0; i = 0;
//		while (m > 0 && i < n) {
//			if (m > p[i].valuepay) {
//				m-=p[i].valuepay;
//				get += p[i].valueget;
//			}
//			else {
//				get += m*1.0 / p[i].valuepay*p[i].valueget;
//				m = 0;
//			}
//			i++;
//		}
//		printf("%.3lf\n", get);
//		chain1_remove(&p, n);
//	}
//	return 0;
//}

//题目8 数字转字符串

//int main() {
//	int n, i; char *p = NULL;
//	scanf("%d", &n);
//	p = new char[n];
//	for (i = 0; i < n; i++)
//		scanf("%d", p + i);
//	printf("%s", p);
//	return 0;
//}

//题目7 简易字符串处理

//#include "string.h"
//#define L 64
//int main() {
//	int n, i, j, J;
//	char temp[L];
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		memset(temp, 0, L);
//		scanf("%*[^\n]"); scanf("%*c");
//		scanf("%[^\n]", temp);
//		J = strlen(temp);
//		printf("String #%d\n", i + 1);
//		for (j = 0; j < J; j++) {
//			if (temp[j] == 'Z')printf("A");
//			else printf("%c", temp[j] + 1);
//		}
//		printf("\n\n");
//	}
//	return 0;
//}

//题目6 简易符号表达式

//int main() {
//	char c;
//	int n, i, a, b;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		scanf("%*[^\n]"); scanf("%*c");
//		scanf("%c %d %d", &c, &a, &b);
//		switch (c)
//		{
//		case '+':printf("%d\n", a + b); break;
//		case '-':printf("%d\n", a - b); break;
//		case '*':printf("%d\n", a * b); break;
//		case '/':
//			if (a / b*b == a)printf("%d\n", a / b);
//			else printf("%.2lf\n", a*1.0 / b);
//			break;
//		default:
//			break;
//		}
//	}
//	return 0;
//}

//题目5 判断直角三角形

//int judge(int a,int b,int c) {
//	int d[3] = { a,b,c };
//	int i, j, temp = 0, tempi = 0;
//	for (i = 0; i < 3 - 1; i++) {
//		temp = d[i];
//		tempi = i;
//		for (j = i; j < 3 - 1; j++)
//			if (d[j + 1] > temp) {
//				temp = d[j + 1];
//				tempi = j + 1;
//		}
//		d[tempi] = d[i];
//		d[i] = temp;
//	}
//	if (d[0] * d[0] - d[1] * d[1] - d[2] * d[2] == 0)return 1;
//	return 0;
//}
//int main() {
//	int i = 0, I = 0, a, b, c;
//	scanf("%d", &I);
//	for (i = 1; i <= I;i++) {
//		scanf("%d%d%d", &a, &b, &c);
//		if(judge(a,b,c))
//		printf("Scenario #%d:\n"
//			"yes\n\n",i);
//		else
//		printf("Scenario #%d:\n"
//			"no\n\n",i);
//	}
//	return 0;
//}

//题目4 x^x尾数

////链表单元
//struct __chain1__ { int key; int value; struct __chain1__ *next; };
////数组链表_创建主链
//void chain1_create(struct __chain1__ **p, int size) {
//	*p = new struct __chain1__[size];
//	int i; for (i = 0; i < size; i++) {
//		//初始化
//		((*p) + i)->key = 1;
//		((*p) + i)->value = i;
//		((*p) + i)->next = NULL;
//		//初始化 end
//	}
//	return;
//}
////数组链表_创建/延长支链
//void chain1_grow(struct __chain1__ *end) {
//	end->next = new __chain1__;
//	//初始化
//	end->next->key = end->key * 2;
//	end->next->value = (end->value*end->value) % 10;
//	end->next->next = NULL;
//	//初始化 end
//	return;
//}
////数组链表_删除全部
//void chain1_remove(struct __chain1__ **p, int size) {
//	//删除支链
//	struct __chain1__ *cur, *next;//操作顺序：先更新next 后删除cur
//	int i; for (i = 0; i < size; i++)
//		if ((*p + i)->next != NULL) {
//			next = (*p + i)->next;
//			do {
//				cur = next;
//				next = cur->next;
//				delete cur;
//			} while (next != NULL);
//		}
//	//删除主链
//	delete[] * p;
//	return;
//}
////数组链表_写入
//int chain1_main(struct __chain1__ **p, int num, int size) {
//	int a = num%size;
//	struct __chain1__ *temp = *p + a;
//	int re = 1;
//	while (num > 0) {
//		//延长链表
//		if (temp->next == NULL)chain1_grow(temp);
//		//计算
//		if (num % 2)
//			re = (re*temp->value) % 10;
//		//下一循环
//		temp = temp->next;
//		num = num / 2;
//	}
//	return re;
//}
//int main() {
//	int i = 0, I = 0, n = 0;
//	struct __chain1__ *p = NULL;
//	scanf("%d", &I);
//	for (i = 0; i < I;i++) {
//		chain1_create(&p, 10);
//		scanf("%d", &n);
//		printf("%d\n", chain1_main(&p, n, 10));
//		chain1_remove(&p, 10);
//	}
//	return 0;
//}

//题目3 统计各项重复次数

////链表单元
//struct __chain1__ { int key; int value; struct __chain1__ *next; };
////数组链表_创建主链
//void chain_create(struct __chain1__ **p,int size) {
//	*p = new struct __chain1__[size];
//	int i; for (i = 0; i < size; i++) {
//		((*p) + i)->key = i;
//		((*p) + i)->value = 0;
//		((*p) + i)->next = NULL;
//	}
//	return;
//}
////数组链表_创建/延长支链
//void chain_grow(struct __chain1__ *end, int num) {
//	end->next = new __chain1__;
//	end->next->key = num;//既存项目没有num 则新增
//	end->next->value = 1;//计数+1
//	end->next->next = NULL;
//	return;
//}
////数组链表_删除全部
//void chain_remove(struct __chain1__ **p, int size) {
//	//删除支链
//	struct __chain1__ *cur, *next;//操作顺序：先更新next 后删除cur
//	int i; for (i = 0; i < size; i++)
//		if ((*p + i)->next != NULL){
//			next = (*p + i)->next;
//			do {
//				cur = next;
//				next = cur->next;
//				delete cur;
//			} while (next != NULL);
//	}
//	//删除主链
//	delete[] * p;
//	return;
//}
////数组链表_查找特定key
//struct __chain1__ *chain_searchkey(struct __chain1__ **p, int num,int size) {
//	struct __chain1__ *cur;
//	cur = *p + num%size;
//	while (cur->key != num&&cur->next != NULL)
//		cur = cur->next;
//	return cur;
//}
////数组链表_查找特定value
//int chain_searchvalue(struct __chain1__ **p, int num, int size) {
//	struct __chain1__ *cur;
//	int i;
//	for (i = 0; i < size; i++) {
//		cur = *p + i;
//		while (cur->value % 2 == 0 && cur->next != NULL)//特殊规则：value是奇数即可
//			cur = cur->next;
//		if (cur->value % 2 == 1)break;//特殊规则：value是奇数即可
//	}
//	return cur->key;//特殊规则：value是奇数即可 必存在一个奇数value
//}
////数组链表_写入
//void chain_input(struct __chain1__ **p, int num, int size) {
//	int a = num%size;
//	struct __chain1__ *temp = *p + a;
//	temp = chain_searchkey(p, num, size);
//	if (temp->key == num)temp->value += 1;
//	else chain_grow(temp, num);
//	return;
//}
////主函数
//int main() {
//	int i, n;
//	int num = 0, size = 32;
//	struct __chain1__ *p = NULL;
//
//	while (1) {
//		scanf("%d", &n);
//		if (n == 0)break;
//		chain_create(&p, size);
//
//		for (i = 0; i < n; i++) {
//			scanf("%d", &num);
//			chain_input(&p, num, size);
//		}
//
//		printf("%d\n", chain_searchvalue(&p, 1, size));
//		chain_remove(&p, size);
//		p = NULL;
//	};
//}

//题目2 一个简单题目

//int judge(int a,int b,int c) {
//	if (b - c == a)return 3;
//	if (b - c > a)return 1;
//	return 2;
//}
//int main() {
//	int I;
//	scanf("%d", &I);
//	int *a = new int[I*3];
//	int i;
//	for (i = 0; i < I; i++)
//		scanf("%d %d %d", a + i * 3, a + i * 3 + 1, a + i * 3 + 2);
//	for (i = 0; i < I; i++)
//		switch (judge(a[i * 3], a[i * 3 + 1], a[i * 3 + 2]))
//		{
//		case 1:printf("advertise\n"); break;
//		case 2:printf("do not advertise\n"); break;
//		case 3:printf("does not matter\n"); break;
//		}
//}

//一维动态数组

//void changesize1(int **a, int sizeold, int sizenew) {
//	int i;
//	if (sizenew == 0) {
//		delete[] * a;//对空指针delete是安全的
//		return;
//	}
//	if (sizeold == 0) {
//		*a = new int[sizenew];
//		for (i = 0; i < sizenew; i++)(*a)[i] = 0;
//		return;
//	}
//	//新建 转移 删除1
//	int *temp = new int[sizeold];
//	for (i = 0; i < sizeold; i++)temp[i] = *(*a + i);
//	delete[] * a;
//	//新建，转移，删除2
//	*a = new int[sizenew];
//	for (i = 0; i < sizenew; i++)(*a)[i] = 0;
//	if (sizenew > sizeold)
//		for (i = 0; i < sizeold; i++)(*a)[i] = temp[i];
//	else
//		for (i = 0; i < sizenew; i++)(*a)[i] = temp[i];
//	delete[] temp;
//	return;
//}

//题目1 上爬昆虫问题

//void changesize1(int **a, int sizeold, int sizenew) {
//	//新建 转移 删除1
//	int i;
//	int *temp = new int[sizeold];
//	for (i = 0; i < sizeold; i++)temp[i] = *(*a + i);
//	delete[] * a;
//	//新建，转移，删除2
//	*a = new int[sizenew];
//	for (i = 0; i < sizenew; i++)(*a)[i] = 0;
//	//默认sizenew更大
//	for (i = 0; i < sizeold; i++)(*a)[i] = temp[i];
//	delete[] temp;
//	return;
//}
//int main()
//{
//	int i, n = 0;
//	int *a = NULL, I = 0;
//	i = -1;
//	do {
//		i++;
//		if (i == I) {
//			changesize1(&a, I, I + 32);
//			I += 32;
//		}
//		scanf("%d %d %d", a + i * 3, a + i * 3 + 1, a + i * 3 + 2);
//	} while (a[3 * i + 1] != 0);
//
//	n = i;
//	int count=0, cur=0;
//	for (i = 0; i < n; i++) {
//		count = 0; cur = a[i * 3 + 2];
//		do {
//			cur -= a[i * 3 + 2];
//			cur += a[i * 3 + 1];
//			count++;
//		} while (cur < a[i * 3]);
//		printf("%d\n", count*2-1);
//	}
//
//    return 0;
//}
