#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include "../../libft/libft.h"

typedef pthread_mutex_t mutex_t;

typedef struct s_input
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		count_eat;
}				t_input;

typedef struct	s_table
{
    mutex_t		*forks;
}				t_table;

typedef struct		s_philo
{
	int	id;
	pthread_t	pt;
	mutex_t *left_fork;
	mutex_t *right_fork;
	long	start;
	int		count_eat;
	long	last_eat;
	mutex_t	*message;
}					t_philo;

typedef struct s_all
{
	t_philo		*philo;
	//t_table		*table;
	t_input		*input;
	int			death;
}				t_all;

void	ft_error(int err);
long	get_time(long start);
void	ft_usleep(int in);
t_input	init_input(int n_philo, int t_die, int t_eat, int t_sleep);
void	init_philo(t_philo **philo, int id, mutex_t *l_fork, mutex_t *r_fork);
void	free_philo(t_philo **philo);
void	init_table(t_table *table, int count);
t_all	*init_all_args(t_philo **philo, t_input *input);
void	pthread_exec(t_all *args, int count, int count_eat);



#endif 