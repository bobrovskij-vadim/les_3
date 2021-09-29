#include <iostream>
#include <list>
#include <vector>


//1. Написать функцию, добавляющую в конец списка вещественных чисел элемент, значение которого равно среднему арифметическому всех его элементов.
//2. Создать класс, представляющий матрицу.Реализовать в нем метод, вычисляющий определитель матрицы.
//3. Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться по диапазону целых чисел в цикле for - range - based.

void my_list_push_back(std::list<int>& my_list)
{
    int sum = 0;
    for (auto i : my_list)
    {
        sum += i;
    }
    my_list.push_back(sum/my_list.size());
}

class Matrix
{
private:
    std::vector <std::vector<int>> arr;

public:
    Matrix()
    {
        for (int i = 0; i < 3; ++i)
        {
            std::vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                temp.push_back(rand() % 100);
            }
            arr.push_back(temp);
        }
    }

    int det_of_matrix()
    {
        int det = (arr[0][0] * (arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1])) - 
                  (arr[0][1] * (arr[1][0] * arr[2][2] - arr[0][2] * arr[1][2])) +
                  (arr[0][2] * (arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0]));
        return det;
    }

    void print_matrix()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                std::cout << arr[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }


    ~Matrix()
    {

    }

};


template<typename T, int size>
class MyIterator
{
private:
    T* data;
    int indx;
public:
    MyIterator() {
        data = new T[size];
        indx = -1;
    }
    ~MyIterator() {
        delete[]data;
    }
    void addData(T newVal) {
        data[++indx] = newVal;
    }

    T* begin() {
        return &data[0];
    }
    T* end() {
        return  &data[size];
    }
};
/*
class MyIterator
{
private:
    T* m_ptr;

public:
    MyIterator(T* ptr):m_ptr(ptr) {}

    ~MyIterator()
    {
        delete m_ptr;
    }

    T& operator*()
    {
        return *m_ptr;
    }

};
*/

int main()
{

    //-----------Ex_1-----------
    {
        std::cout << "-----------Ex_1-----------" << std::endl;

        std::list<int> my_list;
        for (int i = 0; i < 10; ++i)
        {
            my_list.push_back(rand() % 100);
        }

        for (auto i : my_list)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        my_list_push_back(my_list);

        for (auto i : my_list)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    //-----------Ex_2-----------
    {
        std::cout << "\n-----------Ex_2-----------" << std::endl;
        Matrix matrix;
        matrix.print_matrix();
        std::cout << matrix.det_of_matrix() << std::endl;
    }
    //-----------Ex_3-----------
    {
        std::cout << "\n-----------Ex_3-----------" << std::endl;

        MyIterator<int, 10> arr_3;
        arr_3.addData(20);
        arr_3.addData(50);
        arr_3.addData(50);
        for (auto i : arr_3) {
            std::cout << i << std::endl;
        }



      
    }

    return 0;
}
