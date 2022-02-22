/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthreads_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:18:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 14:05:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		g = 0;

void	*myThreadFun(void *vargp)
{
	int			*myid;
	static int	s;

	myid = (int *)vargp;
	s = 0;
	++s;
	++g;
	printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
}

int	main(void)
{
	int			i;
	pthread_t	tid;

	for (i = 0; i < 3; i++)
		pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
	pthread_exit(NULL);
	return (0);
}
