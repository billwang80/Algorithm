#ifndef LAB1_POLYNOMIAL1_H
#define LAB1_POLYNOMIAL1_H

#include <cstdlib>
#include <sys/types.h> //gets the sleep function
#include <cmath>
#include "Polynomial.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

class Polynomial
{
    public:
        Polynomial(int A[], int size);
        Polynomial();
        Polynomial(ifstream & file);
        void print();
        bool operator==(const Polynomial& target)const;
        Polynomial operator+(const Polynomial& target)const;
        Polynomial operator-(const Polynomial& target)const;
        Polynomial operator*(const Polynomial& target)const;
        Polynomial derivative();

    private:
        vector<int> data;

    friend class PolynomialTest;
};

#endif // LAB1_POLYNOMIAL1_H
