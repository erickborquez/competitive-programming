#include <ctime>
#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 2e5;

void insert_numbers(long long x)
{
  clock_t begin = clock();
  unordered_map<long long, int> numbers;

  for (int i = 1; i <= N; i++)
    numbers[i * x] = i;

  long long sum = 0;

  for (auto &entry : numbers)
    sum += (entry.first / x) * entry.second;

  printf("x = %lld: %.3lf seconds, sum = %lld\n", x, (double)(clock() - begin) / CLOCKS_PER_SEC, sum);
}

int main()
{
  insert_numbers(107897);
  insert_numbers(126271);
}