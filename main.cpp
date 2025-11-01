#include <iostream>
#include <cstddef>

void destroy(int ** mtx, size_t created)
{
  for (size_t i = 0; i < created; i++)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int ** create(size_t rows, size_t cols)
{
  int ** mtx = new int * [rows];
  size_t created = 0;
  try
  {
    for (; created < rows; ++created)
    {
      mtx[created] = new int[cols];
    }
  }
  catch (const std::bad_alloc & e)
  {
    destroy(mtx, created);
    throw;
  }
  return mtx;
}

void construct(int ** mtx, int init, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      mtx[i][j] = init;
    }
  }
}

void input(int ** mtx, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      std::cin >> mtx[i][j];
    }
  }
}

void output(int ** mtx, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    std::cout << mtx[i][0];
    for (size_t j = 1; j < cols; ++j)
    {
      std::cout << ' ' << mtx[i][j];
    }
    std::cout << '\n';
  }
}

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows)
{
  size_t posit = 0;
  int ** mtx = new int * [rows];
  try
  {
    for (size_t i = 0; i < rows; ++i)
    {
      mtx[i] = new int[lns[i]];
      for (size_t j = 0; j < lns[i]; ++j)
      {
        mtx[i][j] = t[posit];
        ++posit;
      }
    }
  }
  catch(const std::bad_alloc & e)
  {
    destroy(mtx, posit);
    throw;
  }
  return mtx;
}

int main()
{
  // CLASSWORK
  // size_t r = 0, c = 0;
  // std::cin >> r >> c;
  // if (!std::cin)
  // {
  //   std::cerr << "bad input\n";
  //   return 1;
  // }

  // int ** matrix = nullptr;
  // try
  // {
  //   matrix = create(r, c);
  // }
  // catch (const std::exception & e)
  // {
  //   destroy (matrix, r);
  //   std::cerr << e.what() << "\n";
  //   return 1;
  // }

  // std::cout << "created\n";
  // std::cout << "matrix elements:\n";
  // input(matrix, r, c);

  // if (!std::cin)
  // {
  //   destroy (matrix, r);
  //   std::cerr << "bad input\n";
  //   return 1;
  // }

  // std::cout << "output:\n";
  // output(matrix, r, c);
  // destroy(matrix, r);


  // HOMEWORK
  int t[] = {5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 8};
  size_t lns[] = {4, 2, 5, 1};
  size_t n = 12;
  size_t rows = 4;

  int ** mtx = convert(t, n, lns, rows);
  for (size_t i = 0; i < rows; ++i) 
  {
    for (size_t j = 0; j < lns[i]; ++j) 
    {
      std::cout << mtx[i][j] << ' ';
    }
    std::cout << '\n';
  }
  destroy(mtx, rows);
}
