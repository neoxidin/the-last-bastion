#include "enemy.hpp"

#include <algorithm>
#include <stdexcept>

namespace Entities {

    Enemy::Enemy(int x, int y, int hp_max, int level, float speed)
        : x_(x)
        , y_(y)
        , hp_current_(hp_max)
        , hp_max_(hp_max)
        , level_(level)
        , speed_(speed)
    {
        if (hp_max <= 0)
            throw std::invalid_argument("hp_max must be positive");
        if (level <= 0)
            throw std::invalid_argument("level must be positive");
        if (speed <= 0.0f)
            throw std::invalid_argument("speed must be positive");
    }

    // --- Методы изменения состояния ---

    void Enemy::move(int dx, int dy) {
        x_ += dx;
        y_ += dy;
    }

    void Enemy::add_hp(int k) {
        hp_current_ = std::min(hp_current_ + k, hp_max_);
    }

    void Enemy::set_hp(int new_hp_max) {
        if (new_hp_max <= 0)
            throw std::invalid_argument("hp_max must be positive");

        hp_current_ = std::min(hp_current_, new_hp_max);
        hp_max_ = new_hp_max;
    }

    void Enemy::set_lvl(int new_level) {
        if (new_level <= 0)
            throw std::invalid_argument("level must be positive");
        level_ = new_level;
    }

    // --- Методы получения состояния ---

    std::pair<int, int> Enemy::pos() const {
        return { x_, y_ };
    }

    int Enemy::hp() const {
        return hp_current_;
    }

    int Enemy::lvl() const {
        return level_;
    }

    float Enemy::speed() const {
        return speed_;
    }

} // namespace Entities
