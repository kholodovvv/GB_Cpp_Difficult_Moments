#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

/* ***************************************** Задание 1 *****************************************
 * Написать функцию, добавляющую в конец списка вещественных чисел элемент, значение которого
 * равно среднему арифметическому всех его элементов.
 * *********************************************************************************************/

void isertItemList(std::list<int> &lst){
int counterItem, sum = 0;

  for(auto it = lst.begin(); it != lst.end(); ++it){
    sum += *it;
    counterItem++;
  }

lst.insert(std::next(lst.begin(), counterItem), sum / counterItem);

}

/* ***************************************** Задание 2 **********************************************
 * Создать класс, представляющий матрицу. Реализовать в нем метод, вычисляющий определитель матрицы.
 * *************************************************************************************************/

class Matrix{
private:
size_t Size;
std::vector<double> m;

public:
Matrix(size_t s): Size(s), m(s * s)
{}

double calcDet(){
//Функция нахождения основания матриц до 3-го порядка
//Если матрица имеет строку или столбец, все элементы которого равны нулю, то ее определитель равен 0.

//Для матрицы первого порядка значение определителя равно значению элемента этой матрицы 
if(Size < 2)
  return m[0];

//Для матрицы 2×2 значение определителя равно разности произведений элементов главной и побочной диагоналей
if(Size == 2){
  return m[0]*m[3] - m[1]*m[2];
}

int counter = 0;

for(int i = 0; i < Size; ++i){
  for(int j = 0; j < Size; ++j){
    if(m[i * Size + j] == 0){
      counter++;
    }
  }
  if(counter == Size)
    return 0;
  counter = 0;
}

for(int j = 0; j < Size; ++j){
  for(int i = 0; i < Size; ++i){
    if(m[i * Size + j] == 0){
      counter++;
    }
  }
  if(counter == Size)
    return 0;
}

counter = 0;
//Если в матрице есть две одинаковых строки или два одинаковых столбца, то ее определитель равен 0.

std::vector<double> col(Size);
int iter = 0;
int iter2 = 0;
int step = 0;

for(int j = 0; j < Size; ++j){
  for(int i = 0; i < Size; ++i){
    col[i] = m[i * Size + j];
  }

iter2 = j;
step = Size * j;

  for(int it = 0; it < ((Size * Size) - (Size + step)); ++it){
    if(col[iter] == m[iter  * Size + (iter2 + 1)])
    {
      counter++;
    }
    if(iter < Size - 1){
      iter++;
    }else{
      if(counter == Size) return 0;
      iter = 0;
      iter2++;
    }
  }

}

iter = 0;
iter2 = 0;
counter = 0;

for(int i = 0; i < Size; ++i){
  for(int j = 0; j < Size; ++j){
    col[j] = m[i * Size + j];
  }

iter2 = i;
step = Size * i;

  for(int it = 0; it < ((Size * Size) - (Size + step)); ++it){
    if(col[iter] == m[(iter2 + 1)  * Size + iter])
    {
      counter++;
    }
    if(iter < Size - 1){
      iter++;
    }else{
      if(counter == Size) return 0;
      iter = 0;
      iter2++;
    }
  }

}

col.clear();

//Правило Саррюса для вычисления определителя матрицы 3-го порядка
if(Size == 3){
  return m[0]*m[Size + 1]*m[2*(Size + 1)] + m[1]*m[Size + 2]*m[Size * 2] + m[2]*m[Size]*m[(2*Size) + 1] - 
  m[2]*m[Size + 1]*m[2 * Size] - m[0]*m[Size + 2]*m[(2*Size) + 1] - m[1]*m[Size]*m[(2*Size) + 2];
}

return 0;
}

double& operator() (size_t i, size_t j) { return m[i * Size + j]; };

~Matrix(){
  m.clear();
}
};

/* ***************************************** Задание 3 **********************************************
 * Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться по 
 * диапазону целых чисел в цикле for-range-based.
 * *************************************************************************************************/
template <class T>
class array_{

size_t sz;
T* arr;

public:
class Iterator;

array_(size_t size = 1): sz(size)
{ 
  arr = new T[sz];
}

T& operator[](const int &num){
  if(num > 0 && num < sz){
    return arr[num];
  }else{
    return arr[0];
  }
    
}

Iterator begin(){
  return arr;
}

Iterator end(){
  return arr + sz;
}

class Iterator{
T* current;

public:
Iterator(T* first): current(first)
{ }

T& operator++ (int)
{
  return *current++;
}

T& operator++ ()
{
  return *++current;
}

T& operator-- (int)
{
  return *current--;
}

T& operator-- ()
{
  return *--current;
}

T& operator+ (int num){
  return *current + num;
}

T& operator- (int num){
  return *current - num;
}

T& operator* (){
  return *current;
}

bool operator!= (const Iterator &it){
  return current != it.current;
}

};


~array_()
{
  delete[] arr;
}

};

int main()
{
//1
std::list<int> ls{1, 2, 3, 4, 6, 8};

std::cout << "----------- LIST BEFORE INSERTION -----------" << std::endl;

  for(auto it = ls.begin(); it != ls.end(); ++it){
    std::cout << *it << " ";
  }

  std::cout << std::endl;

isertItemList(ls);

std::cout << "----------- LIST AFTER INSERTION -----------" << std::endl;

  for(auto it = ls.begin(); it != ls.end(); ++it){
    std::cout << *it << " ";
  }

  std::cout << std::endl;

//2
std::cout << "----------- MATRIX -----------" << std::endl;

size_t size = 3;
double dt = 0;
Matrix mx(size);

for(size_t i = 0; i < size; ++i){
  for(size_t j = 0; j < size; ++j){
    mx(i, j) = rand() % 30;
    std::cout << mx(i, j) << "  ";
  }
std::cout << std::endl;
}

  std::cout << std::endl;

dt = mx.calcDet();

std::cout << "Determinant = " << dt << std::endl;

//3

std::cout << "----------- ITERATOR -----------" << std::endl;

array_<int> ar(10);

for(auto n : ar){
  ar[n] = rand();
  std::cout << ar[n] << std::endl;
}

return 0;
}