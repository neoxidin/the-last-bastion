#include "tower.hpp"

#include <stdexcept>

namespace Entities {

    Tower::Tower(int hp_max, int damage, int speed, int radius, int cost, int level)
        : hp_current_(hp_max)
        , hp_max_(hp_max)
        , damage_(damage)
        , speed_(speed)
        , radius_(radius)
        , cost_(cost)
        , level_(level)
    {
        if (hp_max <= 0)
            throw std::invalid_argument("hp_max must be positive");
        if (damage <= 0)
            throw std::invalid_argument("damage must be positive");
        if (speed <= 0)
            throw std::invalid_argument("speed must be positive");
        if (radius <= 0)
            throw std::invalid_argument("radius must be positive");
        if (cost < 0)
            throw std::invalid_argument("cost must be non-negative");
        if (level <= 0)
            throw std::invalid_argument("level must be positive");
    }

    // --- Методы изменения состояния ---

    void Tower::add_lvl() {
        ++level_;
    }

    void Tower::set_damage(int new_damage) {
        if (new_damage <= 0)
            throw std::invalid_argument("damage must be positive");
        damage_ = new_damage;
    }

    void Tower::set_speed(int new_speed) {
        if (new_speed <= 0)
            throw std::invalid_argument("speed must be positive");
        speed_ = new_speed;
    }

    void Tower::set_radius(int new_radius) {
        if (new_radius <= 0)
            throw std::invalid_argument("radius must be positive");
        radius_ = new_radius;
    }

    void Tower::set_cost(int new_cost) {
        if (new_cost < 0)
            throw std::invalid_argument("cost must be non-negative");
        cost_ = new_cost;
    }

    // --- Методы получения состояния ---

    int Tower::lvl() const {
        return level_;
    }

    int Tower::cost() const {
        return cost_;
    }

    int Tower::damage() const {
        return damage_;
    }

    int Tower::radius() const {
        return radius_;
    }

    int Tower::speed() const {
        return speed_;
    }

    int Tower::hp() const {
        return hp_current_;
    }

} // namespace Entities
