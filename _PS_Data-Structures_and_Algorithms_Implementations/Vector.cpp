template<typename T>
class Vector {
private:
    T *arr;
    int size{};
    int current_size{};

public:
    Vector() {
        this->size = 10;
        this->current_size = 0;
        this->arr = new T[this->size];
    }

    explicit Vector(int _size) {
        this->size = _size;
        this->current_size = 0;
        this->arr = new T[this->size];
    }

    Vector(int _size, T filler) {
        this->size = _size;
        this->current_size = _size;
        this->arr = new T[this->size];
        fill(this->arr, this->arr + this->size, filler);
    }

    void push_back(T elem) {
        if (this->current_size == this->size) {
            int new_size = this->size * 2;
            T *newArr = new T[new_size];

            for (int i = 0; i < this->size; ++i)
                newArr[i] = this->arr[i];

            delete[] this->arr;
            this->arr = newArr;
            this->size = new_size;
        }
        this->arr[this->current_size] = elem;
        this->current_size++;
    }

    void print() {
        for (int i = 0; i < this->current_size; ++i)
            cout << this->arr[i] << ' ';
        cout << '\n';
    }

    T &operator[](int index) {
        if (index < 0 || index >= this->current_size) {
            throw std::out_of_range("Index out of range");
        }
        return this->arr[index];
    }

    T *begin() {
        return this->arr;
    }

    T *end() {
        return this->arr + this->current_size;
    }

    ~Vector() {
        delete[] this->arr;
    }
};