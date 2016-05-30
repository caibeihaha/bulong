#include <iostream>
#include<vector>
#include<string>
using namespace std;
//class BitMap
//{
//private:
//	vector<size_t>_a;
//	size_t _size;
//public:
//	BitMap(size_t n)
//		:_size(0)
//	{
//		_a.resize((n >> 5) + 1);
//	}
//	void Set( size_t x)
//	{
//		size_t index = x >> 5;
//		size_t num = x % 32;
//		_a[index] = _a[index] | (1 << num);
//	}
//	void Reset(size_t x)
//	{
//		size_t index = x >> 5;
//		size_t num = x % 32;
//		_a[index] = _a[index] &(~ (1 << num));
//	}
//	bool Test( size_t x)
//	{
//		size_t index = x >> 5;
//		size_t num = x % 32;
//		if ((_a[index] & (1 << num) == 1))
//		{
//			return true;
//		}
//		return false;
//	}
//};
//template<class K=string>
//struct _HashFunc1
//{
//	size_t &operator()( string s)
//	{
//		int hash = 0;
//		for (int i = 0; i < s.size(); i++)
//		{
//			hash += s[i] - '0';
//		}
//		return hash;
//	}
//};
//template <class K=string>
//struct _HashFunc2
//{
//	size_t &operator()( string s)
//	{
//		int hash = strlen(s);
//		return hash;
//	}
//};
//template<class K = string,class HashFunc = _HashFunc1<string>>
//class BloomFilter
//{
//private:
//	size_t _capacity;
//	BitMap _bm;
//public:
//	BloomFilter(size_t n)
//		:_capacity(n)
//		,_bm(n)
//	{}
//	size_t _HashFunc(K key)
//	{
//		HashFunc hashfunc;
//		return hashfunc(key);
//	}
//	void  Setb(K x)
//	{		
//		size_t hash1 = _HashFunc(x);
//		size_t hash2 = _HashFunc<_HashFunc2>(x);
//		_bm.Set(hash1%_capacity);
//		_bm.Set(hash2%_capacity);
//	}
//	bool Testb( K x)
//	{
//		size_t hash1 = _HashFunc(x);
//		size_t hash2 = _HashFunc<_HashFunc2>(x);
//		if (!_bm.Test(hash1%_capacity))
//		{
//			retur false;
//		}
//		if (!_bm.Test(hash2%_capacity))
//		{
//			retur false;
//		}
//		return true;
//	}
//};
//void test()
//{
//	BloomFilter<string> b(100);
//	b.Setb("vbn");
//	int ret = b.Testb("vbn");
//	if (ret > 0)
//	{
//		printf("y");
//	}
//	else
//	{
//		printf("n");
//	}
//}
//int main()
//{
//	test();
//	getchar();
//	return 0;
//}
//

//void InsertSort(int *a, int n)
//{
//	if (a == NULL || n <= 0)
//	{
//		return;
//	}
//	int *ptr = NULL;
//	for (int i = 0; i < n-1; i++)
//	{
//		ptr = a + i;
//		int tmp = *(ptr + 1);
//		while (*ptr>tmp)
//		{
//			if (ptr == a)
//			{
//				*(ptr + 1) = *ptr;
//				*ptr = tmp;
//			}
//			else
//			{
//				*(ptr + 1) = *ptr;
//				ptr--;
//			}
//		}
//		if (*ptr < tmp)
//		{
//			*(ptr + 1) = tmp;
//		}
//	}
//}
//void test()
//{
//	int a[] = { 2, 3, 0, 1, 5, 7 };
//	InsertSort(a, 6);
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	
//}
//int main()
//{
//	test();
//	getchar();
//	return 0;
//}
template<class K>
class FindSame
{
private:
	vector<K> _a;
	vector<K> _b;
public:
	FindSame(size_t n)
	{
		_a.resize(n >> 5 + 1);
		_b.resize(n >> 5 + 1);
	}
	void HashFunca(int key)
	{
		int index = key / 1024;
		int num = key % 1024;
		_a[index] = _a[index] | (1 << num);
	}
	void HashFuncb(int key)
	{
		int index = key / 1024;
		int num = key % 1024;
		_b[index] = _b[index] | (1 << num);
	}
	size_t Test()
	{
		int hash = 0;
		for (int i = 0; i < _a.size(); i++)
		{
			int index = i;
			int count = _a[index] & _b[index];
			while (count != 0)
			{
				hash++;
				count = count&(count - 1);
			}
		}
		return hash;
	}
};
void test()
{
	FindSame<int> f(100000);
	f.HashFunca(2);
	f.HashFunca(3);
	f.HashFuncb(2);
	f.HashFuncb(3);
	cout << f.Test();
}
int main()
{
	test();
	getchar();
	return 0;
}


