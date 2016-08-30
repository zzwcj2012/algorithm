#include <iostream>
using namespace  std;

#define  INITSIZE  100 //初始化大小
#define  INCREMENT  10  //增量大小

template<typename T>
class Sqlist
{
public:
	void Init(); //初始化
	void Destory(); //销毁
	void Clear(); //清空
	bool IsEmpty(); //是否为空
	int GetLen(); //获取长度
	int LocateElem(T t); //获取位置
	T  Prior(T t); //返回t前面的元素
	T  Next(T t); //返回t后面的元素
	void Insert(int i, T t); // 在第i个位置插入元素
	void Delete(int i); //删除第i个位置的元素
	void Dis(); //输出
	void Union(Sqlist<T> sq, Sqlist<T>& ret); //连接排序后的表，最好是保存在一个顺序表中，也可以连接之后再排序

	void Sort(); //排序
	T GetElem(int i); //返回索引为i的元素
private:
	T* elem; //数组指针
	int len; //当前长度


};

////////////////////实现////////////////////////


template<typename T> void Sqlist<T>::Init()
{

	elem = new T[INITSIZE];
	if (elem == NULL)
	{
		return;
	}

	len = 0;


}

template<typename T> void Sqlist<T>::Destory()
{
	delete[]elem;
	elem = NULL;
}

template<typename T> void Sqlist<T>::Clear()
{

	Destory();
	len = 0;
}

template<typename T> bool Sqlist<T>::IsEmpty()
{
	return len >0 ? TRUE : FALSE;
}

template <typename T> int Sqlist<T>::GetLen()
{
	return len;
}

template<typename T> int Sqlist<T>::LocateElem(T t)
{
	for (int i = 0; i <len; ++i)
	{
		if (t == elem[i])
		{
			return i;
		}
	}
	return -1;
}

template<typename T> T Sqlist<T>::Prior(T t)
{
	int i = LocateElem(t);
	if (i != -1 && i != 0)
	{
		return  elem[i - 1];
	}
}

template<typename T> T  Sqlist<T>::Next(T t)
{
	int i = LocateElem(t);
	if (i != -1 && i != len - 1)
	{
		return elem[i + 1];
	}
}

template<typename T> void  Sqlist<T>::Insert(int i, T t)
{
	if (i<0 || i > len)
	{
		return;
	}

	if (len >= INITSIZE)
	{
		delete[]elem;
		elem = NULL;
		T* temp;
		temp = new T[INITSIZE + INCREMENT];
		if (temp == NULL)
		{
			return;
		}
		elem = temp;
	}


	for (int j = len - 1; j >= i; j--)
	{
		elem[j] = elem[j + 1];
	}

	elem[i] = t;

	++len;
}

template<typename T> void Sqlist<T>::Delete(int i)
{

	if (i < 0 || i > len - 1)
	{
		return;
	}

	for (int j = i + 1; j < len; ++j)
	{
		elem[j - 1] = elem[j];
	}

	--len;
}

template<typename T> void Sqlist<T>::Dis()
{
	for (int i = 0; i <len; ++i)
		cout << elem[i] << "/t";
	cout << endl;
}

template<typename T> void  Sqlist<T>::Union(Sqlist<T> sq, Sqlist<T>& ret)
{
	int i = 0, j = 0;
	int k = 0;
	ret.Init();
	while (i < len && j < sq.GetLen())
	{
		if (elem[i] > sq.GetElem(j))
		{
			ret.Insert(k, sq.GetElem(j));
			++j, ++k;
		}
		else
		{
			ret.Insert(k, this->GetElem(i));
			++i, ++k;
		}

	}

	while (i < len)
	{
		ret.Insert(k, this->GetElem(i));
		i++;
		k++;
	}

	while (j < sq.GetLen())
	{
		ret.Insert(k, sq.GetElem(j));
		j++;
		k++;
	}





}

template<typename T> void Sqlist<T>::Sort()
{
	for (int i = 1; i < len; ++i)
	{
		for (int j = 0; j < len - i; ++j)
		{
			if (elem[j] > elem[j + 1])
			{
				T t;
				t = elem[j];
				elem[j] = elem[j + 1];
				elem[j + 1] = t;
			}
		}
	}

}

template<typename T> T Sqlist<T>::GetElem(int i)
{
	if (i < 0 || i > len)
	{
		return -1;
	}

	return elem[i];
}
int main()
{
	Sqlist<int> sq;
	sq.Init();
	sq.Insert(0, 5);
	sq.Insert(1, 6);
	sq.Insert(2, 3);
	sq.Insert(3, 13);
	sq.Insert(4, 15);
	cout << "顺序表长度:" << sq.GetLen() << endl;
	sq.Dis();

	sq.Delete(3);
	cout << "顺序表长度:" << sq.GetLen() << endl;
	cout << "删除索引为3的元素顺序表为:";
	sq.Dis();
	cout << "排序后的线性表为:";
	sq.Sort();
	sq.Dis();

	Sqlist<int> sq1;
	sq1.Init();
	sq1.Insert(0, 3);
	sq1.Insert(1, 5);
	sq1.Insert(2, 1);
	sq1.Insert(3, 13);
	sq1.Sort();
	cout << "要合并的表为:";
	sq1.Dis();
	cout << "合并后的单链表为:";
	Sqlist<int> ret;
	sq.Union(sq1, ret);
	ret.Dis();
	return 0;
}