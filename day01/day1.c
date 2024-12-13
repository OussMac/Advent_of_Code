#include <stdio.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>


static int	flow_check(long pow, char c, int s)
{
	long	next_pow;

	next_pow = (pow * 10) + (c - 48);
	if ((s == -1 && next_pow < pow) || (s == 1 && next_pow < pow))
	{
		if (s == -1)
			return (0);
		else
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	pow;
	int		s;

	i = 0;
	s = 1;
	pow = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (flow_check(pow, str[i], s) != 1)
			return (flow_check(pow, str[i], s));
		pow = (pow * 10) + (str[i] - 48);
		i++;
	}
	return (pow * s);
}


void    sort_list(int *list,int num_of_elems)
{
    int i = 0;
    int temp = 0;
    while (i < num_of_elems - 1)
    {
        int flag = 0;
        int j = 0;
        while (j < num_of_elems - i - 1)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                flag = 1;
            }
            j++;
        }
        // if there was no swap the flag would still be 0 and the loop would break
        // we have a sorted list
        if(flag == 0)
            break;
        i++;
    }
}
int sum_list(int *list,int num_of_elems)
{
    int i = 0;
    int sum = 0;
    while (i < num_of_elems)
    {
        sum += list[i];
        i++;
    }
    return (sum);
}

void summed_pairs(int *sumd_list, int *list_1, int *list_2, int num_of_elements)
{
    int i = 0;
    while (i < num_of_elements)
    {
        sumd_list[i] = abs(list_1[i] - list_2[i]);
        i++;
    }
}

void func()
{
    system("leaks a.out");
}

int main(void)
{
    //atexit(func);
    int sumd_list[1000] = {0};
    int big_list1[1000] = {0};
    int big_list2[1000] = {0};
    int fd = open("puzzle_input.txt", O_RDONLY);
    char *line;
    int j = 0;
    while ((line = get_next_line(fd)))
    {
        big_list1[j] = atoi(line);
        big_list2[j] = atoi(line + 8);
        free(line);
        j++;
    }
    sort_list(big_list1, 1000);
    sort_list(big_list2, 1000);
    summed_pairs(sumd_list, big_list1, big_list2, 1000);
    int n = sum_list(sumd_list, 1000);
    printf("sum: %d\n", n);
    return (0);
}
