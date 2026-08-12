#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap("Cris");

    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    for (int i = 0; i < 10; i++)
        clap.attack("Enemy");

    clap.beRepaired(5);

    ClapTrap copy(clap);
    copy.attack("Enemy");

    ClapTrap assigned("Other");
    assigned = clap;
    assigned.attack("Enemy");

    return 0;
}