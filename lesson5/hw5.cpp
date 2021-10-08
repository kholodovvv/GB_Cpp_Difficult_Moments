#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <deque>
#include <list>
#include <sstream>
/* ***************************************** Задание 1 **************************************************
 * Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов,
 * и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза, то вывести его
 * надо один раз). Продемонстрировать работу функции, передав итераторы различных типов.
 * *****************************************************************************************************/


template<typename  T>
void uniqueWords(T itF, T itE){

    std::set<std::string> uniqW;

    for(; itF != itE; ++itF){
        uniqW.insert(*itF);
    }

    copy(uniqW.begin(), uniqW.end(), std::ostream_iterator<std::string>(std::cout, " "));

}

/* ***************************************** Задание 2 **************************************************
 * Используя ассоциативный контейнер, напишите программу, которая будет считывать данные введенные
 * пользователем из стандартного потока ввода и разбивать их на предложения.
 * Далее программа должна вывести пользователю все предложения, отсортировав их по длине.
 * *****************************************************************************************************/
template<typename  IT>
void parseWords(IT itF, IT itE){

    std::stringstream ss;
    std::multiset<std::string> mset;

    for(;itF != itE; ++itF){
        ss << *itF << " ";

        if(ss.str().find('.') != ss.str().npos){
            mset.insert(ss.str());
            ss.str("");
        }

    }

    copy(mset.begin(), mset.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}


int main() {
//1

    std::vector<std::string> words;
    std::deque<std::string> words_;
    std::list<std::string> _words;

    std::string answer;

    do{
        std::cout << "TO EXIT THE PROGRAM, ENTER END" << std::endl;
        std::cout << "ENTER THE WORD: " << std::endl;
        std::cin >> answer;

        if(answer != "END" && answer != ""){
            words.push_back(answer);
            words_.push_back(answer);
            _words.push_back(answer);
        }

    }while(answer != "END" && answer != "");

    std::cin.get();

    std::cout << "----------------- VECTOR ITERATOR -----------------" << std::endl;
    uniqueWords(words.begin(), words.end());
    std::cout << std::endl;

    std::cout << "----------------- DEQUE ITERATOR -----------------" << std::endl;
    uniqueWords(words_.begin(), words_.end());
    std::cout << std::endl;

    std::cout << "----------------- LIST ITERATOR -----------------" << std::endl;
    uniqueWords(_words.begin(), _words.end());
    std::cout << std::endl;

//2
std::stringstream st;
st <<  "mom was washing the frame. rama was washing mom. Sasha was walking along the highway. The girls were swimming in the lake.";

parseWords(std::istream_iterator<std::string>{st}, {});



    return 0;
}
