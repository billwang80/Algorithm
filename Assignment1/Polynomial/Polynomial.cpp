// Bill Wang & Jimmy Huang
// 20778745 & 20778541

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

Polynomial::Polynomial()
{
	srand(time(0));
	int order = rand() % 1001;
	for(int index = 0; index<=order; index++)
	{
		data.push_back(rand()%2001-1000);
	}
}

Polynomial::Polynomial(int A[], int size)
{
	for(int index = 0; index<size; index++)
	{
		data.push_back(A[index]);
	}
}

Polynomial::Polynomial(ifstream & file)
{
	if(!file)
	{
		cout<<"Could not find file";
	}
	int input;
	while(file>>input)
	{
		data.push_back(input);
	}
	file.close();
}

void Polynomial::print()
{
	for(int order = data.size()-1; order>=0; order--)
	{
		if(data[order] != 0)
		{
			if(order != data.size()-1 && data[order]>0)
			{
				cout<<"+";
			}
			if(order !=0)
			{
				if(data[order] == -1)
				{
					cout<<"-";
				}
				else if(data[order != 1])
				{
					cout<<data[order];
				}
			}
			else
			{
				cout<<data[0];
			}

			if(order > 1)
			{
				cout<<"x^"<<order;
			}
			else if(order == 1)
			{
				cout<<"x";
			}
		}
	}
	cout<<endl;
}

bool Polynomial::operator==(const Polynomial& other) const
{
	if(data.size() != other.data.size())
	{
		return false;
	}

	for(int index = 0; index<data.size(); index++)
	{
		if(data[index] != other.data[index])
		{
			return false;
		}
	}
	return true;
}

Polynomial Polynomial::operator+(const Polynomial& target) const
{
    vector<int> result;

    int size1 = data.size();
    int size2 = target.data.size();
    int difference = fabs(size1 - size2);
    int largerSize = 0;
    bool isOneLarger = true;

    if(size1 > size2){
        largerSize = size1;
    }
    else{
        largerSize = size2;
        isOneLarger = false;
    }

    for(int i = 0; i < largerSize; i++)
    {
        if(i < largerSize - difference)
        {
            if(isOneLarger)
            {
                result.push_back(data[i] + target.data[i]);
            }
            else
            {
                result.push_back(data[i] + target.data[i]);
            }
        }
        else
        {
            if(isOneLarger)
                result.push_back(data[i]);
            else
                result.push_back(target.data[i]);
        }
    }
    int arr[result.size()];

    for(int count = 0; count < result.size(); count++)
    {
        arr[count] = result[count];
    }
    Polynomial poly(arr, result.size());

    return poly;
}

Polynomial Polynomial::operator-(const Polynomial& target) const
{
    vector<int> result;

    int size1 = data.size();
    int size2 = target.data.size();
    int difference = fabs(size1 - size2);
    int largerSize = 0;
    bool isOneLarger = true;

    if(size1 > size2){
        largerSize = size1;
    }
    else{
        largerSize = size2;
        isOneLarger = false;
    }

    for(int i = 0; i < largerSize; i++)
    {
        if(i < largerSize - difference)
        {
            if(isOneLarger)
                result.push_back(data[i] - target.data[i]);
            else
                result.push_back(data[i] - target.data[i]);
        }
        else
        {
            if(isOneLarger)
                result.push_back(data[i]);
            else
                result.push_back(-1*target.data[i]);
        }
    }
    int arr[result.size()];

    for(int count = 0; count < result.size(); count++)
    {
        arr[count] = result[count];
    }
    Polynomial poly(arr, result.size());

    return poly;
}

Polynomial Polynomial::operator*(const Polynomial& target) const
{
    int resultSize = data.size() + target.data.size();
    vector<int> result;

    for(int i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < target.data.size(); j++)
        {
            int degree1 = i;
            int degree2 = j;

            if(i == 0 && j == 0)
            {
                for(int count = 0; count < resultSize; count++)
                {
                    result[count] = 0;
                }
            }
            int currentResultIndex = degree1 + degree2;
            result[currentResultIndex] = result[currentResultIndex] + data[i]*target.data[j];
        }
    }

    int arr[result.size()];

    for(int count = 0; count < result.size(); count++)
    {
        arr[count] = result[count];
    }
    Polynomial poly(arr, result.size());

    return poly;
}

Polynomial Polynomial::derivative()
{
    data.erase(data.begin());
    for(int i = 0; i < data.size(); i++)
    {
        data[i] = (i+1)*data[i];
    }
    return *this;
}

