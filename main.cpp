#include <iostream>

void rmMtx(int** mtx, size_t rows)
{
    for (size_t i = 0; i < rows; ++i)
    {
        delete[] mtx[i];
    }
    delete[] mtx;
}

int** makeMtx(size_t rows, size_t cols)
{
    int** res = new int* [rows]();
    try
    {
        for (size_t i = 0; i < rows; ++i)
        {
            res[i] = new int[cols];
        }
    }
    catch (const std::bad_alloc&)
    {
        rmMtx(res, rows);
        throw;
    }
    return res;
}

int** transpose(int** mtx, size_t m, size_t n)
{
    int** res = makeMtx(n, m);
    for (size_t i = 0; i < m; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            res[j][i] = mtx[i][j];
        }
    }
    return res;
}

void printMtx(int** mtx, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; ++i)
    {
        if (i > 0)
        {
            std::cout << '\n';
        }
        std::cout << mtx[i][0];
        for (size_t j = 1; j < cols; ++j)
        {
            std::cout << '_' << mtx[i][j];
        }
    }
}

int main()
{
    size_t m = 0;
    size_t n = 0;
    std::cin >> m >> n;
    if (!std::cin || m == 0 || n == 0)
    {
        std::cerr << "Error: wrong matrix size\n";
        return 1;
    }

    int** mtx = nullptr;
    try
    {
        mtx = makeMtx(m, n);
    }
    catch (const std::bad_alloc&)
    {
        std::cerr << "Error: not enough memory\n";
        return 2;
    }

    for (size_t i = 0; i < m * n; ++i)
    {
        std::cin >> mtx[i / n][i % n];
    }
    if (!std::cin)
    {
        rmMtx(mtx, m);
        std::cerr << "Error: wrong matrix data\n";
        return 1;
    }

    int** res = nullptr;
    try
    {
        res = transpose(mtx, m, n);
    }
    catch (const std::bad_alloc&)
    {
        rmMtx(mtx, m);
        std::cerr << "Error: not enough memory\n";
        return 2;
    }
    rmMtx(mtx, m);

    printMtx(res, n, m);
    std::cout << '\n';
    rmMtx(res, n);
    return 0;
}
