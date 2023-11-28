#include <iostream>

template <typename T>
class MyVector {
private:
    int size_;
    int capacity_;
    T* data_;

    void newСapacity(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size_; i++) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    MyVector() : size_(0), capacity_(0), data_(nullptr) {}

    ~MyVector() {
        delete[] data_;
    }

    T& at(int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    void push_back(const T& value) {
        if (size_ >= capacity_) {
            newСapacity(capacity_ == 0 ? 1 : 2 * capacity_);
        }
        data_[size_] = value;
        size_++;
    }

    int size() const {
        return size_;
    }

    int capacity() const {
        return capacity_;
    }

    MyVector& operator=(const MyVector& second_vec) {
        if (this != &second_vec) {
            delete[] data_;

            size_ = second_vec.size_;
            capacity_ = second_vec.capacity_;

            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                data_[i] = second_vec.data_[i];
            }
        }
        return *this;
    }
};

int main() {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);


    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    try {
        std::cout << "Elements: ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i) << " ";
        }
    } catch(const std::out_of_range& ex){
        std::cout << std::endl << "ERROR: " << ex.what() << std::endl;
    }

    //operator=
    MyVector<int> vec_2 = vec;
    for (int i = 0; i < vec_2.size(); i++) {
        std::cout << vec_2.at(i) << " ";
    }
    return 0;
}