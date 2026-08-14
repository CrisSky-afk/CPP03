#include "FragTrap.hpp"

int main(void)
{
    FragTrap clap("Cris");

    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.highFivesGuys();

    for (int i = 0; i < 10; i++)
        clap.attack("Enemy");

    clap.beRepaired(5);

    FragTrap copy(clap);
    copy.attack("Enemy");

    FragTrap assigned("Other");
    assigned = clap;
    assigned.attack("Enemy");

    return 0;
}