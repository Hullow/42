## Storage
- [[B2Broot#^9f40d4 | lsblk]] : to list storage volumes (partitions)
- `du -h` / `df -h`: disk usage/disk free space (-h: human readable)


## Packages
-  [[B2Broot#^b03539 | apt list --installed]]: show all installed packages

## Names, users,  groups, permissions
- `whoami` : current user
- change user: `su <username>`
- [[B2Broot#^77cbc1 | usermod]]: to change users' groups, home directories, etc.
- [[B2Broot#^7fc8e8 | getent group sudo]] : list users part of the sudo group
- `hostname`, `hostnamectl`, `hostnamectl -set-hostname <new_hostname>`
- `passwd`: change password of current user
- 

## Prompt settings
- `echo $PS1 && oldps1="$PS1"` to get the current prompt setting and save it
- `export PS1="\e[0;34m$oldps1"` to change the prompt color (0;30 black, 0;32 green, 0:34 blue, ...)