template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    while (data[i] < data[data.parent(i)]) {
        swap(&data[i], &data[data.parent(i)])
        i = data.parent(i);
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    int l = left(i);
    int r = right(i);
    int small = i;

    if (l < data.size() && data[l] < data[small]) {
        small = l;
    } else if (r < data.size() && data[r] < data[small]) {
        small = r;
    }

    if (small != i) { // base case
        swap(&data[i], &data[small]);
        data.siftDown(small);
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    int i = data.size() - 1; // i is the final index
    data[i] = value;

    while (data[i] < data.parent(i)) {
        data.siftUp(i);
    }
}

template <typename T>
T MinHeap<T>::removeRoot() {
    T rootValue;
    // TODO: Implement removing the root element.
    swap(&data[0], &data[data.size()-1]);
    data.pop_back();
    siftDown(data(0));

    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property
    siftUp(index);
    siftDown(index);
}
