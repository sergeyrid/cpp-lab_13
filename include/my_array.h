#include <stdexcept>

namespace lab_13 {

template<typename T, std::size_t N>
class my_array {
public:
    T &at(std::size_t index) {
        check_index(index);
        return _data[index];
    }
    const T &at(std::size_t index) const {
        check_index(index);
        return _data[index];
    }
    const T &operator[](std::size_t index) const {
        return _data[index];
    }
    T &operator[](std::size_t index) {
        return _data[index];
    }

    bool empty() const noexcept {
        return N == 0;
    }
    int size() const noexcept {
        return N;
    }

    void fill(T value) {
        for (std::size_t i = 0; i < N; ++i) {
            _data[i] = value;
        }
    }

private:
    T _data[N]{};

    static void check_index(std::size_t index) {
        if (index >= N) {
            throw std::out_of_range("Array index out of bounds");
        }
    }
};


template<std::size_t N>
class my_array<bool, N> {
public:
    class bool_reference {
    public:
        explicit bool_reference(std::size_t index, uint8_t *data): _index(index), _data(data) { }

        operator bool() const {
            return *_data & (1 << _index);
        }

        bool_reference &operator=(bool value) {
            *_data |= 1 << _index;
            if (!value) {
                *_data ^= 1 << _index;
            }
            return *this;
        }
        bool_reference &operator=(const bool_reference &other) {
            if (this != &other) {
                *this = bool(other);
            }
            return *this;
        }

    private:
        std::size_t _index;
        uint8_t *_data;
    };

    bool at(std::size_t index) const {
        check_index(index);
        return operator[](index);
    }
    bool_reference at(std::size_t index) {
        check_index(index);
        return operator[](index);
    }
    bool operator[](std::size_t index) const {
        return _data[index / byte] & (1 << (index % byte));
    }
    bool_reference operator[](std::size_t index) {
        return bool_reference(index % byte, &_data[index / byte]);
    }

    bool empty() const noexcept {
        return N == 0;
    }
    int size() const noexcept {
        return N;
    }

    void fill(bool value) {
        for (std::size_t i = 0; i < N; ++i) {
            operator[](i) = value;
        }
    }

private:
    static const std::size_t byte = 8;
    uint8_t _data[(N + byte - 1) / byte]{};

    static void check_index(std::size_t index) {
        if (index >= N) {
            throw std::out_of_range("Array index out of bounds");
        }
    }
};

}