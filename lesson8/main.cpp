#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <optional>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "gtest/gtest.h"
#include "gtest/internal/gtest-port.h"

typedef struct {
    std::string firstName, lastName;
    std::optional<std::string> patronymic;

    std::optional<std::string> Patronymic(std::string& patr) {
        if (patr == "" || patr == "-") {
            return std::nullopt;
        }

        return patr;
    }
}Person;

typedef struct {
    size_t countryCode, cityCode;
    std::string number;
    std::optional<size_t> extensionNumber;

    std::optional<std::size_t> ext(std::size_t& ex_num) {
        if (ex_num == 0) {
            return std::nullopt;
        }

        return ex_num;
    }
}PhoneNumber;

bool operator< (const Person& P1, const Person& P2) {

    return tie(P1.firstName, P1.lastName, P1.patronymic) < tie(P2.firstName, P2.lastName, P2.patronymic);
}

bool operator== (const Person& P1, const Person& P2) {

    return tie(P1.firstName, P1.lastName) == tie(P2.firstName, P2.lastName);
}

class PhoneBook {
private:
    Person p;
    PhoneNumber phone;
    std::string str;

public:
    std::vector<std::pair<Person, PhoneNumber>> book;

    PhoneBook(std::ifstream& file)
    {
        std::string patr = "";
        std::size_t ex_num = 0;

        while (!file.eof()) {

            std::getline(file, str);
            std::istringstream iss(str);

            iss >> p.firstName >> p.lastName >> patr >> phone.countryCode >> phone.cityCode >> phone.number >> ex_num;
            p.patronymic = p.Patronymic(patr);
            phone.extensionNumber = phone.ext(ex_num);

            book.push_back(std::make_pair(p, phone));

        }

    }

    friend std::ostream& operator<< (std::ostream& out, const PhoneBook& pbook) {

        for (const auto &it : pbook.book) {

            out << it.first.firstName << "\t" << it.first.lastName << "\t";

            if (it.first.patronymic.has_value()) {
                out << it.first.patronymic.value();
            }
            else {
                out << "\t";
            }

            out << "\t" << "+" << it.second.countryCode << "(" << it.second.cityCode << ")" << it.second.number << "\t";

            if (it.second.extensionNumber.has_value()) {
                out << it.second.extensionNumber.value();
            }
            else {
                out << "\t";
            }

            out << "\n";
        }

        return out;
    }

    void SortByName() {

        std::sort(book.begin(), book.end(), [](const std::pair<Person,PhoneNumber> &left, const std::pair<Person,PhoneNumber> &right)
        {return left.first < right.first;});
    }

    void SortByPhone(){

        std::sort(book.begin(), book.end(), [](std::pair<Person, PhoneNumber> p1, std::pair<Person, PhoneNumber> p2)
        {return p1.second.countryCode < p2.second.countryCode;});
    }

    std::tuple<std::string, std::string> GetPhoneNumber(std::string fName){
        int count = 0;
        std::string number = "";
        std::stringstream ss;

        for(const auto& [man, phone] : book){
            if (man.firstName == fName) {
                count++;
            }
        }

        if(count > 1){
            return std::tie("found more than 1", " ");
        }else if(count < 1){
            return std::tie("not found", " ");
        }else{
            for(const auto& [man, phone] : book){
                if (man.firstName == fName) {
                    ss << "+" << phone.countryCode << "(" << phone.cityCode << ")" << phone.number << " ";
                    ss >> number;
                    return std::tie("", number);
                }
            }
        }

        return std::tie("", "");
    }


    void ChangePhoneNumber(const Person &p, const PhoneNumber &num)
    {
        std::vector<std::pair<Person, PhoneNumber>>::iterator it;
        auto pred = [&p](const auto &item){return std::get<0>(item) == p;};

        it = std::find_if(book.begin(), book.end(), pred);

        if(it != book.end()){
            it.base()->second.countryCode = num.countryCode;
            it.base()->second.cityCode = num.cityCode;
            it.base()->second.number = num.number;
            it.base()->second.extensionNumber = num.extensionNumber;
        }

    }

    ~PhoneBook()
    {
        book.clear();
    }
};


TEST(class_PhoneBook, outFile){
    std::ifstream file("pBook.txt");
        ASSERT_NO_THROW(PhoneBook book(file));
        file.close();
}

TEST(class_PhoneBook, getNumber){
    std::ifstream file("pBook.txt");
    PhoneBook book(file);
        auto answer = book.GetPhoneNumber("Egorov");
        EXPECT_TRUE("+77(4521)8880876" ==  std::get<1>(answer));
    file.close();
}

TEST(class_PhoneBook, ChangePhoneNumber){
    std::ifstream file("pBook.txt");
    PhoneBook book(file);
    PhoneNumber Ph {7, 423, "45346458", std::nullopt};
    Person p { "Ivanov", "Ivan", "Ivanovich" };

    ASSERT_NO_THROW(book.ChangePhoneNumber(p, Ph));
    file.close();
}

int main(int argc, char *argv[])
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

