#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

// Ele serve para permitir que um ClapTrap que já existe receba os valores de outro ClapTrap.

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) // deve fazer o ClapTrap perder amount pontos de vida.
{
    if (_hitPoints > 0)
    {
        if (amount >= _hitPoints)
            _hitPoints = 0;
        else
            _hitPoints -= amount;

        std::cout << "ClapTrap " << _name << " takes " << amount
                  << " points of damage! Remaining hit points: "
                  << _hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is already dead!"
                  << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) // faz o ClapTrap recuperar amount de HP e que reparar custa 1 ponto de energia. Se ele não tiver HP ou energia, não pode fazer a ação.
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points! Current hit points: " << _hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " has no energy or hit points left to repair!" << std::endl;
    }
}