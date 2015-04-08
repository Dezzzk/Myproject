
#include "iset.h"

template <class T> class Myset : public ISet<T>
{
private:

	int razmer, kolvo;
	T* arr;

private:

	void uvel()
	{
		T* temp;

		temp = new T[razmer * 2];
		for (int i = 0; i < razmer; i++)
		{
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
		razmer *= 2;
	}

public:

	Myset()
	{
		razmer = 10;
		kolvo = 0;
		arr = new T[razmer];
	}
	~Myset()
	{
		delete[]arr;
	}

	Myset(const Myset<T>& copir)
	{
		kolvo = copir.kolvo;
		razmer = kolvo * 2 + 10;
		arr = new T[razmer];

		for (int i = 0; i < kolvo; i++)
		{
			arr[i] = copir.arr[i];
		}
	}

	Myset<T>& operator = (const Myset<T>& copir)
	{
		delete[]arr;
		kolvo = copir.kolvo;
		razmer = kolvo * 2 + 10;
		arr = new T[razmer];

		for (int i = 0; i < kolvo; i++)
		{
			arr[i] = copir.arr[i];
		}
		return *this;
	}

	// добавить элемент
	void add(const T& elem) // O(N)
	{
		int left = 0;
		int right = kolvo - 1;
		int mid;
		
		
		while (right >= left)
		{
			mid = (left + right) / 2;

			if (elem == arr[mid]) throw "elem dublecate";
			if (elem > arr[mid]) left = mid + 1;
			else right = mid - 1;
		}
		
		if (kolvo == 0)
		{
			arr[0] = elem;
			kolvo++;
			return;
		}
		if (kolvo == razmer)
		{
			uvel();
		}
		for (int i = kolvo; i > mid; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[mid + 1] = elem;
		kolvo++;
	}
	// удалить элемент
	void remove(const T& elem) // O(N)
	{
		int left = 0;
		int right = kolvo - 1;
		int mid;


		while (right >= left)
		{
			mid = (left + right) / 2;

			if (elem == arr[mid])
			{
				for (int i = mid; i < kolvo - 1; i++)
				{
					arr[i] = arr[i + 1];
				}
				--kolvo;
				return;
			}
			if (elem > arr[mid]) left = mid + 1;
			else right = mid - 1;
		}
		throw "not found";
	}
	// содержится ли элемент
	bool contains(const T& elem) const // O(log(N))
	{
	
		int left = 0;
		int right = kolvo - 1;
		int mid;


		while (right >= left)
		{
			mid = (left + right) / 2;

			if (elem == arr[mid]) return true;
			if (elem > arr[mid]) left = mid + 1;
			else right = mid - 1;
		}
		return false;
	}
	// узнать размер множества
	int size() const //O(1)
	{
		return kolvo;
	}
};

