#include "iostream"

class Vector
{
private:
	double *mas;
	int size;
public:
	Vector();
	Vector(double* mas_src, int n);
	~Vector();
	double operator[](size_t position);
	double * operator=(const Vector& object);
	friend double * operator+(const Vector& a, double* b);
};
