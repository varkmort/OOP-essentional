// first class.cpp : 
// 
//

#include <iostream>

//ваш новый тип данных
class Type {
public://доступно всем пользователям класса
    void f00(){}//функции - члены | методы

    //пример access функций
    int var() {
        return var_;
    }
    void var(int a) {
        var_ = a;
    }
private://компоненты доступны только членам класса,
        //дружественным функциям и дружественным классам
    int var_;//переменная - член класса | полями
protected://компоненты доступны только членам класса, наследникам,
          //дружественным функциям и дружественным классам
};

//Duration
// установить время
// узнать время
// добавить время
//

class Duration {
public:
    double seconds() {
        return seconds_;
    }

    int minutes(){}

    void seconds(double time) {
        seconds_ = time;
    }

    void add(double time) {
        seconds_ += time;
    }

    void add(Duration time);

    friend Duration Summ(Duration a, Duration b);

private:
    double seconds_;
};

Duration Summ(Duration a, Duration b) {
    Duration result;
    result.seconds(a.seconds_ + b.seconds_);
    return result;
}



int main()
{
    //Type obj;
    //obj.var();
    //obj.f00();
    Duration timeA;
    timeA.seconds(15.6);
    std::cout << timeA.seconds() << '\n';
    timeA.add(2.3);
    std::cout << timeA.seconds() << '\n';
    Duration timeB;
    timeB.seconds(12.9);
    auto res{ Summ(timeA, timeB) };
    Summ(Duration(), Duration());
    std::cout << res.seconds();
    return 0;
}