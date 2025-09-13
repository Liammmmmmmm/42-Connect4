/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:35:39 by ebini             #+#    #+#             */
/*   Updated: 2025/06/30 18:55:11 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stddef.h>
# include <stdbool.h>

# define ENV_MIN_CAPACITY 64

typedef struct s_env
{
	char	**data;
	size_t	capacity;
}			t_env;

enum e_env_flags
{
	ENV_INIT = 0,
	ENV_SET,
	ENV_GET,
	ENV_UNSET,
	ENV_TO_ENVP,
	ENV_CLEAR,
};

size_t	env_var_len(const char *var_name);
bool	is_env_var_start(char c);
bool	is_env_var_char(char c);
int		increase_env_capacity(t_env *env);
int		decrease_env_capacity(t_env *env);

t_env	*env_create(char **envp);
int		env_init(t_env *env, char **envp);
int		env_set(t_env *env, char *var_name, char *value);
char	*env_get(t_env *env, char *var_name);
char	**env_to_envp(t_env *env);
void	env_unset(t_env *env, char *var_name);
void	env_clear(t_env *env);

void	*env_handle(int action, ...);

void	ft_clearenv(void);
char	*ft_getenv(char *var_name);
char	**ft_getenvp(void);
int		ft_initenv(char **envp);
int		ft_setenv(char *var_name, char *value);
void	ft_unsetenv(char *var_name);

#endif
