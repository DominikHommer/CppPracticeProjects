// linked_list_template.tpp

template<typename T>
list<T>::node::node() = default;

template<typename T>
list<T>::node::node(const T &value) : value(value) {}

template<typename T>
list<T>::node::~node() {
    delete next;
}

template<typename T>
list<T>::list() = default;

template<typename T>
list<T>::list(const T &content) : head(new node(content)) {}

template<typename T>
list<T>::list(const list<T> &other) : head(nullptr) {
    node *run = other.head;
    while(run) {
        append(run->value);
        run = run->next;
    }
}

template<typename T>
list<T>& list<T>::operator=(const list<T> &other) {
    if(this == &other) {
        return *this;
    }
    delete head;
    head = nullptr;
    node *run = other.head;
    while(run) {
        append(run->value);
        run = run->next;
    }
    return *this;
}

template<typename T>
list<T>::list(list<T> &&other) noexcept : head(other.head) {
    other.head = nullptr;
}

template<typename T>
list<T>& list<T>::operator=(list<T> &&other) noexcept {
    delete head;
    head = other.head;
    other.head = nullptr;
    return *this;
}

template<typename T>
list<T>::~list() {
    delete head;
}

template<typename T>
void list<T>::append(T value) {
    node *tail = new node(value);
    if(!head) {
        head = tail;
    } else {
        node *run = head;
        while(run->next) {
            run = run->next;
        }
        run->next = tail;
    }
}

template<typename T>
void list<T>::add_list(const list<T> &to_add) {
    node *run = to_add.head;
    while(run) {
        append(run->value);
        run = run->next;
    }
}

template<typename T>
int list<T>::size() {
    node *run = head;
    int i = 0;
    while(run) {
        i++;
        run = run->next;
    }
    return i;
}

template<typename T>
T& list<T>::value_at(int index) {
    assert(index > 0 && index <= size());
    index--;
    node *run = head;
    if(index == 0) {
        return run->value;
    }
    int i = 1;
    while(i <= index) {
        i++;
        run = run->next;
    }
    return run->value;
}

