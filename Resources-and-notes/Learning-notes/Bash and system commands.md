## Storage
- [[B2Broot#^9f40d4 | lsblk]] : to list storage volumes (partitions)
- `du -h` / `df -h`: disk usage/disk free space (-h: human readable)


## Packages
-  [[B2Broot#^b03539 | apt list --installed]]: show all installed packages

## Names, users,  groups, permissions
<<<<<<< HEAD
- `whoami` : current user
- change user: `su <username>`
- `cat /etc/passwd` : lists all users
=======
>>>>>>> 879b9a0 (More notes on B2BRoot & programming)
- [[B2Broot#^77cbc1 | usermod]]: to change users' groups, home directories, etc.
- `userdel` : delete user
- [[B2Broot#^7fc8e8 | getent group sudo]] : list users part of the sudo group
- `hostname`, `hostnamectl`, `hostnamectl -set-hostname <new_hostname>`
<<<<<<< HEAD
- `passwd`: change password of current user
- 

## Prompt settings
- `echo $PS1 && oldps1="$PS1"` to get the current prompt setting and save it
- `export PS1="\e[0;34m$oldps1"` to change the prompt color (0;30 black, 0;32 green, 0:34 blue, ...)
=======
>>>>>>> 879b9a0 (More notes on B2BRoot & programming)
