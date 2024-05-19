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