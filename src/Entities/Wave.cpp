#include "wave.hpp"

#include <stdexcept>

namespace Entities {

    Wave::Wave(int time_max, int number)
        : time_current_(0)
        , time_max_(time_max)
        , number_(number)
    {
        if (time_max <= 0)
            throw std::invalid_argument("time_max must be positive");
        if (number < 0)
            throw std::invalid_argument("number must be non-negative");
    }

    // --- Методы изменения состояния ---

    void Wave::set_time(int new_time) {
        if (new_time < 0)
            throw std::invalid_argument("time cannot be negative");
        if (new_time > time_max_)
            throw std::invalid_argument("time cannot exceed time_max");
        time_current_ = new_time;
    }

    void Wave::set_number(int new_number) {
        if (new_number < 0)
            throw std::invalid_argument("number must be non-negative");
        number_ = new_number;
    }

    // --- Методы получения состояния ---

    int Wave::time() const {
        return time_current_;
    }

    int Wave::end_time() const {
        return time_max_;
    }

    int Wave::number() const {
        return number_;
    }

} // namespace Entities
