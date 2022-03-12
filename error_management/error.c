#include "../includes/so_long.h"

void	end_program(char *mess)
{
	perror(mess);
	exit (84);
}
