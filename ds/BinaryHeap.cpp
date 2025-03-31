#include <iostream>
#include <vector>

using namespace std;

class BinaryHeap
{
protected:
    vector<int> heap; // storage for the heap
    bool isMinHeap;   // true if Min-Heap else Max-Heap
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int p = parent(index);
            if ((isMinHeap && heap[index] < heap[p]) ||
                (!isMinHeap && heap[index] > heap[p]))
            {
                std::swap(heap[index], heap[p]);
                index = p;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        int size = heap.size();
        while (true)
        {
            int left = leftChild(index);
            int right = rightChild(index);
            int smallestOrLargest = index;

            if (left < size && (isMinHeap && heap[left] < heap[smallestOrLargest]) || (!isMinHeap && heap[left] > heap[smallestOrLargest]))
            {
                smallestOrLargest = index;
            }
            if (right < size && (isMinHeap && heap[right] < heap[smallestOrLargest]) || (!isMinHeap && heap[right] > heap[smallestOrLargest]))
            {
                smallestOrLargest = right;
            }

            if (smallestOrLargest != index)
            {
                swap(heap[index], heap[smallestOrLargest]);
                index = smallestOrLargest;
            }
            else
            {
                break;
            }
        }
    }

public:
    BinaryHeap(bool minHeap = true)
    {
    }
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int peek() const
    {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        return heap[0];
    }

    int extractTop()
    {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return top;
    }

    void display()
    {
        for (int num : heap)
            cout << num << " ";
        cout << endl;
    }
};

int main()
{
    BinaryHeap minHeap(true);
    minHeap.insert(3);
    minHeap.insert(25);
    minHeap.insert(5);
    minHeap.insert(20);
    minHeap.display();

    // for(int i = 0; i < 10; i++) {
    //     cout << "i: " << i << " root: " << (i-1)/2 << endl;
    // }

    return 0;
}