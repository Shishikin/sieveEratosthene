// sieveEratosthene.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>

#ifdef _WIN32
#include <windows.h>
#endif

void InputVector(std::vector<int>& numbers, int n)
{
    for (int i = 0; i <= n - 2; ++i)
    {
        numbers.push_back(i + 2);
    }
}

void PrintVector(const std::vector<int>& numbers)
{
    for (auto a : numbers)
    {
        std::cout << a << '\n';
    }
}

// решето Эратосфена оставляет в векторе только простые числа
void SieveEratosthene(std::vector<int>& numbers)
{
    for(int i = 0; i < numbers.size(); ++i)
    {
        int k = i + 2;
        if (numbers[i])
        {
            for (int f = (k * k) - 2; f < numbers.size(); f = f + k)
            {
                numbers[f] = 0;   // если число не простое обнулить
            }
        }
    }

    // убираем все нули из вектора
    for (int i = numbers.size() - 1; i >= 0; --i)
    {
        if (numbers[i] == 0)
        {
            numbers.erase(numbers.begin() + i); // Удаляем элемент с индексом i
        }
    }
}

bool IsStream(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i < std::ceil(sqrt(n)); ++i)
    {
        if (n % i == 0)
        {
            return false;
            break;
        }
    }
    return true;
}

bool IsNInVector(const std::vector<int>& numbers, int n)
{
    
    for (auto a : numbers)
    {
        if (a == n)
        {
            return true;
        }            
    }
    return false;
}

int main()
{
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    int n;
    std::cout << "Введите число ";    
    std::cin >> n;
    if (IsStream(n))
    {
        std::cout << "число " << n << " простое";
    }
    else
    {
        std::cout << "число " << n << " не является простым";
    }
        
//    std::vector<int> numbers;
//    InputVector(numbers, n);
//    SieveEratosthene(numbers);

 //   return IsNInVector(numbers, n);
 //   PrintVector(numbers);
 //   std::cout << "Hello World!\n";
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
