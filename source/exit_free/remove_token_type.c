/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_token_type.c                                :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

void	ft_remove_token_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->flags)
		free(cmd->flags);
	cmd->flags = NULL;
	if (cmd->bin)
		free(cmd->bin);
	cmd->bin = NULL;
	if (cmd->arg)
		free(cmd->arg);
	cmd->arg = NULL;
	if (cmd->content)
		free(cmd->content);
	cmd->content = NULL;
	ft_remove_all_arg(cmd);
	free(cmd);
}

void	ft_remove_token_redir(t_redir *redir)
{
	if (!redir)
		return ;
	if (redir->tmp_file)
	{
		if (redir->tmp_file->fd > 2)
			close(redir->tmp_file->fd);
		if (redir->tmp_file->name)
			free(redir->tmp_file->name);
		free(redir->tmp_file);
		redir->tmp_file = NULL;
	}
	if (redir->content)
		free(redir->content);
	redir->content = NULL;
	if (redir->delimiter)
		free(redir->delimiter);
	redir->delimiter = NULL;
	free(redir);
}

void	ft_remove_token_file(t_file *file)
{
	if (!file)
		return ;
	if (file->name)
		free(file->name);
	file->name = NULL;
	if (file)
		free(file);
}

void	ft_remove_token_word(t_word *word)
{
	if (!word)
		return ;
	if (word->content)
		free(word->content);
	word->content = NULL;
	free(word);
}

void	ft_remove_and_disconnect_env_var(t_env *env, t_var *var)
{
	t_var	*iter;

	iter = ft_get_first_env_var(env);
	if (!iter)
		return ;
	while (iter)
	{
		if (iter->index == var->index)
		{
			ft_disconnect_env_var(env, var);
			ft_free_env_var(var);
			return ;
		}
		iter = iter->next;
	}
}
