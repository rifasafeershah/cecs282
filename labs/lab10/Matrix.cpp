//Rifa Safeer Shah
//CECS 282 LAB 10
//Matrix.cpp

#include "cecs282lab10Matrix.h"
//#include "Assert.h"
 
Matrix::Matrix(int rSize, int cSize)
{
  ptr = new int *[rSize];
  for(int i = 0; i < rSize; i++)
	{
    ptr[i] = new int[cSize];
  }
  rowSize = rSize;
  colSize = cSize;
}
//Copy constructor m2(m1)

//m2(m1)
Matrix::Matrix(const Matrix &m)
{
  rowSize = m.rowSize;
  colSize = m.colSize;
  ptr = new int *[m.rowSize];
  for(int i = 0; i < m.rowSize; i++)
	{
    ptr[i] = new int[m.colSize];
  }
  for(int i = 0; i < m.rowSize; i++)
	{
    for(int j = 0; j < m.colSize; j++)
	  {
      ptr[i][j] = m.ptr[i][j];
    }
  }
}
//Overloading assignment operator
 
// m2 = m1;
Matrix& Matrix:: operator =(const Matrix &m)
{
  rowSize = m.rowSize;
  colSize = m.colSize;
  for(int i = 0; i < m.rowSize; i++)
	{
    for(int j = 0; j < m.colSize; j++)
		{
      ptr[i][j] = m.ptr[i][j];
    }
  }
  return *this;
}
//Destructor

Matrix::~Matrix()
{
  for(int i = 0; i < rowSize; i++)
	{
    delete[] ptr[i];
  }
  delete[] ptr;
}

//m3 = m1 + m2
Matrix Matrix::operator +(Matrix &m)
{
  Matrix result = *this;
	//YOUR CODE  
	for(int i = 0; i < rowSize; i++)
  {
    for(int j = 0; j < colSize; j++)
    {
    	result.ptr[i][j] = this->ptr[i][j] + m.ptr[i][j];
    }
	}
	return result;   
}

//m3 = m1 * m2
Matrix Matrix::operator *(Matrix &m)
{
  Matrix *result = new Matrix(rowSize, colSize);
  for (int i = 0; i < rowSize; i++) 
	{
    for (int j = 0; j < m.colSize; j++) 
		{
      int num = 0;
      for (int k = 0; k < colSize; k++) 
			{
        num += this->ptr[i][k] * m.ptr[k][j];
      }
      result->ptr[i][j] = num;
    }
  }
  return *result;
}

//m2 = ++m1
Matrix Matrix::operator ++()
{
	//YOUR CODE
	for(int i = 0; i < rowSize; i++)
	{
		for(int j = 0; j < colSize; j++)
		{
			this->ptr[i][j] += 1;
		}
	}
  return *this;
}

//m2 = integer value + m1
Matrix operator +(const int &num, const Matrix &m)
{
  //YOUR CODE
  Matrix result(m.rowSize, m.colSize);
  for(int i = 0; i < m.rowSize; i++)
  {
    for(int j = 0; j < m.colSize; j++)
		{
			result.ptr[i][j] = m.ptr[i][j] + num;
		}
	}
  return result; 
}
 
//m2 += m1
Matrix Matrix::operator +=(Matrix &m)
{
    //YOUR CODE
	for(int i = 0; i < m.rowSize; i++)
	{
		for(int j = 0; j < m.colSize; j++)
		{
			this->ptr[i][j] += m.ptr[i][j];
		}
	} 
  return *this;
}
 
//m2 += 2
Matrix Matrix::operator +=(const int &num)
{
  for(int i = 0; i < rowSize; i++)
	{
    for(int j = 0; j < colSize; j++)
		{
      ptr[i][j] += num;
    }
  }
  return *this;
}

//cin >> m1
istream &operator >> (istream &in, const Matrix &m)
{
  //YOUR CODE
  for(int i = 0; i < m.rowSize; i++)
  {
    for (int j = 0; j < m.colSize; j++)
    {
    	cin >> m.ptr[i][j];
	  }
  }
  return in;
}

//cout << m1
ostream &operator << (ostream &os, const Matrix &m)
{
  for(int i = 0; i < m.rowSize; i++)
  {
    for(int j = 0; j < m.colSize; j++)
    {
      cout << m.ptr[i][j] << " ";
    }
    cout << "\n";
  }
  return os;
}

//Get row size
int Matrix::getRowSize()
{
	return rowSize;
}

//Get column size
int Matrix::getColumnSize()
{
	return colSize;
}
