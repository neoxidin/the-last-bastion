#ifndef TOWER_HPP_
#define TOWER_HPP_

#pragma once

namespace Entities {

    class Tower {
    private:
        int hp_current_;
        int hp_max_;
        int damage_;
        int speed_;
        int radius_;
        int cost_;
        int level_;

    public:
        // Конструктор
        Tower(int hp_max, int damage, int speed, int radius, int cost, int level);

        // Методы изменения состояния
        void add_lvl();
        void set_damage(int new_damage);
        void set_speed(int new_speed);
        void set_radius(int new_radius);
        void set_cost(int new_cost);

        // Методы получения состояния
        int lvl() const;
        int cost() const;
        int damage() const;
        int radius() const;
        int speed() const;
        int hp() const;
    };

} // namespace Entities

#endif // TOWER_HPP_
