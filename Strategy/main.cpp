#include <iostream>
#include <vector>
#include <algorithm>

class ISortStrategy {
public:
  virtual void Sort(std::vector<int>& vec) = 0;
};

class BubbleSortStrategy : public ISortStrategy {
public:
  void Sort(std::vector<int>& vec) override {
    std::cout << "Sorting using bubble sort" << std::endl;
    _BubbleSort(vec); 
  }
private:
  void _BubbleSort(std::vector<int>& vec) {
      using size = std::vector<int>::size_type;
      for (size i = 0; i != vec.size(); ++i)
        for (size j = 0; j != vec.size()-1; ++j)
          if (vec[j] > vec[j+1])
            std::swap(vec[j], vec[j+1]);
  }
};

class QuickSortStrategy : public ISortStrategy {
public:
  void Sort(std::vector<int>& vec) override {
    std::cout << "Sorting using quick sort" << std::endl;
    _QuickSort(vec);
  }
private:
  void _QuickSort(std::vector<int>& vec) {
    using size = std::vector<int>::size_type;
    auto partition = [&vec](size low, size high) {
      int pivot = vec[high], i = low;
      for (size j = low; j != high; ++j)
        if (vec[j] <= pivot)
          std::swap(vec[i++], vec[j]);
      std::swap(vec[i], vec[high]);
      return i;
    };

    std::function<void (size, size)> quickSort = [&](size low, size high) {
      if (low >= high) return;
      size pi = partition(low, high);
      quickSort(low, pi - 1);
      quickSort(pi + 1, high);
    };

    quickSort(0, vec.size()-1);
  }
};

class Sorter {
public:
  Sorter(ISortStrategy* sorter): sorter_(sorter) {}
  void Sort(std::vector<int>& vec) { sorter_->Sort(vec); }
private:
  ISortStrategy* sorter_;
};

int main()
{
  std::vector<int> vec{1, 5, 4, 3, 2, 8};
  
  Sorter sorter(new BubbleSortStrategy());
  sorter.Sort(vec);
  for (int i : vec) std::cout << i << " ";
  std::cout << std::endl;

  sorter = Sorter(new QuickSortStrategy());
  sorter.Sort(vec);
  for (int i : vec) std::cout << i << " ";
  std::cout << std::endl;
}
