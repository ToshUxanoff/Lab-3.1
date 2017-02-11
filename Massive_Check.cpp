//Вариант 6, Лаба 3

#include "stdafx.h"
#include "iostream"

class Vector
{
private:
	double *mas;
	int elements; //Отвечает за размер массива. Не знаю почему изначально не назвал просто "Size"
public:
	Vector()
	{
		this->elements = 0;
		this->mas = nullptr;
	}
	Vector(double* mas_src, int n)
	{
		this->elements = n;
		this->mas = new double[n];
		for (int i = 0; i < n; i++)
		{
			this->mas[i] = mas_src[i];
			std::cout << mas_src[i] << ' ';
		}
	}
	~Vector()
	{
		delete[] this->mas;
	}
	double operator[](size_t position)
	{
		if (position > this->elements|| position == 0)
		{
			std::cout << "\nwrong position" << std::endl;
			return -1;
		}
		else
		{
			return this->mas[position-1]; //-1 т.к. обычно человек считает массив с 1 элемента, а не с 0. Возможно тупо, но редко кто-то говорит "нулевой" а не "первый" элемент
		}
	}
	double * operator=(const Vector& object)
	{
		delete[] this->mas;
		this->elements = object.elements;
		this->mas = new double[object.elements];
		for (int i = 0; i < object.elements; i++)
		{
			this->mas[i] = object.mas[i];
			std::cout << object.mas[i] << ' ';
		}
		return this->mas;
	}
	double * operator+(const Vector& object)  //Как и в первой лабе, студия не хочет брать на перегруз оператора + два аргумента. Не знаю в чем проблема. Сложение все равно реализовал
	{
		if (object.elements > this->elements)
		{
			std::cout << "Error!" << std::endl;
			return 0;
		}
		else
		{
		for (int i = 0; i < this->elements; i++)
			{
				this->mas[i] = this->mas[i] + object.mas[i];
				std::cout << this->mas[i] << ' ';
			}
		}
		return this->mas;
	}	
};


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
#pragma region Инициализация 2 - х массивов для 2 - х объектов для последующего заполнения через конструктор.Не интересно ведь ?
	int n = 5;
	double* mas_src = new double[n];
	for (int i = 0; i < n; i++)
	{
		mas_src[i] = rand() % 100;		
	}
	double* mas_src2 = new double[n];
	for (int i = 0; i < n; i++)
	{
		mas_src2[i] = rand() % 50;
	}
#pragma endregion
	Vector mas1(mas_src, n);
	std::cout << '\n';//ctor test
	Vector mas2(mas_src2, n);
	std::cout << '\n' << mas1[3] << std::endl;		//operator [] test
	std::cout << "TEST:\n"; //operator = test; mas1 = mas 2, вывод mas1
	mas1 = mas2;
	std::cout << '\n';
	std::cout << "т.к. Mas 1 = Mas 2, то операция + применяется сама к себе. Вы можете закомментировать строку 'mas1 = mas2', тогда увидите сложение разных массивов." << std::endl;
	mas1 + mas2;
	system("pause");
	return 0;
}

