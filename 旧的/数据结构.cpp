/*======================================================================   目录   ======================================================================*/
5. hashmap
6. skiplist用于多种用途 template<class K = int, class T = int> class Slist
1. 循环队列/栈两用结构 template<class T> class QUEUE
2. 双向循环链表(带有key) template<class T, typename K> class LIST
3. 优先队列 template<class T, typename K> class PRIQUE  需要使用 (1) 与 (2)   将1的对象作为2的模板里的T
4. 点与点阵基类

/*======================================================================   hashmap   ======================================================================*/
//开放地址法hashmap太简单了 等拉链法hashmap写好放拉链法的
/*======================================================================   skiplist   ======================================================================*/
//skiplist
template<class K, class V>
struct Slist{
	static const int pmax=16;
	//节点
	struct N {
		const int plen; N**p;
		K k; V v;
		N(int p0) :plen(p0) { p = new N*[plen]; for (int i = 0; i < plen; i++)p[i] = NULL; };
		~N() { delete[]p; };
	}*head, *tail;
	N* gethead() { return head; } N* gettail() { return tail; }
	N* getrtail() { return head->p[0]; }//需要注意 这里的head节点与tail节点都是不保存数据的。实际使用中要getrtail和getrhead
	//比较
	int cmpmode = 0; void setcmpmode(int mode) { cmpmode = mode; }
	bool cmp(const K&temp, const K&k) {
		if (cmpmode == 0) {
			if (temp >= k)return 0; return 1;
		}
		else {
			if (temp <= k)return 0; return 1;
		}
	}
	//查
	N*pleft[pmax];
	N* find_impl(const K&k) {
		int i = pmax - 1; N*cur = head;
		while (i >= 0) {
			while (cur->p[i] != tail&&cmp(cur->p[i]->k, k))
				cur = cur->p[i];
			pleft[i] = cur; i--;
		}
		return cur;
	}
	//增删
	int msize = 0; N*rhead;
	bool isempty() { if (msize == 0)return 1; return 0; }
	int size() { return msize; }
	N* getrhead() { return rhead; } //需要注意 这里的head节点与tail节点都是不保存数据的。实际使用中要getrtail和getrhead
	N* push_impl(N*n) {
		msize++;
		for (int i = 0; i < n->plen; i++) {
			n->p[i] = pleft[i]->p[i];
			pleft[i]->p[i] = n;
		}
		if (n->p[0] == tail)rhead = n;
		return n;
	}
	void erase_impl() {
		msize--;
		N*n = pleft[0]->p[0];
		for (int i = 0; i < n->plen; i++)
			pleft[i]->p[i] = n->p[i];
		delete n;
		if (pleft[0]->p[0] == tail)rhead = pleft[0];
	}
	//初始化
	void set() {
		head = new N(pmax); tail = new N(pmax); rhead = tail;
		for (int i = 0; i < pmax; i++) { head->p[i] = tail; pleft[i] = head; }
		msize = 0;
	}
	void reset() {
		N*cur;
		while (head->p[0] != tail) {
			cur = head; head = head->p[0]; delete cur;
		}
		delete head; delete tail;
		set();
	}
	Slist() { set(); }
	~Slist() {
		N*cur;
		while (head->p[0] != tail) {
			cur = head; head = head->p[0]; delete cur;
		}
		delete head; delete tail;
	}
	//线性散列
	int max = 1 << pmax, ma = 0, mb = max / 7 / 6 * 6 + 1;
	int rrand() { return ma = (ma + mb) % max; }
	int prand() {
		int p = pmax, r = rrand();
		while (p > 1 && r) { r >>= 1; p--; }
		if (p == pmax&&r)return 1;
		return p;
	}
	//封装A
	bool isitexist(const K&k) {
		N*cur = find_impl(k)->p[0];
		if (cur != tail&&cur->k == k)return 1;
		return 0;
	}
	V&getit() { return pleft[0]->p[0]->v; }
	V&pushit(const K&k, const V&v) {
		N*cur = new N(prand());
		cur->k = k; cur->v = v;
		push_impl(cur);
		return cur->v;
	}
	void eraseit() { erase_impl(); }
	//封装B
	V&get(const K&k) { find_impl(k); return getit(); }
	V&push(const K&k, const V&v) { find_impl(k); return pushit(k, v); }
	void erase(const K&k) { find_impl(k); eraseit(); }
	//遍历模板
	template<class F,class ...FR>
	void foreachKey(F f, FR ...args) {
		for (N*cur = head->p[0]; cur != tail; cur = cur->p[0])
			f(cur->k, args...);
	}
	template<class F, class ...FR>
	void foreachValue(F f, FR ...args) {
		for (N*cur = head->p[0]; cur != tail; cur = cur->p[0])
			f(cur->v, args...);
	}
};


