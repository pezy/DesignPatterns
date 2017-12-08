#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>

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
        if (vec.empty()) return;
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
        if (vec.empty()) return;
        using size = std::vector<int>::size_type;
        auto partition = [&vec](size low, size high) {
            int pivot = vec[high];
            size i = low;
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
    static void Sort(std::vector<int>& vec, const std::shared_ptr<ISortStrategy>& sorter) { sorter->Sort(vec); }
};

int main()
{
    std::vector<int> vec{};

    Sorter::Sort(vec, std::make_shared<BubbleSortStrategy>());
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    Sorter::Sort(vec, std::make_shared<QuickSortStrategy>());
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;
}
