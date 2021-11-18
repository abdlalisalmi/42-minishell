/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:44:43 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/17 01:28:16 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"
#include "../includes/main.h"

t_token *init_token(t_token_type type, char *value)
{
	t_token *token;

	if (value == 0)
		put_error(errno);
	token = (t_token *)malloc(sizeof(t_token));
	if (token == 0)
		put_error(errno);
	token->type = type;
	token->value = value;
	return (token);
}
