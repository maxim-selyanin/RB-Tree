#pragma once

#include "color_and_state.h"
#include "common.h"

template <std::size_t capacity, typename value_t, typename key_t = int, typename dummy = integral<key_t> >
class rb_tree {
    struct {
        key_t key;
        value_t value;
        color_and_state is_black;
    } data[capacity];
    static constexpr std::size_t max = std::numeric_limits<std::size_t>::max();

    static bool is_null(std::size_t number) { return number >= capacity;}
    static bool not_null(std::size_t number) { return number < capacity;}
    static std::size_t null() { return capacity;}
    static bool has_parent(std::size_t number);

    static std::size_t parent(std::size_t number);
    static std::size_t left_child(std::size_t number);
    static std::size_t right_child(std::size_t number);

public:
    rb_tree() = default;

    void insert(key_t, value_t);
    value_t remove(key_t);
    value_t find(key_t) const;

    [[nodiscard]] bool empty() const;
    [[nodiscard]] std::size_t size() const;

    template <typename ret_t>
    void level_traverse(std::function<ret_t (value_t)>);

    template <typename ret_t>
    void order_traverse(std::function<ret_t (value_t)>);

    ~rb_tree() = default;
};

template<std::size_t capacity, typename value_t, typename key_t, typename dummy>
std::size_t rb_tree<capacity, value_t, key_t, dummy>::parent(std::size_t number) {
    if (is_null(number) || number == 0) {
        return null();
    }

    --number;
    return number / 2;
}

template<std::size_t capacity, typename value_t, typename key_t, typename dummy>//2n + 1
std::size_t rb_tree<capacity, value_t, key_t, dummy>::left_child(std::size_t number) {
    if (is_null(number)) {
        return null();
    }

    std::size_t that_max = max - 1;
    that_max = that_max / 2;
    if (number > that_max) {
        return null();
    }

    return number*2 + 1;
}

template<std::size_t capacity, typename value_t, typename key_t, typename dummy>//2n + 2
std::size_t rb_tree<capacity, value_t, key_t, dummy>::right_child(std::size_t number) {
    if (is_null(number)) {
        return null();
    }

    std::size_t that_max = max - 2;
    that_max = that_max / 2;
    if (number > that_max) {
        return null();
    }

    return number*2 + 2;
}

template<std::size_t capacity, typename value_t, typename key_t, typename dummy>
bool rb_tree<capacity, value_t, key_t, dummy>::has_parent(std::size_t number) {
    return not_null(number) && number;
}

template<std::size_t capacity, typename value_t, typename key_t, typename dummy>
template<typename ret_t>
void rb_tree<capacity, value_t, key_t, dummy>::level_traverse(std::function<ret_t(value_t)> callback) {
    //
}
