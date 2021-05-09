#pragma once"

/*
 * CSxxxxxx
 * ^^
 * 76
 * color == 0 means red
 * state == 0 means inactive
 */

class color_and_state {
    unsigned char data = 0;
    static constexpr unsigned char get_cleaner = 1;
    static constexpr unsigned char color_bit = 128;//10000000
    static constexpr unsigned char state_bit = 64; //01000000

public:
    void set_active() {
        data |= state_bit;
    }
    void set_inactive() {
        data &= color_bit;
    }
    [[nodiscard]] bool active() const {
        return (data >> 6) & get_cleaner;
    }
    [[nodiscard]] bool inactive() const {
        return !active();
    }

    void set_black() {
        data |= color_bit;
    }
    void set_red() {
        data &= state_bit;
    }
    [[nodiscard]] bool black() const {
        return (data >> 7) & get_cleaner;
    }
    [[nodiscard]] bool red() const {
        return !black();
    }
};
