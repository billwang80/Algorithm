#ifndef LAB1_POLYNOMIAL1_H
#define LAB1_POLYNOMIAL1_H

#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Polynomial
{
    public:
        Polynomial(int A[], int size);
        Polynomial();
        Polynomial(string fileName);
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
