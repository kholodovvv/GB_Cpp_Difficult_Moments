#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>
#include <cmath>
#include <iterator>

/* ***************************************** Задание 1 **************************************************
 * Имеется отсортированный массив целых чисел. Необходимо разработать функцию insert_sorted,
 * которая принимает вектор и новое число и вставляет новое число в определенную позицию
 * в векторе, чтобы упорядоченность контейнера сохранялась. Реализуйте шаблонную функцию 
 * insert_sorted, которая сможет аналогично работать с любым контейнером, содержащим любой тип значения.
 * *****************************************************************************************************/

template<typename T, typename S>

void insert_sorted(T& cont, S& num, size_t pos) {

	S tmp;

if((cont.size() / 2) < pos){

	cont.push_back(num);

for (auto it = cont.end() - 1; it > cont.begin() + pos; --it) {
  std::swap(*it, *(it - 1));
}

}else{
  auto it = cont.begin() + pos;
  cont.insert(it, num);
}

}

/* ***************************************** Задание 2 **************************************************
 * Сгенерируйте вектор, состоящий из 100 вещественный чисел, представляющий собой значения аналогового
 * сигнала. На основе этого массива чисел создайте другой вектор целых чисел, представляющий цифровой
 * сигнал, в котором будут откинуты дробные части чисел. Выведите получившиеся массивы чисел. 
 * Посчитайте ошибку, которой обладает цифровой сигнал по сравнению с аналоговым.
 * *****************************************************************************************************/





int main()
{
//1
	std::vector<int> v(10);
	int number = 3;
	
	std::generate(v.begin(), v.end(), []() {return rand() % 10; });
	std::sort(v.begin(), v.end(), [&](int &first, int &second) {
		return (first < second);
		});

std::cout << "------------- VECTOR BEFORE INSERTION -------------" << std::endl;

	for (auto it : v){
		std::cout << it << ' ';
	}

insert_sorted<std::vector<int>>(v, number, 3);

std::cout << "------------- VECTOR AFTER INSERTION -------------" << std::endl;

	for (auto it : v){
		std::cout << it << ' ';
	}

	std::deque<float> dq(6);
	std::generate(dq.begin(), dq.end(), []() {return rand() % 10; });

	std::sort(dq.begin(), dq.end(), [&](float& first, float& second) {
		return (first < second);
		});

std::cout << "------------- DEQUE BEFORE INSERTION -------------" << std::endl;

	for (auto it : dq){
		std::cout << it << ' ';
	}

	insert_sorted<std::deque<float>>(dq, number, 4);

std::cout << "------------- DEQUE AFTER INSERTION -------------" << std::endl;

	for (auto it : dq){
		std::cout << it << ' ';
	}

std::cout << std::endl;

//2
srand(time(0));

std::vector<float> analog(100);
std::vector<int> digital;
std::vector<float> result;

	std::generate(analog.begin(), analog.end(), []() {return (float)(rand()%20001)/100-100; });

//Откидываем целую часть от дробной и записываем в вектор digital
std::transform(analog.begin(), analog.end(), back_inserter(digital), [&result](float i){
  result.push_back(pow(std::round(i) - i, 2));
  return std::round(i);
});

std::cout << "------------- THE VALUE OF THE ANALOG SIGNAL -------------" << std::endl;

copy(analog.begin(), analog.end(), std::ostream_iterator<float>{std::cout, ", "});

std::cout << "------------- THE VALUE OF THE DIGITAL SIGNAL -------------" << std::endl;

copy(digital.begin(), digital.end(), std::ostream_iterator<int>{std::cout, ", "});

std::cout << "------------- SIGNAL DIFFERENCE -------------" << std::endl;

copy(result.begin(), result.end(), std::ostream_iterator<float>{std::cout, ", "});

  return 0;
}