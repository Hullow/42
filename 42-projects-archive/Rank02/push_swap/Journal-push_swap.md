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
	- struct stacks
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
- Segfault in ft_calculate_sizes due to `stacks->b_head = stacks->b_head->next;` in while even though there was a check

# 23/5/24
- Back to work (at school)
- Added back ft_set_positions which was missing
- Until now, used ft_optimal_position to determine where to place a value from stack a above a value from stack b that is smaller.
Problem is, with `./push_swap 1 2 3 4 5 6 7 8 9` and moves :
```c
ft_do_multiple_actions(PB, stacks, 5);
ft_do_multiple_actions(RRA, stacks, 3);
ft_do_multiple_actions(PA, stacks, 1);
ft_do_multiple_actions(RRB, stacks, 1);
ft_do_multiple_actions(PA, stacks, 1);
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

# 28/5/24
- Fixed size calculation: it was because we were calculating size based on `stacks->a_head`, which moves in the while() in our main. Replaced it with a variable `stack_iterator` so size can be calculated with an untouched `stacks->a_head`
- Looks like I debugged a few things, and now can see a stack be rearranged !
- Need a function to do the final stack arrangement (e.g. ft_stack_max to calculate maximum value, then rotate or reverse_rotate until found)
=> done !
- Now let's check and optimise

# 29/5/24
- Working on checker (also spent some time setting up everything on Ubuntu): but how to do it without strcmp ?
	- had to modify ft_atoi and ft_putnbr_unsigned due to gcc warnings
	- Checker quite useful to test actions on stacks in real time. Fouixed segfault in reverse rotate if empty stack, also need to fix this (if a single element in stack, rr makes it disappear, but not rrb/rra)
		- bug to fix: rr doesn't work if one stack is empty, but rrr does ! => **still not fixed**
		- otherwise checker seems to work

# 30/5/24
- Using tester.sh, mostly red so far
- Fixed: the prints to only print the moves (and not "action N: pa") => works for 100 and 500-length stacks !!!
- Finished writing checker, also added ft_find_duplicates for the input handling
- Error handling: ok
- Problems: basic input, small stacks (size 5). Larger stacks okay (a few 4/5 yellow though)
- Norm : to be done

# 31/5/24
- Advanced on checker, swapping functions

# 3/6/24
- Fixed swapping function
- Checker: fixed seg faults, bad input

# 4/6/24
- Worked on swap, seems to work ok
- Checker seems to work too
- Problem: small stacks => don't print out the whole stack after ft_sort_small_stack (or some component thereof)
- Also, not sure if ft_sort_three_elements doesn't sort upside down => test!

# 5/6/24
- All right, focused in silence (thank you !) and redid the 3-element-stack hardcoding. Also added an anchor to ft_check_stack,
which was the source of the issue with only part of a stack being printed out

# 6/6/24
- Checker okay now
- Working on small stacks: for a stack of 5, trying out Filipo (Fcandia)'s idea of pushing the two smallest elements to b in an optimized way, but it does too many moves. To debug and test

# 7/6/24
- Working version, also for small stacks, but some "OK (4/5)" yellow results for stacks of 500, leaks issues. See "latest_test_output.txt" for output.
- To do: check 4/5 yellow results, then fix leaks and norm, then retest
- Working on Norm, renaming functions for clarification
- Maybe fix large stacks 4/5 to have "perfect" project so bonus can be counted
	=> by not checking further than 10 first elements when looking for optimal insertion maybe


To do: remove printfs !!!

# 10/6/24
- Solved largest stack issue (>5500 moves):
	- initially started with Lucas' idea of not searching further than X elements in the stack (e.g. 10, 50) and coded a function ft_advance_X_elements for that but it didn't solve the problem
	- decided to take a look at one sequence that was too long and saw hundreds of "rb" at the end (pushing the highest element at the top of the b stack before pushing back to a stack); added a if/else with rrb instead if max_element->position > (size_b / 2) => solved in two lines
- Remaining issues:
	- "order nums" test (?)
	- all size test + leaks check => "KO Leaks" every 5 test
		=> solved; no more errors with Tester ! 
- Learning to use valgrind
- Did some work on Norm, two things remain:
	- ft_calculate_cost to be broken down
	- ft_optimal_position to be shortened

# 11/6/24
- Put ft_calculate_cost to Norm (separated in a few functions)
- Cannot run norminette on MacBook... => fixed with `pip3 install --upgrade norminette` and `export PATH=$PATH:/Library/Frameworks/Python.framework/Versions/3.10/bin`
- Norm okay except comments in cost.c
- Norm not done in checker

# 17/6/24
To do (from last time):
- Check cost.c function with comments inside => done
- Test with tester => ok
- Norm the header => done
- Test the checker => crap, get the "error: move not recognised"
- Norm the checker

Push_swap sorter done, now trying to fix the checker, unsuccessfully so far

Unclear how to signal that input is finished. Replaced "end" instruction with "\n"
but to use checker with push_swap output is different...how to understand that input is at the end ?
for ./push_swap [ARGS] | ./checker [$ARGS] (=> "Error" after like 5 moves, which I cannot reproduce 
by inputing the sequence manually...)

To do:
- Checker (+ checker Norm)

# 18/6/24
- Used GNL instead of read in checker (cf Rui's advice) => problem solved
- Added GNL to the libft used in push_swap
- Norm-ing and refactoring the checker
	=> done. now need to put into main Makefile via "bonus" rule
		=> done
	=> also, need to do a few more tests of the checker
		=> okay right, done albeit a bit superficially

=> pushed, will subscribe to defence tomorrow morning (no spots yet)

# 20/6/24
- Forgot to check for leaks in checker => see some with valgrind unfortunately.
=> done

- Gave up project to be able to resubmit (at 6:30 pm )=> try again in two days
	=> files to push: /Rendus/PS-gittest1

# 2/7/24
- Finally pushed and corrected.
- Fixed a few things with the checker (error treatment in checker_utils.c)
- Issues remaining:
	- Makefile relink! careful!
	- ft_check_input => redundancy in checking for e.g. 3333-3333
		=> way to do is to use compare ft_strlen before and after ft_atoi => if shorter after atoi, means some characters are 			not integers
	- 