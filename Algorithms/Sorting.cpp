/*
 * Sorting — merge sort, quick sort, heap sort; std::sort note in Sorting.md
 */

#include <iostream>
#include <vector>
#include <algorithm>

static void merge(std::vector<int>& a, int l, int mid, int r, std::vector<int>& buf) {
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) buf[k++] = a[i++];
        else buf[k++] = a[j++];
    }
    while (i <= mid) buf[k++] = a[i++];
    while (j <= r) buf[k++] = a[j++];
    for (int t = l; t <= r; t++) a[t] = buf[t];
}

void mergeSort(std::vector<int>& a, int l, int r, std::vector<int>& buf) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid, buf);
    mergeSort(a, mid + 1, r, buf);
    merge(a, l, mid, r, buf);
}

void mergeSort(std::vector<int>& a) {
    if (a.empty()) return;
    std::vector<int> buf(a.size());
    mergeSort(a, 0, static_cast<int>(a.size()) - 1, buf);
}

static int partition(std::vector<int>& a, int l, int r) {
    int pivot = a[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) std::swap(a[i++], a[j]);
    }
    std::swap(a[i], a[r]);
    return i;
}

void quickSort(std::vector<int>& a, int l, int r) {
    if (l >= r) return;
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

void quickSort(std::vector<int>& a) {
    if (a.empty()) return;
    quickSort(a, 0, static_cast<int>(a.size()) - 1);
}

static void siftDown(std::vector<int>& heap, int i, int n) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && heap[left] > heap[largest]) largest = left;
        if (right < n && heap[right] > heap[largest]) largest = right;
        if (largest == i) break;
        std::swap(heap[i], heap[largest]);
        i = largest;
    }
}

void heapSort(std::vector<int>& a) {
    int n = static_cast<int>(a.size());
    for (int i = n / 2 - 1; i >= 0; i--) siftDown(a, i, n);
    for (int end = n - 1; end > 0; end--) {
        std::swap(a[0], a[end]);
        siftDown(a, 0, end);
    }
}

static void printVec(const std::vector<int>& v) {
    for (int x : v) std::cout << x << ' ';
    std::cout << '\n';
}

int main() {
    std::vector<int> m{5, 2, 8, 1, 9, 3};
    mergeSort(m);
    std::cout << "mergeSort: ";
    printVec(m);

    std::vector<int> q{5, 2, 8, 1, 9, 3};
    quickSort(q);
    std::cout << "quickSort: ";
    printVec(q);

    std::vector<int> h{5, 2, 8, 1, 9, 3};
    heapSort(h);
    std::cout << "heapSort: ";
    printVec(h);

    std::vector<int> s{5, 2, 8, 1, 9, 3};
    std::sort(s.begin(), s.end());
    std::cout << "std::sort: ";
    printVec(s);
    return 0;
}
