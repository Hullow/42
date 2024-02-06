
## Command handling
- `ctrl+A` : move cursor to start of command prompt
- `ctrl+R` : search past commands (tap `ctrl+R` again to search for the next occurrence, then `tab` to select)

## System state and information
- `man 7 file-hierarchy`: explain Linux file hierarchy
- `uname -a` : print system information (kernel name, release, nodename, machine, processor, hardware, OS)
- `cat /etc/os-release`: display OS version
- [[B2Broot#^9f40d4 | lsblk]] : list storage volumes (partitions)
- `du -h` / `df -h`: disk usage/disk free space (-h: human readable)
- `free --mega`: show total, used and available memory in megabytes
- `uptime`: current time, time running, users logged in, system (CPU+I/O e.g. disks) load averages for 1, 5, 15min
- `journalctl _COMM=sudo -q` : print all sudo commands from system inception## File manipulation
- Add "*-suffix*" to all file names: ```for file in *; do
						        mv "$file" "${file%.}-suffix"
							done```
- 
## Text analysis and processing
- `wc -c/-m/-l/-w` : count bytes, characters, lines (or all with only `wc`)
- `head/tail` : print the first/last 10 lines of each FILE (or piped input).
	- `-n X` : input the first/last X lines
	- `-n +X`: start with line X
- `[command] | > file.txt`: write the results of a command to a file
### awk
- `awk 'NR {count++} END {print count} <file>'`: print number of lines in a file
- `awk -F: '{print $2}'` : define a field as separated by \<separator>, here the second field after a ":"
- CLI copy-paste: `screen` followed by `ctrl + A`followed by `[` followed by `space`, select text with arrows, `space`, to copy, then `ctrl + A` and `[` again to paste

## Names, users,  groups, permissions
- `whoami` : current user
- `w`: display who is logged in 
- change user: `su <username>`
- `cat /etc/passwd` : lists all users
- [[B2Broot#^77cbc1 | usermod]]: to change users' groups, home directories, etc.
- `useradd` : new user
- `userdel` : delete user
- `[[B2Broot#^7fc8e8 | getent group <group_name>]]`: list users of a group with output: \<groupname>:\<password> (encrypted group password, empty signifies no password, `x` bit signifies the password is in the file `/etc/gshadow`) : \<group-ID> : \<user(s)> (member of this group, empty means no member)
- `groupadd --users <username1> <username2>` : create new group
- `hostname`, `hostnamectl`, `hostnamectl -set-hostname <new_hostname>`
- `passwd`: change password of current user

## Prompt settings
- `setterm -foreground black -background white` : to change terminal colors (Linux)
- `echo $PS1 && oldps1="$PS1"` to get the current prompt setting and save it
- `export PS1="\e[0;34m$oldps1"` to change the prompt color (0;29 white , 0;30 black, 0;32 green, 0:;33 orange, 0:34 blue, ...)
- `export PS1="\e[0;34m$oldps1"` to change the prompt color (0;30 black, 0;32 green, 0:34 blue, ...)

## Package management
- `apt-get install <package>` : download and install a package
- `apt list --installed lib*` : list all installed packages starting with "lib"
- `apt search <package>`: search for a given term(s) and display matching packages
- `apt show <package>`: display details about a given package(s)


## Vim
- `let @*=@"` copy contents from unnamed register (from yank) to clipboard

### navigation and edit mode
- go to top of file: `gg`
- go to end of file: `G`
- go to middle of file: `M`
- insert a line above/below and go to insert mode: `O` or `o`
- search: `/` then `n` or `N` to go to the next or previous occurrence
- show whitespace (including end of lines, as `$`, and carriage returns, as `^M`): `:set list`

### modifying text
- substitute: `:%s/old/new/gn` => % for all lines/current file (`g` to substitute for all of each line, not just once per line, `n` to count occurrences)
	- to substitute newlines: use `\n`
- case insensitivity in patterns: adding \c anywhere in the pattern, e.g. `:$s/\cold/new` for a substitution.
- delete:
	- range of lines: `:[start],[end]d`
	- beginning/rest of line up to cursor: `d0/d$`

`:[line]co [destination line]`. Or just `:co [destination line]` to  ????


### Settings

to disable a setting: `set no[command]`, e.g. `set noline`
- `:syntax enable / syntax off`
- `:set` :
	- `number` (to see line numbers)
	- `cursorline`

### File handling
- `:saveas [newname]` : rename
