#include <iostream>

int main()
{
    int rows;
    int colns;
    std::cin >> rows >> colns;

    int** arr = new int* [rows];

    for (size_t i = 0; i < rows; ++i)
    {
        arr[i] = new int[colns];
    }

    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < colns; ++j)
        {
            arr[i][j] = rand() % 10;
        }
    }

    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < colns; ++j)
        {
            std::cout << arr[i][j] << '\t';
        }
        std::cout << '\n';
    }
}
