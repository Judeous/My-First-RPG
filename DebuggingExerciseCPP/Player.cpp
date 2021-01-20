#include "Player.h"


Player::Player(const char* name, float health, float damage, float defense) :
    Character(name, health, damage, defense)
{ }

float Player::takeDamage(float damage)
{
    float totalDamage = damage - m_shield.getStatusBoost();

    Character::takeDamage(totalDamage);

    return totalDamage;
}

float Player::attack(Character* other)
{
    return other->takeDamage(getDamage() + m_weapon.getStatusBoost());
}

float Player::getDamage()
{
    return Character::getDamage() + m_weapon.getStatusBoost();
}

float Player::getDefense()
{
    return Character::getDefense() + m_shield.getStatusBoost();
}
