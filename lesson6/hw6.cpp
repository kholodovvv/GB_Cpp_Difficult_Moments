#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>
#include <vector>
#include <ctime>
#include <iterator>

/* ***************************************** Задание 1 **************************************************
 * Создайте потокобезопасную оболочку для объекта cout. Назовите ее pcout. Необходимо, чтобы несколько
 * потоков могли обращаться к pcout и информация выводилась в консоль. Продемонстрируйте работу pcout.
 * *****************************************************************************************************/

std::mutex m;
std::mutex m1;
std::mutex m2;

template<typename T>
void pcout(T& inf){
std::lock_guard lg(m);
    std::cout << inf << std::endl;
}

/* ***************************************** Задание 2 **************************************************
 * Реализовать функцию, возвращающую i-ое простое число (например, миллионное простое число равно 15'485'863).
 * Вычисления реализовать во вторичном потоке. В консоли отображать прогресс вычисления.
 * *****************************************************************************************************/
bool checkNum(long n){
//Проверка числа на простоту
    for(long i = 2; i < n; ++i){
        if(n % i == 0)
            return false;
    }

if(n % n == 0)
    return true;
}


long rPrimeNumber(long num){

//Ищем следующее натуральное число от заданного и возвращаем результат
/*long i = num;
++num;
for(; i <= num; ++i){
    if(checkNum(i))
        return i;
++num;
}

return 0;*/

//Возвращаем количество натуральных чисел до входящего числа
long count = 0;
long iter = 2;
while(iter != num){
    if(checkNum(iter))
        count++;

iter++;
}

return count;
}

/* ***************************************** Задание 3 **************************************************
 * Промоделировать следующую ситуацию. Есть два человека (2 потока): хозяин и вор. Хозяин приносит домой 
 * вещи. При этом у каждой вещи есть своя ценность. Вор забирает вещи, каждый раз забирает вещь с 
 * наибольшей ценностью.
 * *****************************************************************************************************/
void addGoods(std::vector<int>& hause){
std::scoped_lock l{ m1, m2 };
srand(time(0));

for(int i = 0; i <= hause.size(); ++i){
    if(hause[i] == 0)
        hause[i] = rand() % 500;
}

}

void rob(std::vector<int>& hause){
std::scoped_lock l{ m2, m1 };
int bag = 0;
int current = 0;

    for(int i = 0; i <= hause.size(); ++i)
        if(bag < hause[i]){
            bag = hause[i];
            current = i;
        }
    hause[current] = 0;
}


int main() {
//1
int num = 10;
std::thread th1([&](){pcout("OUTPUT THREAD th1");});
std::thread th2([&](){pcout(num);});
    th1.join();
    th2.join();

std::cout << std::endl;

//2
long answer = 0;
auto result (std::async(std::launch::async, rPrimeNumber, 1'000));
auto status = result.wait_for(std::chrono::nanoseconds(1));

std::cout << "Progress ";

while(status != std::future_status::ready){

    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    status = result.wait_for(std::chrono::nanoseconds(1));
}

std::cout << "complete";
    std::cout << std::endl;
std::cout << "answer: " << result.get() << std::endl;

std::cout << std::endl;

//3
std::vector<int> goods(5);
int step = 6;

for(int i = 0; i < step; ++i){
    std::thread owner([&](){addGoods(goods);});
    std::thread thief([&](){rob(goods);});
    
owner.join();
thief.join();

std::cout << "THE OWNER BROUGHT IT HOME:" << std::endl;
    copy(goods.begin(), goods.end(), std::ostream_iterator<int>(std::cout, " "));
std::cout << std::endl;

std::cout << "THE THIEF STOLE:" << std::endl;
    copy(goods.begin(), goods.end(), std::ostream_iterator<int>(std::cout, " "));
std::cout << std::endl;

std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

    return 0;
}
