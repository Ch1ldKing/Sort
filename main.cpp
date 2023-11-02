#include <iostream>
#include <vector>
#include <cstdlib> // for std::swap

// 分区函数
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = low - 1; // i指向比基准小的最后一个元素

    for (int j = low; j < high; j++) {
        // 如果当前元素小于或等于基准
        if (arr[j] <= pivot) {
            i++; // 移动小于基准的元素的边界
            std::swap(arr[i], arr[j]); // 交换元素
        }
    }
    std::swap(arr[i + 1], arr[high]); // 将基准元素放到中间位置
    return i + 1; // 返回基准元素的最终位置
}

// 快速排序函数
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 分区索引

        quickSort(arr, low, pi - 1); // 递归排序基准左边的子数组
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> data = {10, 7, 8, 9, 1, 5};
    int n = data.size();

    quickSort(data, 0, n - 1);

    std::cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

