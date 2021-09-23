#include "ft_so_long.h"

static void ft_check_params(int argc, char **argv);

int main (int argc, char **argv)
{
	ft_check_params(argc, argv);
	ft_sl_run(*(argv + 1));
	return (0);
}

static void ft_check_params(int argc, char **argv)
{
	if (argc != 2 || argv == NULL)
	{
		printf("Invalid arguments number");
		exit (EXIT_FAILURE);
	}
}