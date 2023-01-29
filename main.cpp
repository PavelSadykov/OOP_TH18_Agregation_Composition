//
//  main.cpp
//  ООП ДЗ 18 Агрегация и Композиция
//
//  Created by Павел on 29.01.2023.
//

#include <iostream>
#include <string>
//Для правильного выбора  использования Агрегации или Композиции надо смотреть на структуру системы :
//Как система  функционирует? Из каких функциональных звеньев она состоит и где они должны быть расположены, чтобы все работало.

//1)Агрегация. Класс Кредит - он может использоваться в разных субъектах (предприятиях)
class Credit{
public:
    std::string getСurrency(){
        return _currency;
    }
private:
    std::string _currency = "USD";
};
//Например завод кредитуется в валюте USD
class Factory{
public:
    void Currency_Of_Credit(){
        std::cout<<"Завод кредитуется в валюте :"<<_currency.getСurrency()<<std::endl;
    }
private:
    Credit _currency;
};

//2)Композиция. Класс Уставной Капитал - он принадлежит конкретному субъекту(предприятию - Company) и без него субъекта не будет. При этом Company может также и кредитоваться (класс Credit) - это уже  агрегация.
class Company{
public:
    void Turnover() {
        _capital.Turnover();
    }
    void inspectCurrency(){
        std::cout<<"Компания кредитуется в валюте :"<<_currency.getСurrency()<<std::endl;
    }
private:
    // Класс капитал  - он неотделим от Company
    class Capital{
    public:
        void Turnover(){
            std::cout<<"Уставной капитал Компании в обороте"<<std::endl;
    }
    };
        Credit _currency;
        Capital _capital;
};

int main(int argc, const char * argv[]) {
    Company company;
    company.Turnover();
    company.inspectCurrency();
    Factory factory;
    factory.Currency_Of_Credit();
    
    
    
    return 0;
}
