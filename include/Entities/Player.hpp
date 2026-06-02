#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#pragma once

#include <utility>

namespace Entities {

    class Enemy {
    private:
        int x_;
        int y_;
        int hp_current_;
        int hp_max_;
        int level_;
        float speed_;

    public:
        // Конструктор
        Enemy(int x, int y, int hp_max, int level, float speed);

        // Методы изменения состояния
        void move(int dx, int dy);
        void add_hp(int k);
        void set_hp(int new_hp_max);
        void set_lvl(int new_level);

        // Методы получения состояния
        std::pair<int, int> pos() const;
        int hp() const;
        int lvl() const;
        float speed() const;
    };

} // namespace Entities

#endif // ENEMY_HPP_
