/*
 * Sorting algorithms for FAANG interviews
 */

#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int>& a, int lo, int mid, int hi) {
    std::vector<int> left(a.begin() + lo, a.begin() + mid + 1);
    std::vector<int> right(a.begin() + mid + 1, a.begin() + hi + 1);
    int i = 0, j = 0, k = lo;
    while (i < static_cast<int>(left.size()) && j < static_cast<int>(right.size())) {
        if (left[i] <= right[j]) a[k++] = left[i++];
        else a[k++] = right[j++];
    }
    while (i < static_cast<int>(left.size())) a[k++] = left[i++];
    while (j < static_cast<int>(right.size())) a[k++] = right[j++];
}

void mergeSort(std::vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;
    int mid = lo + (hi - lo) / 2;
    mergeSort(a, lo, mid);
    mergeSort(a, mid + 1, hi);
    merge(a, lo, mid, hi);
}

int partition(std::vector<int>& a, int lo, int hi) {
    int pivot = a[hi];
    int i = lo;
    for (int j = lo; j < hi; j++) {
        if (a[j] < pivot) std::swap(a[i++], a[j]);
    }
    std::swap(a[i], a[hi]);
    return i;
}

void quickSort(std::vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;
    int p = partition(a, lo, hi);
    quickSort(a, lo, p - 1);
    quickSort(a, p + 1, hi);
}

void heapify(std::vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        std::swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(std::vector<int>& a) {
    int n = static_cast<int>(a.size());
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        std::swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void print(const std::vector<int>& a) {
    for (int x : a) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> a = {5, 2, 8, 1, 9, 3};
    mergeSort(a, 0, static_cast<int>(a.size()) - 1);
    print(a);  // 1 2 3 5 8 9

    a = {5, 2, 8, 1, 9, 3};
    quickSort(a, 0, static_cast<int>(a.size()) - 1);
    print(a);

    a = {5, 2, 8, 1, 9, 3};
    heapSort(a);
    print(a);

    a = {5, 2, 8, 1, 9, 3};
    std::sort(a.begin(), a.end());
    print(a);
    return 0;
}
