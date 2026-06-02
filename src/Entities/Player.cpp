#include "player.hpp"

#include <algorithm>
#include <limits>
#include <stdexcept>

namespace Entities {

    Player::Player(int hp_max, int money, int level, int wave_max)
        : hp_current_(hp_max)
        , hp_max_(hp_max)
        , money_(money)
        , level_(level)
        , wave_max_(wave_max)
    {
        if (hp_max <= 0)
            throw std::invalid_argument("hp_max must be positive");
        if (money < 0)
            throw std::invalid_argument("money must be non-negative");
        if (level <= 0)
            throw std::invalid_argument("level must be positive");
        if (wave_max < 0)
            throw std::invalid_argument("wave_max must be non-negative");
    }

    // --- Методы изменения состояния ---

    void Player::add_hp(int k) {
        hp_current_ = std::min(hp_current_ + k, hp_max_);
    }

    void Player::set_hp(int new_hp_max) {
        if (new_hp_max <= 0)
            throw std::invalid_argument("hp_max must be positive");

        hp_current_ = std::min(hp_current_, new_hp_max);
        hp_max_ = new_hp_max;
    }

    void Player::add_money(int k) {
        if (k < 0 && money_ + k < 0)
            throw std::invalid_argument("money cannot go below zero");

        // Защита от переполнения int
        const int int_max = std::numeric_limits<int>::max();
        if (k > 0 && money_ > int_max - k)
            money_ = int_max;
        else
            money_ += k;
    }

    void Player::add_lvl() {
        ++level_;
    }

    void Player::set_wave(int new_wave_max) {
        if (new_wave_max < 0)
            throw std::invalid_argument("wave_max must be non-negative");
        wave_max_ = new_wave_max;
    }

    // --- Методы получения состояния ---

    int Player::hp() const {
        return hp_current_;
    }

    int Player::wave() const {
        return wave_max_;
    }

    int Player::money() const {
        return money_;
    }

} // namespace Entities
