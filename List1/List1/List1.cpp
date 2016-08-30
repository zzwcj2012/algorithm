#include <iostream>
using namespace  std;

#define  INITSIZE  100 //��ʼ����С
#define  INCREMENT  10  //������С

template<typename T>
class Sqlist
{
public:
	void Init(); //��ʼ��
	void Destory(); //����
	void Clear(); //���
	bool IsEmpty(); //�Ƿ�Ϊ��
	int GetLen(); //��ȡ����
	int LocateElem(T t); //��ȡλ��
	T  Prior(T t); //����tǰ���Ԫ��
	T  Next(T t); //����t�����Ԫ��
	void Insert(int i, T t); // �ڵ�i��λ�ò���Ԫ��
	void Delete(int i); //ɾ����i��λ�õ�Ԫ��
	void Dis(); //���
	void Union(Sqlist<T> sq, Sqlist<T>& ret); //���������ı�����Ǳ�����һ��˳����У�Ҳ��������֮��������

	void Sort(); //����
	T GetElem(int i); //��������Ϊi��Ԫ��
private:
	T* elem; //����ָ��
	int len; //��ǰ����


};

////////////////////ʵ��////////////////////////


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
	cout << "˳�����:" << sq.GetLen() << endl;
	sq.Dis();

	sq.Delete(3);
	cout << "˳�����:" << sq.GetLen() << endl;
	cout << "ɾ������Ϊ3��Ԫ��˳���Ϊ:";
	sq.Dis();
	cout << "���������Ա�Ϊ:";
	sq.Sort();
	sq.Dis();

	Sqlist<int> sq1;
	sq1.Init();
	sq1.Insert(0, 3);
	sq1.Insert(1, 5);
	sq1.Insert(2, 1);
	sq1.Insert(3, 13);
	sq1.Sort();
	cout << "Ҫ�ϲ��ı�Ϊ:";
	sq1.Dis();
	cout << "�ϲ���ĵ�����Ϊ:";
	Sqlist<int> ret;
	sq.Union(sq1, ret);
	ret.Dis();
	return 0;
}