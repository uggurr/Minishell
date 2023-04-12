#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_list		*list;
	char		*input;

	(void)argc;
	(void)argv;

	while (1)
	{
		input = readline("minishell: ");
		add_history(input);
		if (ft_opr_pair(input))
			return (0);
		list = malloc(sizeof(t_list) * (ft_str_shred(input) + 1));
		list->env = env;
		init_env(list);
		ft_uname(input, list);
		ft_untype(input, list);
		ft_env_check(input, list);
		ft_builtins(input, list);
	}
}
