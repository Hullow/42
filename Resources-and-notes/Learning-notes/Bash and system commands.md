## System state
- [[B2Broot#^9f40d4 | lsblk]] : to list storage volumes (partitions)
- `du -h` / `df -h`: disk usage/disk free space (-h: human readable)
- `free --mega`: show total, used and available memory in megabytes
- `uptime`: current time, time running, users logged in, system (CPU+I/O e.g. disks) load averages for 1, 5, 15min


## Text analysis and processing
- `wc -c/-m/-l/-w` : count bytes, characters, lines (or all with only `wc`)
- `tail` : print the last 10 lines of each FILE (or piped input).
	- `-n X` : input the last X lines
	- `-n +X`: start with line X
- `[command] | > file.txt`: write the results of a command to a file
- `awk 'NR {count++} END {print count} <file>'`: print number of lines in a file

## Packages
-  [[B2Broot#^b03539 | apt list --installed]]: show all installed packages

## Names, users,  groups, permissions
- `whoami` : current user
- change user: `su <username>`
- `cat /etc/passwd` : lists all users
- `whoami` : current user
- change user: `su <username>`
- [[B2Broot#^77cbc1 | usermod]]: to change users' groups, home directories, etc.
- `userdel` : delete user
- [[B2Broot#^7fc8e8 | getent group sudo]] : list users part of the sudo group
- `hostname`, `hostnamectl`, `hostnamectl -set-hostname <new_hostname>`
- `passwd`: change password of current user
- `w`: display who is logged in 

## Prompt settings
- `echo $PS1 && oldps1="$PS1"` to get the current prompt setting and save it
- `export PS1="\e[0;34m$oldps1"` to change the prompt color (0;30 black, 0;32 green, 0:34 blue, ...)
- `export PS1="\e[0;34m$oldps1"` to change the prompt color (0;30 black, 0;32 green, 0:34 blue, ...)


## Package management
- `apt-get install <package>` : download and install a package
- `apt list --installed lib*` : list all installed packages starting with "lib"
- `apt search <package>`: search for a given term(s) and display matching packages
- `apt show <package>`: display details about a given package(s)


## Vim
- `let @*=@"` copy contents from unnamed register (from yank) to clipboard

### navigation and edit mode
gg to go to top of file
G to end of file
M to go to middle of file
O or o to insert a line above/below and go to insert mode
search: / then n or N to go to the next or previous occurrence

### modifying text
- substitute: `:%s/old/new/gn` => % for all lines/current file (`g` to substitute for all of each line, not just once per line, `n` to count occurrences)
- case insensitivity in patterns: adding \c anywhere in the pattern, e.g. `:$s/\cold/new` for a substitution.
- delete:
	- range of lines: `:[start],[end]d`
	- beginning/rest of line up to cursor: `d0/d$`

`:[line]co [destination line]`. Or just `:co [destination line]` to  ????


### settings

to disable a setting: `set no[command]`, e.g. `set noline`
- `:syntax enable / syntax off`
- `:set` :
	- `number` (to see line numbers)
	- `cursorline`

### File handling
- `:saveas [newname]` : rename