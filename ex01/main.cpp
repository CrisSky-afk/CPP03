#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap clap("Cris");

    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.guardGate();

    for (int i = 0; i < 10; i++)
        clap.attack("Enemy");

    clap.beRepaired(5);

    ScavTrap copy(clap);
    copy.attack("Enemy");

    ScavTrap assigned("Other");
    assigned = clap;
    assigned.attack("Enemy");

    return 0;
}