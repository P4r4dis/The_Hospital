#include "../includes/my_hospital.hpp"

int     main(int ac, char **av)
{
    if (ac < 2 && av) {
        return 1;
    }
    return 0;
}
