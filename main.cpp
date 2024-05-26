#include "log_duration.h"

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

vector<int> ReverseVector(const vector<int>& source_vector) {
    vector<int> res;

    for (int i : source_vector) {
        res.insert(res.begin(), i);
    }

    return res;
}

vector<int> ReverseVector2(const vector<int>& source_vector) {
    vector<int> res;

    // будем проходить source_vector задом наперёд
    // с помощью обратного итератора
    for (auto iterator = source_vector.rbegin(); iterator != source_vector.rend(); ++iterator) {
        res.push_back(*iterator);
    }

    return res;
}

vector<int> ReverseVector3(const vector<int>& source_vector) {
    return { source_vector.rbegin(), source_vector.rend() };
}

//моя реализация перестановки вектора через итераторы без использования метода push_back()
vector<int> ReverseVector4(const vector<int>& source_vector) {
    vector<int> res(source_vector.size());

    auto source_rbegin = source_vector.rbegin();    
    for (auto res_iter = res.begin(); res_iter != res.end(); ++res_iter, ++source_rbegin) {
        *res_iter = *source_rbegin;
    }

    return res;    
}

void Operate() {    
    vector<int> rand_vector;
    int n;

    cin >> n;
    rand_vector.reserve(n);

    for (int i = 0; i < n; ++i) {
        rand_vector.push_back(rand());
    }
    
    vector<int> reversed_vector;
    if (n <= 100000) {        
        {
            LOG_DURATION("Naive"s);
            // перевернём вектор задом наперёд      
            reversed_vector = ReverseVector(rand_vector);
        }

        {
            LOG_DURATION("Good"s);
            // перевернём вектор задом наперёд      
            reversed_vector = ReverseVector2(rand_vector);
        }
    }
    else {
        {
            LOG_DURATION("Good"s);
            // перевернём вектор задом наперёд      
            reversed_vector = ReverseVector2(rand_vector);
        }
        {
            LOG_DURATION("Best"s);
            // перевернём вектор задом наперёд      
            reversed_vector = ReverseVector3(rand_vector);
        }
        {
            LOG_DURATION("My_one"s);
            // перевернём вектор задом наперёд      
            reversed_vector = ReverseVector4(rand_vector);
        }
    }                
}

int main() {
    Operate();
    return 0;
}

/*
Напишите программу, которая будет сравнивать четыре реализации реверсирования вектора :
наивную(Naive), со вставками в начало;
хорошую(Good), со вставками в конец;
отличную(Best), с инициализацией двумя итераторами;
вашу(Your) : она изначально создаёт вектор из нужного числа элементов и заполняет его с последнего элемента.
Прочитайте из cin одно число — размер вектора.Создайте вектор такого размера, заполните его случайными числами и произведите сравнение нескольких версий реверсирования :
Если размер вектора меньше либо равен 100'000, сравните наивную и хорошую реализацию.
Если размер вектора больше 100'000, сравните хорошую с отличной и вашей.
Сравнение заключается в измерении и выводе времени работы операций.

Считайте одно целое неотрицательное число — размер входных данных.

Выведите в cerr несколько строк в формате <название версии> : <время работы> ms.
Если введённое число меньше или равно 100'000, то должны быть выведены результаты для Naive и Good.
Если введённое число от 100'001, то должны быть выведены результаты для Good, Best, Your.

наивную — ReverseVector,
хорошую — ReverseVector2,
отличную — ReverseVector3,
вашу — ReverseVector4.

Для тестирования компилируйте с оптимизацией(конфигурация Release), иначе результаты могут быть не такими, как вы ожидаете.

Три реализации реверсирования у вас уже есть, осталось разработать четвёртую и применить их все.Не измеряйте заполнение вектора случайными числами.
Не выводите в cerr напрямую : для вывода используйте макрос LOG_DURATION.
*/