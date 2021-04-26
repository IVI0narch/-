#include<vector>
#include<chrono>
#include<random>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<fstream>

using namespace std;
using namespace std::chrono;

constexpr int max_value = 100000;

//символ "&" позволяет менять непосредственно ту переменную, которая передана в функцию
//как питоновский объект
//это замена указателя в современном c++
void bubble_sort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j){
            if (v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}

void insert_sort(vector<int>& v) {
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0; --j){
            if (v[j-1] < v[j]) {
                break;
            }
        swap(v[j], v[j-1]);
        }
    }
}

static void merge(vector<int>& buf, size_t left, size_t right, size_t middle)
{
    if (left >= right || middle < left || middle > right) return;
    if (right == left + 1 && buf[left] > buf[right]) {
        swap(buf[left], buf[right]);
        return;
    }

    vector<int> tmp(&buf[left], &buf[right] + 1);

    for (size_t i = left, j = 0, k = middle - left + 1; i <= right; ++i) {
        if (j > middle - left) {
            buf[i] = tmp[k++];
        } else if(k > right - left) {
            buf[i] = tmp[j++];
        } else {
            buf[i] = (tmp[j] < tmp[k]) ? tmp[j++] : tmp[k++];
        }
    }
}

void MergeSort(vector<int>& buf, size_t left, size_t right)
{

    //! Условие выхода из рекурсии
    if(left >= right) return;

    size_t middle = left + (right - left) / 2;

    //! Рекурсивная сортировка полученных массивов
    MergeSort(buf, left, middle);
    MergeSort(buf, middle + 1, right);
    merge(buf, left, right, middle);
}

void merge_sort(vector<int>& v) {
    size_t left = 0;
    size_t right = v.size() - 1;
    MergeSort(v, left, right);
}

void std_sort(vector<int>& v) {
    std::sort(v.begin(), v.end());
}

int Partition(std::vector<int>& arr, int low, int high) {
  int pivot = arr[high];
  int i = low;
  for (int j = low; j < high; ++j) {
    if (arr[j] < pivot) {
      std::swap(arr[i++], arr[j]);
    }
  }
  std::swap(arr[i], arr[high]);
  return i;
}

void QSortInternal(std::vector<int>& arr, int low, int high) {
  if (low < high) {
    int pos = Partition(arr, low, high);
    QSortInternal(arr, low, pos - 1);
    QSortInternal(arr, pos + 1, high);
  }
}

void qSort(std::vector<int>& v) {
  int len = v.size();
  if (len <= 1) return;
  QSortInternal(v, 0, len -  1);
}

void StupidSort(vector<int>& v){
    int i = 0, tmp, n;
    n = v.size();
    while (i < n - 1)
    {
        if (v[i+1] < v[i])
        {
            tmp = v[i];
            v[i] = v[i+1];
            v[i+1] = tmp;
            i = 0;
        }
        else i++;
    }
}

vector<int> generate_random_vector(uint64_t n) {

    vector<int> ret(n);

    //это математически строгий и надежный способ генерировать случайные числа
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, max_value);

    for (int i = 0; i < n; ++i) {
        ret[i] = dist(gen);
    }

    return ret;
}


//это магическая строчка
//благодаря этому функция может принимать аргумент произвольного типа
//название для конкретно этого типа вы придумываете сами (я назвал его SortFunction)
template<typename SortFunction>
int benchmark(SortFunction f, uint64_t n) {

    auto v = generate_random_vector(n);

    auto start = steady_clock::now();
    //время засекается внутри этого блока
    f(v);
    auto finish = steady_clock::now();

    //это проверка на то, верно ли проведена сортировка
    //в случае ошибки программа падает с сообщением "assertion failed"
    assert(is_sorted(begin(v), end(v)));

    //возвращаем время работы в мс
    return duration_cast<milliseconds>(finish - start).count();
}

int main() {
    double time = 0;
    ofstream fout("stupid_sort.csv", ios_base::out);
    //fout << "iteration,time\n";

    for (int i = 1; i < 100; ++i){
        fout << 100*i << "," << (0 + benchmark(StupidSort, 100*i)) << "\n";
    }
    fout.close(); // закрываем файл
    time = 0;

    return 0;
}
