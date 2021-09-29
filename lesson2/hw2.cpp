#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

/* ***************************************** Задание 1 *****************************************
 * Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает местами
 * значения, на которые указывают эти указатели
 * *********************************************************************************************/
template<typename T>
T Swap(T *p1, T *p2){

  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;

return 0;
}

/* ***************************************** Задание 2 *****************************************
 * Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей и сортирует 
 * указатели по значениям, на которые они указывают
 * *********************************************************************************************/

class Date{

public:
int day, month, year;

Date(int d = 0, int m = 0, int y = 0): day(d), month(m), year(y)
{}

~Date()
{}
};

template<typename S>
void SortPointers(std::vector<S*> &vec){

std::sort(begin(vec), end(vec), [vec](S* left, S* right){
  return left->day < right->day;
});
}

void printArray(std::vector<Date*> &vec){

for(const auto &it : vec){

  if(it->day < 10){
    std::cout << "0" << it->day << "."; 
  }else{
    std::cout << it->day << ".";
  }

  if(it->month < 10){
    std::cout << "0" << it->month << ".";
  }else{
    std::cout << it->month << ".";
  }

  std::cout << it->year << std::endl;
}

}

/* ***************************************** Задание 3 *****************************************
 * Подсчитайте количество гласных букв в книге “Война и мир”. Для подсчета используйте 4 
 * способа: count_if и find, count_if и цикл for, цикл for и find, 2 цикла for
 * *********************************************************************************************/

void counterLetters(std::string &str){

  std::string letters = "aAeEiIoOuUyY";

auto counter = std::count_if(str.begin(), str.end(), [&letters](char &ch){

if(letters.find(ch) != std::string::npos){
  return true;
}else{
  return false;
}
});

std::cout << "count_if + find: " << counter << std::endl;

//count_if и цикл for
counter = 0;
counter = std::count_if(str.begin(), str.end(), [&letters](char &ch){

for(const auto &it : letters){
  if(it == ch) return true;
}

return false;
});

std::cout << "count_if + for: " << counter << std::endl;

//цикл for и find
counter = 0;

for(const auto &it : str){
  if(letters.find(it) != std::string::npos){
    counter++;
  }
}

std::cout << "for + find: " << counter << std::endl;

//2 цикла for
counter = 0;

for(const auto &it : str){
  for(const auto &let : letters){
    if(it == let)
        counter++;
  }
}

std::cout << "2 for: " << counter << std::endl;
}

int main()
{
// 1
int p1 = 10;
int p2 = 20;

std::cout << "------------- Swap -------------" << std::endl;

std::cout << "p1 = " << p1 << ", " << "p2 = " << p2 << ";" << std::endl;
  Swap(&p1, &p2);
std::cout << "p1 = " << p1 << ", " << "p2 = " << p2 << ";" << std::endl;
std::cout << std::endl;

//2
Date *dt;
std::vector<Date*> v;
int count = 0;

for(int i = 0; i < 10; ++i){
  dt = new Date;
  dt->day = rand() % 30;
  dt->month = rand() % 12;
  dt->year = 2021;
  v.push_back(dt);
}

std::cout << "------------- Unsorted Array -------------" << std::endl;
  printArray(v);
std::cout << std::endl;

SortPointers(v);

std::cout << "------------- Sorting By Day -------------" << std::endl;
  printArray(v);
std::cout << std::endl;

v.clear();

//3
std::ifstream file("C:/War and peace.txt");
  if (!file.is_open()) {
		std::cout << "File not found!";
		return 0;
	}

std::string str = "";
std::stringstream ss;
  ss << file.rdbuf();
file.close();

str = ss.str();

std::cout << "------------- Letter Counter -------------" << std::endl;

counterLetters(str);


return 0;
}