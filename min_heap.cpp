#include<iostream>
#include<vector>

template<typename T>
class Heap {
private:
    std::vector<T> heap;

    static int left(int parent) {
        return parent * 2 + 1;
    }

    static int right(int parent) {
        return parent * 2 + 2;
    }

    static int parent(int child) {
        return (child - 1) / 2;
    }

    void heapifyup(int idx) {
        if (idx == 0) return;
        if (heap[parent(idx)] > heap[idx]) {
            std::swap(heap[idx], heap[parent(idx)]);
            heapifyup(parent(idx));
        }
        return;
    }

    void heapifydown(int idx) {
        int min_idx = idx;
        int left_child = left(idx);
        int right_child = right(idx);
        if (left_child < heap.size() && heap[left_child] < heap[min_idx]) {
            min_idx = left_child;
        }
        if (right_child < heap.size() && heap[right_child] < heap[min_idx]) {
            min_idx = right_child;
        }
        if (min_idx != idx) {
            std::swap(heap[idx], heap[min_idx]);
            heapifydown(min_idx);
        }
        return;
    }

public:
    Heap() = default;

    void push(T element) {
        heap.push_back(element);
        heapifyup(heap.size() - 1);
    }

    void pop() {
        if (heap.size() == 0) return;
        T last_element = heap.back();
        heap[0] = last_element;
        heap.pop_back();
        heapifydown(0);
    }

    T top() {
        if (heap.size() == 0) return -1;
        return heap[0];
    }

    size_t size() {
        return heap.size();
    }

    void display() {
        std::cout << "Heap: ";
        auto it = heap.begin();
        while (it != heap.end()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }
};

int main() {
    std::cout << "Heap" << std::endl;
    Heap<int> heap;
    while (true) {
        std::cout << "------------------" << std::endl;
        std::cout << "Operations on Heap" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "1.Insert Element" << std::endl;
        std::cout << "2.Delete Minimum Element" << std::endl;
        std::cout << "3.Extract Minimum Element" << std::endl;
        std::cout << "4.Print Heap" << std::endl;
        std::cout << "5.Exit" << std::endl;
        int choice, element;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter the element to be inserted: ";
                std::cin >> element;
                heap.push(element);
                break;
            case 2:
                heap.pop();
                break;
            case 3:
                std::cout << "Minimum Element: ";
                if (heap.top() == -1) {
                    std::cout << "Heap is Empty" << std::endl;
                } else
                    std::cout << "Minimum Element:  " << heap.top() << std::endl;
                break;
            case 4:
                std::cout << "Displaying elements of ";
                heap.display();
                break;
            case 5:
                exit(1);
            default:
                std::cout << "Enter Correct Choice" << std::endl;
        }
    }
}
