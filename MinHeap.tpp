template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    while (i > 0 && data[i] < data[parent(i)]) {
        swap(data[i], data[parent(i)])
        i = parent(i);
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
    }
    
    if (r < data.size() && data[r] < data[small]) {
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

    data.push_back(value);
    siftUp(data.size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    T rootValue;
    // TODO: Implement removing the root element.
    rootValue = data[0];
    data[0] = data.back();
    data.pop_back();
    siftDown(0);

    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    if (index == size() - 1){
        data.pop_back();
        return;
    }

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property
    siftUp(index);
    siftDown(index);
}
