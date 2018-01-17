/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
**
*/
int my_strcmp(char *s1, char *s2)
{
  int			i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\n') && (s2[i] != '\0'))
    {
      i++;
    }
  return (s1[i] - s2[i]);
}