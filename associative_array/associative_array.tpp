// associative_array.tpp

template<typename S, typename I>
associative_array<S, I>::associative_array() = default;

template<typename S, typename I>
I& associative_array<S, I>::operator[](const S &key) {
    for(auto &p : vec) {
        if(p.name == key) {
            return p.mat;
        }
    }
    vec.emplace_back(key, I{});
    return vec.back().mat;
}

template<typename S, typename I>
const I& associative_array<S, I>::operator[](const S &key) const {
    for(auto &p : vec) {
        if(p.name == key) {
            return p.mat;
        }
    }
    throw std::out_of_range("Key not found");
}

