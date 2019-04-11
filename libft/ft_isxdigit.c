/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isxdigit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 14:16:12 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/05 14:34:41 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isxdigit(int c)
{
	if ((c >= '0' && c <= '9')
	|| (c >= 'a' && c <= 'f')
	|| (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}