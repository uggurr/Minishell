#include "../minishell.h"

int	which_commant(t_list *list, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (list[0].value[i] != '\0')
	{
		if (list[0].value[i] != str[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

void	ft_builtins(char *input, t_list *list)
{
	if (list[0].type == COMMAND)
	{
		printf("%s\n",list[0].value);
		if (which_commant(list, "echo"))
		{
			ft_echo(input, list);
		}
		else if (which_commant(list, "cd"))
			ft_cd(list);
		else if (which_commant(list, "pwd"))
			ft_pwd();
		else if (which_commant(list, "export"))
			printf("export fonksiyonu çalıştı");
		else if (which_commant(list, "unset"))
			printf("unset fonksiyonu çalıştı");
		else if (which_commant(list, "env"))
			printf("env fonksiyonu çalıştı");
		else if (which_commant(list, "exit"))
			printf("exit fonksiyonu çalıştı");
	}
}
