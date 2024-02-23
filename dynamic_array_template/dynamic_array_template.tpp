// dynamic_array_template.tpp

template<typename T>
dynamic_array<T>::dynamic_array() : len(0), data(nullptr) {}

template<typename T>
dynamic_array<T>::dynamic_array(int n) : len(n), data(new T[n]) {}

template<typename T>
dynamic_array<T>::dynamic_array(const dynamic_array<T>& other) : len(other.len), data(new T[other.len]) {
    for(int i = 0; i < len; i++) {
        data[i] = other.data[i];
    }
}

template<typename T>
dynamic_array<T>& dynamic_array<T>::operator=(const dynamic_array<T>& other) {
    if(this != &other) {
        delete[] data;
        len = other.len;
        data = new T[len];
        for(int i = 0; i < len; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
dynamic_array<T>::dynamic_array(dynamic_array<T>&& other) noexcept : len(other.len), data(other.data) {
    other.len = 0;
    other.data = nullptr;
}

template<typename T>
dynamic_array<T>& dynamic_array<T>::operator=(dynamic_array<T>&& other) noexcept {
    if(this != &other) {
        delete[] data;
        len = other.len;
        data = other.data;
        other.len = 0;
        other.data = nullptr;
    }
    return *this;
}

template<typename T>
dynamic_array<T>::~dynamic_array() {
    delete[] data;
}

template<typename T>
void dynamic_array<T>::append(T value) {
    T* new_data = new T[len + 1];
    for(int i = 0; i < len; i++) {
        new_data[i] = data[i];
    }
    new_data[len] = value;
    len++;
    delete[] data;
    data = new_data;
}

template<typename T>
int dynamic_array<T>::size() const {
    return len;
}

template<typename T>
T& dynamic_array<T>::operator[](int i) const {
    assert(i >= 0 && i < len);
    return data[i];
}

