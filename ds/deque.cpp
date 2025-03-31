#include <iostream>

using namespace std;

class Deque {
private:
    static const int BLOCK_SIZE = 2; // Each block holds 2 elements
    static const int INITIAL_CAPACITY = 4; // Number of blocks initially

    int** blocks; // Pointer array to store multiple blocks
    int frontIndex, backIndex;
    int frontBlock, backBlock;
    int size, capacity;

public:
    Deque() {
        capacity = INITIAL_CAPACITY;
        blocks = new int*[capacity];
        for (int i = 0; i < capacity; i++)
            blocks[i] = new int[BLOCK_SIZE]; // Allocate fixed-size blocks

        frontBlock = backBlock = capacity / 2; // Start in the middle
        frontIndex = backIndex = 0;
        size = 0;
    }

    void push_front(int val) {
        if (frontIndex == 0) { // Need new block
            if (frontBlock == 0) expandCapacity();
            frontBlock--;
            frontIndex = BLOCK_SIZE;
        }
        blocks[frontBlock][--frontIndex] = val;
        size++;
    }

    void push_back(int val) {
        if (backIndex == BLOCK_SIZE) { // Need new block
            if (backBlock == capacity - 1) expandCapacity();
            backBlock++;
            backIndex = 0;
        }
        blocks[backBlock][backIndex++] = val;
        size++;
    }

    void pop_front() {
        if (size == 0) return;
        frontIndex++;
        if (frontIndex == BLOCK_SIZE) { // Move to next block
            frontBlock++;
            frontIndex = 0;
        }
        size--;
    }

    void pop_back() {
        if (size == 0) return;
        if (backIndex == 0) { // Move to previous block
            backBlock--;
            backIndex = BLOCK_SIZE;
        }
        backIndex--;
        size--;
    }

    int getFront() {
        return blocks[frontBlock][frontIndex];
    }

    int getBack() {
        return blocks[backBlock][backIndex - 1];
    }

    int getSize() { return size; }

    void expandCapacity() {
        int newCapacity = capacity * 2;
        int** newBlocks = new int*[newCapacity];

        for (int i = 0; i < newCapacity; i++)
            newBlocks[i] = new int[BLOCK_SIZE];

        int start = (newCapacity - capacity) / 2;
        for (int i = 0; i < capacity; i++)
            newBlocks[start + i] = blocks[i];

        delete[] blocks;
        blocks = newBlocks;
        frontBlock += start;
        backBlock += start;
        capacity = newCapacity;
    }

    void display() {
        // cout << "**blocks: " << **blocks << endl;
        // cout << "*blocks: " << *blocks << endl; // pointer 2 val: which is the array index value
        cout << "blocks: " << blocks << endl; // pointer 2 pointer
        for(int i=0; i<capacity; i++) {
            cout << "blocks[" << i << "]: " << blocks[i] << " ";
            cout << "blocks[" << i <<"]: "; 
            for(int j=0; j<BLOCK_SIZE; j++) {
                cout << blocks[i][j] << " ";
            }
            cout << endl;
        }

    }
};

int main() {
    Deque dq;
    dq.push_front(10);
    dq.push_front(11);
    dq.push_front(12);
    dq.push_front(13);
    dq.push_front(14);

    dq.push_back(20);
    dq.push_back(40);
    dq.push_front(5);
    dq.display();
    // std::cout << "Front: " << dq.getFront() << ", Back: " << dq.getBack() << std::endl; // Output: Front: 5, Back: 20

    // dq.pop_front();
    // std::cout << "Front after pop: " << dq.getFront() << std::endl; // Output: 10

    return 0;
}
