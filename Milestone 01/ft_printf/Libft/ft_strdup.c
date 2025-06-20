/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:22:23 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:44:33 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  La funzione strdup è una funzione in C che serve a duplicare 
 una stringa, creando una copia dinamica della stessa in memoria 
 heap. Essa alloca automaticamente la memoria necessaria per 
 memorizzare una nuova stringa e copia il contenuto della stringa 
 originale in questa nuova area di memoria. */

char	*ft_strdup(const char *s)
{
	char	*copy;

	copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s, ft_strlen(s) + 1);
	return (copy);
}
