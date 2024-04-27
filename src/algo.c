
#include "push_swap.h"

void    final_sorting(t_dll **stack_a)
{
    int min_index;
    int diff_min;
    int size;

    min_index = find_min_index(*stack_a);
    size = dll_size(*stack_a);
    if (min_index > (size - 1) / 2)
    {
        diff_min = size - min_index;
        while (diff_min > 0)
        {
            r_rotate(stack_a, NULL, MOVE_A);
            diff_min--;
        }
        return ;
    }
    if (min_index <= (size - 1) / 2)
    {
        while (min_index > 0)
        {
            rotate(stack_a, NULL, MOVE_A);
            min_index--;
        }
        return ;
    }
}

void    do_moves(t_dll **stack_a, t_dll **stack_b)
{
    t_bestmoves moves;

    moves = get_best_moves(*stack_a, *stack_b);
    if (moves.rot_a || moves.rot_b || moves.rot_both)
        get_rotate(stack_a, stack_b, moves);
    if (moves.r_rot_a || moves.r_rot_b || moves.r_rot_both)
        get_r_rotate(stack_a, stack_b, moves);
}

void    solve_all(t_dll **stack_a, t_dll **stack_b)
{
    int size_all;
    int size_a;
    int size_b;

    size_all = dll_size(*stack_a) + dll_size(*stack_b);
    size_b = dll_size(*stack_b);
    size_a = 0;
    while (stack_b && size_all != size_a)
    {
        do_moves(stack_a, stack_b);
        pa(stack_a, stack_b);
        size_a = dll_size(*stack_a);
    }
    if (!is_sorted(*stack_a))
        final_sorting(stack_a);
}