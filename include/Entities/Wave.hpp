#ifndef WAVE_HPP_
#define WAVE_HPP_

#pragma once

namespace Entities {

    class Wave {
    private:
        int time_current_;
        int time_max_;
        int number_;

    public:
        // Конструктор
        Wave(int time_max, int number);

        // Методы изменения состояния
        void set_time(int new_time);
        void set_number(int new_number);

        // Методы получения состояния
        int time() const;
        int end_time() const;
        int number() const;
    };

} // namespace Entities

#endif // WAVE_HPP_
