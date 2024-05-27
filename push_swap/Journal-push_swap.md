# 9/5/24
- Started reading about project ([Wikipedia: Stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)))
- Wrote outline for input and error handling

# 10/5/24
- Implemented input handling, more

# 12/5/24
- Looked at algorithms: [quicksort](https://en.wikipedia.org/wiki/Quicksort) (see also [here](https://www.kirupa.com/sorts/quicksort.htm)), [turk](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

# 13/5/24
- Lucas writes to me to ask how it's going and suggest a few things:
	- struct for each stack
	- struct full_stack
	- do_action(func action, overarching_stack)
- Lucas showed me his general algo on whiteboard in Foundation:
	- finish with all pieces ordered in stack b, before pushing back to stack a
	- each step is to
		1. calculate for each element of stack a the number of moves it takes to put it
		into order into stack b
		2. do it for the element where the calculated # moves is smallest
		3. redo calculation 1. at each step
	- notes on moves and #move calculations:
		- n = 0-500 (moves: 5500 for 500?)
		- swaps are irrelevant, they only save 1 move vs rotation, so forget about them (it's optimization at the end)
		- hardcode moves for n <= 6 (otherwise algo is suboptimal); nb: use this when stack A is down to 6 elements
		- if n is high, only calculates move for first few elements of stack (10?) because it becomes inefficient anyway if have to go down hundreds of elements and rotate that many times to bring them up

- Did structs for lists and input handling
- ft_push_b, ft_push_a: done by reorienting `->next` .<br>
- ft_rotate, ft_reverse_rotate: done

# 14/5/24
- now on to sorting. Looked at quicksort to calculate a rank for each value, but Lucas tells me it's useless, just need
to figure out between which two values of stack b I must place my element from stack a 
- ft_calculate_min_max for edge cases
- ft_optimal_position: I don't look at two values, just each value, whether the a_value should take its place (i.e. push it one value below). seems to work even in edge cases
- ft_set_position: sets the position (order of appearance) of each element of a stack 
- ft_calculates_sizes: calculates size of each stack
- ft_calculate_cost (ongoing): to find the minimum number of moves to place an element from its current position in a to its optimal position in b. 
- created a struct `t_element_solution` to store the best solution for the sorting of an element. Unclear how to efficiently code it to calculate the best sequence of actions and return both the total number of moves (for comparison with other elements) and the corresponding set of actions and #moves for each action
- ft_do_multiple_actions: to help orchestrate sequences, to be called by **ft_do_sort** (using information from elem_insert where the optimal solution was stored, by ft_outline_sort and ft_optimal_insertion If w)
=> see sort.c

# 15/5/24
- Wrote the insertion evaluation part per element (which will need to be run on the whole stack)
- Refactored (more source files, changed references to "insertion" from "sort" for clarity)
- Not sure if it works, didn't test components.
- How to test: call `ft_optimal_insertion` from main and print out result.

# 18/5/24
- Back to work (in Monthey)
- Debugging to enable calls to `ft_optimal_insertion` from main and printing the result

# 19/5/24
- Continued (in Monthey): okay, we're printing out stuff (still ft_printf shenanigans making me lose another 30-40min, need to fix it)
- Learned the (void) casting of a variable to tell compiler to ignore it
- Fixing `ft_optimal_position`. Positions need to start at 0, not 1, because we use position to calculate rotations.

# 22/5/24
- Back to work (Unimail)
- Trying to fix segfault in ft_calculate_sizes: segfault moves around, even for list `list = list->next;`don't understand why, maybe the sanitizer's Oxbebe which changes the value ?
- Fixing segfaults from ft_optimal_insertion/ft_optimal_position when a_stack is empty: actually useless, only call ft_optimal_insertion if there is an element to insert. Now maybe, add checks in case b_stack doesn't exist yet
- Segfault in ft_calculate_sizes due to `full_stack->b_head = full_stack->b_head->next;` in while even though there was a check

# 23/5/24
- Back to work (at school)
- Added back ft_set_positions which was missing
- Until now, used ft_optimal_position to determine where to place a value from stack a above a value from stack b that is smaller.
Problem is, with `./push_swap 1 2 3 4 5 6 7 8 9` and moves :
```c
ft_do_multiple_actions(PB, full_stack, 5);
ft_do_multiple_actions(RRA, full_stack, 3);
ft_do_multiple_actions(PA, full_stack, 1);
ft_do_multiple_actions(RRB, full_stack, 1);
ft_do_multiple_actions(PA, full_stack, 1);
```
, I get :
a:
0) 1
1) 5
2) 7
3) 8
4) 9
5) 6

b:
0) 4
1) 3
2) 2

Thus "1" from a is smaller than all values from b, and should be placed at the tail of stack b, i.e. in place 3), beneath "2".

Need to recheck ft_count_required_moves because instructions are wrong insertion functions
for that, or maybe rethink the whole thing.

# 24/5/24
- Reworked insertion calculations:
	- Fixed `ft_optimal_insertion` for norminette, made an `ft_abs` function
	- Removed `ft_calculate_min_max` use as input in ft_optimal_position, replaced with INT_MAX, so deleted the function
	- in `ft_count_required_moves`, added exceptions for optimal_position == 0 and == size_b (size of stack b)
	- Decided not to put b stack in final order before the end. E.g. if an element from a must be put at the end of b, put it at the top of the stack, then reorder the whole at the end
- Wrote an iteration over the stack a to select the best element to insert and print out along with the insertion moves

# 27/4/24
- How do I want to use my optimal insertion calculator ?
- Help from Lucas (ft_calculate_cost)
- To do :
	-  problems with `./push_swap 42 61 8 14 12 13 15 67 -23 191 1 | grep "size: a"`, we get
	```c
size: a 9, b 2, optimal_position: 2
size: a 8, b 2, optimal_position: 2
size: a 7, b 2, optimal_position: 2
```
=> it looks like our stack handling functions have issues. Test them systematically before anything else