#include "cub3d_bonus.h"

float	**creat_door_tab(int x, int y)
{
	float **door_tab;
	int i;

	i = 0;
	door_tab = malloc(sizeof(float *) * (y + 1));
	if (!door_tab)
		return (NULL);
	while (i < y)
	{
		door_tab[i] = malloc(sizeof(float) * (x + 1));
		if (door_tab[i] == NULL)
		{
			while (i > 0)
			{
				i--;
				free(door_tab[i]);
			}
			free(door_tab);
			return (NULL);
		}
		i++;
	}
    return (door_tab);
}

void fill_door_tab(float **door_tab, int x, int y)
{
    int i;
    int j;

    i = 0;
    while (i < y)
    {
        j = 0;
        while (j < x)
        {
            door_tab[i][j] = 0.0f;
            j++;
        }
        i++;
    }
}