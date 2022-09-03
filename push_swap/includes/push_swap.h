/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:57:22 by hyujang           #+#    #+#             */
/*   Updated: 2022/07/18 14:44:13 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_record {
	int	pa_cnt;
	int	pb_cnt;
	int	ra_cnt;
	int	rb_cnt;
}	t_record;

typedef struct s_pivot {
	int	p_large;
	int	p_small;
}	t_pivot;

typedef struct s_node {
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_deque {
	int		cnt;
	t_node	*head;
	t_node	*tail;
}	t_deque;

typedef struct s_deque_set {
	t_deque	a;
	t_deque	b;
}	t_deque_set;

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

void	valid_check_and_init(int argc, char *argv[], t_deque *deque, int *arr);
void	error_write_exit(void);
t_node	*make_new_node(int val);
void	append_head(t_deque *deque, t_node *new_node);
void	append_tail(t_deque *deque, t_node *new_node);
void	split_free(char **p);

void	is_unique_array(int *arr, int cnt);
void	is_sorting_array(int *arr, int cnt);

void	pre_def_funtions(t_deque_set *ab, int num_cnt, t_deque *inst);

void	print_all_node(t_deque *deque);
void	print_list_ab(t_deque_set *ab);
void	printf_mapping_inst(int code);
void	print_all_node_inst(t_deque *deque);

void	del_tail(t_deque *deque);
void	init_list(t_deque *deque);
void	quick_sort(int *arr, int l, int r);

void	sa(t_deque *deque, int flag, t_deque *inst);
void	sb(t_deque *deque, int flag, t_deque *inst);
void	ss(t_deque *a, t_deque *b, t_deque *inst);
void	pa(t_deque_set *deque, t_deque *inst);
void	pb(t_deque_set *deque, t_deque *inst);
void	ra(t_deque *deque, int flag, t_deque *inst);
void	rb(t_deque *deque, int flag, t_deque *inst);
void	rr(t_deque *a, t_deque *b, t_deque *inst);
void	rra(t_deque *deque, int flag, t_deque *inst);
void	rrb(t_deque *deque, int flag, t_deque *inst);
void	rrr(t_deque *a, t_deque *b, t_deque *inst);

void	init_cnt_pivot(t_deque *deque, int range, t_pivot *pv, t_record *cnt);
void	find_pivot(t_deque *deque, int range, t_pivot *pv);
void	set_original_position(t_deque_set *ab, t_deque *inst, \
								int ra_cnt, int rb_cnt);
void	quick_sort_deque(t_deque_set *ab, int range, t_deque *inst);
void	quick_sort_deque2(t_deque_set *ab, int range, t_deque *inst);

int		find_and_update(int val, int *arr, int cnt);
void	mapping_simple_number(t_deque *deq, int *arr);

void	delete_node(t_deque *deq, t_node *p);
int		compression(t_deque *deq, t_node *p, int val);
int		delete_two_inst(t_deque *deq, t_node *p);
int		can_skip(t_deque *deq, t_node *p);
int		try_compression(t_deque *deq, t_node *p);
int		try_delete(t_deque *deq, t_node *p);

void	three_sorting_rules_a(t_deque_set *ab, t_deque *inst);
void	three_sorting_rules_b(t_deque_set *ab, t_deque *inst);

void	*malloc_and_check(size_t size);

#endif