BFS/DFS
BFS使用队列，有时可以使用队列链表实现优先队列
DFS有多种用法 通常使用栈，但是要在T里放回调标志与回调函数
简陋： 队列/栈的大小发生改变时 元素的引用或指向元素的指针会失效。应在失效前进行操作 或者在必要的时候重新获得引用或指向元素的指针
/*======================================================================   循环队列/栈   ======================================================================*/
template<class T>
class QUEUE{
	int mhead = 0, mend = 0, mcapacity = 0; T*v = NULL;
	bool isempty() { if (mend == mhead)return 1; return 0; }
	int size() { return mend - mhead; }
	int mcapadef = 16, mheat = 0, mheatdef = 8;
	//动态数组
	void changecapacity(int capanew) {
		int s1 = mhead, l1 = size(), s2 = 0, l2 = 0;
		if (mend > mcapacity) { l2 = mend - mcapacity; l1 = mcapacity - mhead; }
		T*temp = new T[capanew]; int i;
		for (i = s1; i < s1 + l1; i++)temp[i - s1] = v[i]; 
		for (i = s2; i < s2 + l2; i++)temp[i - s2 + l1] = v[i];
		delete[]v; v = temp; temp = NULL;
		mhead = 0; mend = l1 + l2; mcapacity = capanew;
	}
	void checkcapacity(int needone) {
		int capaneed = needone + size(), capanew = mcapadef;
		while (capanew < capaneed)capanew *= 2;
		if (capanew > mcapacity) { changecapacity(capanew); mheat = mheatdef; return; }
		if (mheat > 0) { mheat--; return; }
		if (capanew < mcapacity) { changecapacity(capanew); mheat = mheatdef; return; }
	}
	//输入输出
	void push_end(const T&x) { checkcapacity(1); v[mend%mcapacity] = x; mend++; }
	//以下四个执行前必须检查isempty
	T&head() { return v[mhead]; }
	T&rhead() { return v[(mend - 1) % mcapacity]; }
	void pop_head() { mhead++; if (mhead == mcapacity) { 
		mhead = 0; mend -= mcapacity; }checkcapacity(0); }
	void pop_end() { mend--; checkcapacity(0); }
	//构造/析构
	void Reset() { delete[]v; v = NULL; mhead = 0; mend = 0; mcapacity = 0; }
	~queue() { if (v != NULL)Reset(); };
	void operator=(const queue<T>&y) { 
		Reset(); mcapadef = y.mcapadef; mheat = 0; mheatdef = y.mheatdef; 
		if (!y.isempty()) {
			v = new T[y.mcapacity]; mcapacity = y.mcapacity; for (int i = y.mhead; i < y.mend; i++)
				v[i%mcapacity] = y.v[i%mcapacity]; mhead = y.mhead; mend = y.mend; 
		} 
	}
};
/*======================================================================   双向循环链表（已被skiplist代替）   ======================================================================*/
//双向循环链表 (含有key)
template<class T, typename K>
class LIST {
public:
	struct N {
		K key; T data;
		N*next = NULL, *prev = NULL;
	};
private:
	//数据
	struct N *m_head = NULL;
	int m_size = 0;
public:
	//信息
	bool isempty() { if (m_size)return 0; return 1; };
	int size() { return m_size; };
	N*head() { return m_head; };
	void sethead(N*newhead) {
		if (m_head == NULL) {
			m_size = 1;
			newhead->next = newhead;
			newhead->prev = newhead;
		};
		m_head = newhead;
	};
	//增查删
	void insert(N *px, N *ppre = NULL) {
		//首节点
		if (ppre == NULL) {
			m_head = px;
			m_head->prev = m_head;
			m_head->next = m_head;
		}
		//常规
		else {
			N *pnex = ppre->next;
			px->prev = ppre; ppre->next = px;
			px->next = pnex; pnex->prev = px;
		};
		m_size++;
		return;
	};
	N*search(K key) {
		if (isempty())return NULL;
		N *cur = m_head;
		for (int i = 0; i < m_size; i++) {
			if (cur->key == key)return cur;
			cur = cur->next;
		};
		return NULL;
	};
	void erase(N *px) {
		//最后一个节点
		if (m_size == 1) {
			delete m_head; m_head = NULL;
		}
		else {
			px->prev->next = px->next;
			px->next->prev = px->prev;
			if (px == m_head)m_head = px->next;
			delete px; px = NULL;
		};
		m_size--;
		return;
	};
	//构造/析构
	virtual ~LIST() {
		if (isempty())return;
		while (m_head)erase(m_head);
	};
};
/*======================================================================   优先队列（已被skiplist代替）   ======================================================================*/
//优先队列 (队列链表实现)
template<class T, typename K>
class PRIQUE {
public:
	using Q = QUEUE<T>;
	LIST<Q, int> list;
	using N = typename LIST<Q, int>::N;
	void push(T &data, int count) {
		auto push_queue = [&](N*note, T &data) {note->data.push_end(data); };
		auto push_list = [&](T &data, int key) {
			N *temp = new N;
			temp->data.push_end(data); temp->key = key;
			if (list.isempty()) { list.sethead(temp); return; };
			int size = list.size();
			N *cur = list.head();
			int i; for (i = 0; i < size; i++) {
				if (key < cur->key)break;
				cur = cur->next;
			};
			list.insert(temp, cur->prev);
			if (i == 0 && cur == list.head())list.sethead(temp);
		};

		N*s = list.search(count);
		if (s)push_queue(s, data);
		else push_list(data, count);
	};
	bool isempty() {
		if (list.isempty())return 1; return 0;
	};
	//请使用isempty()提前检查
	T pop() {
		T temp;
		Q&q = list.head()->data;
		temp = q.head(); q.pop_head();
		if (q.isempty())list.erase(list.head());
		return temp;
	};
};
/*======================================================================   点与点阵基类   ======================================================================*/
struct P { int i, j; bool operator==(const P&y) { if (y.i == i&&y.j == j)return 1; return 0; } };
template<class T>
struct square {
	int m = 0, n = 0; T**v = NULL;
	void New(int im, int in) { m = im; n = in; v = new T*[m]; for (int i = 0; i < m; i++)v[i] = new T[n]; }
	void Del() { for (int i = 0; i < m; i++)delete[]v[i]; delete[]v; v = NULL; m = 0; n = 0; }
	~square() { if (v != NULL)Del(); };
	template<class F, class ...Ft>void For_each(F f, Ft ...args) { for (int i = 0; i < m; i++)for (int j = 0; j < n; j++)f(v[i][j], args...); }
	template<class F, class ...Ft>void For_each_ij(F f, Ft ...args) { for (int i = 0; i < m; i++)for (int j = 0; j < n; j++)f(i, j, v[i][j], args...); }
	void Reset(const T&valuedefault) { For_each([&](T &v) {v = valuedefault; }); }
	//题目不会给出找不到起点或找不到终点的情况
	void find(const T&valuetarget, P&f) { For_each_ij([&](int i, int j, T&v) {if (v == valuetarget) { f = { i,j }; return 1; } return 0; }); }
	bool isinrect(const P&p) { int i = p.i, j = p.j; if (i < 0 || i >= m || j < 0 || j >= n)return 0; return 1; }
	//仅支持相同大小的两个结构进行赋值运算
	void operator=(const square&y) { if (v == NULL)New(y.m, y.n); For_each_ij([&](int i, int j, T&v) {v = y.v[i][j]; }); }
};
/*======================================================================   end   ======================================================================*/
