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

    // ����� ��������� source_vector ����� ������
    // � ������� ��������� ���������
    for (auto iterator = source_vector.rbegin(); iterator != source_vector.rend(); ++iterator) {
        res.push_back(*iterator);
    }

    return res;
}

vector<int> ReverseVector3(const vector<int>& source_vector) {
    return { source_vector.rbegin(), source_vector.rend() };
}

//��� ���������� ������������ ������� ����� ��������� ��� ������������� ������ push_back()
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
            // ��������� ������ ����� ������      
            reversed_vector = ReverseVector(rand_vector);
        }

        {
            LOG_DURATION("Good"s);
            // ��������� ������ ����� ������      
            reversed_vector = ReverseVector2(rand_vector);
        }
    }
    else {
        {
            LOG_DURATION("Good"s);
            // ��������� ������ ����� ������      
            reversed_vector = ReverseVector2(rand_vector);
        }
        {
            LOG_DURATION("Best"s);
            // ��������� ������ ����� ������      
            reversed_vector = ReverseVector3(rand_vector);
        }
        {
            LOG_DURATION("My_one"s);
            // ��������� ������ ����� ������      
            reversed_vector = ReverseVector4(rand_vector);
        }
    }                
}

int main() {
    Operate();
    return 0;
}

/*
�������� ���������, ������� ����� ���������� ������ ���������� �������������� ������� :
�������(Naive), �� ��������� � ������;
�������(Good), �� ��������� � �����;
��������(Best), � �������������� ����� �����������;
����(Your) : ��� ���������� ������ ������ �� ������� ����� ��������� � ��������� ��� � ���������� ��������.
���������� �� cin ���� ����� � ������ �������.�������� ������ ������ �������, ��������� ��� ���������� ������� � ����������� ��������� ���������� ������ �������������� :
���� ������ ������� ������ ���� ����� 100'000, �������� ������� � ������� ����������.
���� ������ ������� ������ 100'000, �������� ������� � �������� � �����.
��������� ����������� � ��������� � ������ ������� ������ ��������.

�������� ���� ����� ��������������� ����� � ������ ������� ������.

�������� � cerr ��������� ����� � ������� <�������� ������> : <����� ������> ms.
���� �������� ����� ������ ��� ����� 100'000, �� ������ ���� �������� ���������� ��� Naive � Good.
���� �������� ����� �� 100'001, �� ������ ���� �������� ���������� ��� Good, Best, Your.

������� � ReverseVector,
������� � ReverseVector2,
�������� � ReverseVector3,
���� � ReverseVector4.

��� ������������ ������������ � ������������(������������ Release), ����� ���������� ����� ���� �� ������, ��� �� ��������.

��� ���������� �������������� � ��� ��� ����, �������� ����������� �������� � ��������� �� ���.�� ��������� ���������� ������� ���������� �������.
�� �������� � cerr �������� : ��� ������ ����������� ������ LOG_DURATION.
*/