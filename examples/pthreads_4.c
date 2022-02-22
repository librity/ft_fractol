/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthreads_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:18:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 14:59:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

#define SIZE 7
#define NO_OF_THREADS 8

int		a[SIZE] = {0, 3, 5, 7, 10, 1, 2};

void	*unique_pair(void *param)
{
	long	start;

	start = (long)param;
	int i, j, k, flag;
	//each thread will start one iteration of the outmost for loop and will increment by 8 since
	//the rest 7 threads will do the previous 7 iterations
	for (i = start; i < SIZE - 1; i += 8)
	{
		for (j = i + 1; j < SIZE; j++)
		{
			//flag is initially set to 1 before starting comparing
			flag = 1;
			for (k = 0; k < SIZE; k++)
			{
				if (a[i] < a[j] && a[k] > a[i] && a[k] < a[j])
				//if a[i]<a[j] and a[k] is in bet a[i] and a[j]
				{
					//flag = 0 if value any value is found between a[i] and a[j]
					flag = 0;
					break ;
				}
				else if (a[j] < a[i] && a[k] < a[i] && a[k] > a[j])
				//if a[i]>a[j] and a[k] is in bet a[i] and a[j]
				{
					//flag = 0 if value any value is found between a[i] and a[j]
					flag = 0;
					break ;
				}
			}
			//if flag still stays 1 throughout the iterations that means no value is found in bet a[i] and a[j]
			//and a[i] and a[j] are unique pairs
			if (flag == 1)
				printf("(%d,%d) or (%d,%d) = %d\n", a[i], a[j], a[j], a[i],
						abs(a[i] - a[j]));
		}
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	thread[NO_OF_THREADS];
	int			i;
	long		j;

	for (i = 0; i < SIZE; i++)
		printf("%d\t", a[i]);
	printf("\n");
	for (j = 0; j < NO_OF_THREADS; j++)
		pthread_create(&thread[j], NULL, unique_pair, (void *)j);
	//each thread will be created and will start executing unique_pair()
	for (j = 0; j < NO_OF_THREADS; j++)
		pthread_join(thread[j], NULL);
	//all the threads created after completing the execution of the function will combine to form the main thread
	return (0);
}
