#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Parameter arrays
nb_philos=(1 2 3 4 10 50 80 100 150 200)
time_to_die=(400 600 1000 1500 2000)
time_to_eat=(200 300 400 600 1000)
time_to_sleep=(200 300 400 600 1000)

# Run philo with timeout
run_test() {
    local w=$1 x=$2 y=$3 z=$4
    local output_file="test-$w-$x-$y-$z.txt"
    
    ./philo $w $x $y $z > "$output_file" &
    local pid=$!
    sleep 3
    kill -INT $pid 2>/dev/null
    wait $pid 2>/dev/null
    
    process_output "$output_file" $w $x $y $z
}

# Process output file
process_output() {
    local file=$1 w=$2 x=$3 y=$4 z=$5
    
    if grep "has died" "$file" > /dev/null; then
        local dead_philo=$(grep "has died" "$file" | awk '{print $2}')
        local dead_file="dead-philo-$w-$x-$y-$z.txt":q
        
        grep " $dead_philo " "$file" > "$dead_file"
        
        # Get death timestamp
        local death_time=$(grep "has died" "$dead_file" | awk '{print $1}')
        
        # Get last eating/thinking timestamp
        local last_action_time
        if grep "is eating" "$dead_file" > /dev/null; then
            last_action_time=$(grep "is eating" "$dead_file" | tail -1 | awk '{print $1}')
        else
            last_action_time=$(grep "is thinking" "$dead_file" | tail -1 | awk '{print $1}')
        fi
        
        # Calculate time differences
        local time_diff=$((death_time - last_action_time))
        local result=$((x - time_diff))
        
        # Print result
        if [ $result -lt 0 ] || [ $result -ge 10 ]; then
            printf "${RED}test-$w-$x-$y-$z: philosopher $dead_philo took $result ms difference from time_to_die ($x ms) to die - FAIL${RED}\n"
        else
            printf "${NC}test-$w-$x-$y-$z: philosopher $dead_philo took $result ms more than time_to_die ($x ms) to die - ${NC}${GREEN}OK${GREEN}\n"
			rm -f "$file" "$dead_file"
	    fi
    fi
}

# Main test loop
for w in "${nb_philos[@]}"; do
    for x in "${time_to_die[@]}"; do
        for y in "${time_to_eat[@]}"; do
            for z in "${time_to_sleep[@]}"; do
                run_test $w $x $y $z
            done
        done
    done
done