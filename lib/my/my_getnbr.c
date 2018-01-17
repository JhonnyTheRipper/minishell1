/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** lib
*/

char	is_digit(char str)
{
  if (str >= '0' && str <= '9')
    return (1);
  return (0);
}

int	chars_to_int(char *start, char *end)
{
  int	multp;
  int	numb;

  if (!start || !end)
    return (0);

  numb = 0;
  multp = 1;
  while (end >= start)
    {
      numb = numb + ((*end - 48) * multp);
      multp = multp * 10;
      end = end - 1;
    }
  if (*(start - 1) == '-')
    numb = numb * (-1);
  return (numb);
}

int	my_getnbr(char *str)
{
  char	i;
  char	*start;
  char	*end;

  start = 0;
  end = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (is_digit(str[i]))
	{
	  if (!start)
	    start = &(str[i]);
	  if ((str[i + 1] == '\0' || !is_digit(str[i + 1])) && !end)
	    end = &(str[i]);
	}
      else if (!start && !end)
	{
	  start = 0;
	  end = 0;
	}
      i = i + 1;
    }
  return (chars_to_int(start, end));
}
