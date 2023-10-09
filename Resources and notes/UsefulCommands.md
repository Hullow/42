# Useful commands - Bash, Vim, Git

## Bash
- `CMD+up/down` : next/previous command
- see commands of current terminal session: `vim ~/.zsh_history`
- `reset`: fixes messed up characters for instance.
- go to beginning of command line: `CTRL+A`

**Navigation**
- go to previous directory: `cd -`
- `find . -name “<filename>” -delete` : delete all files of a certain name
						`2 > /dev/null` : don’t print out error messages (e.g. “folder not permitted”)
- download a file: `curl -o [filename] [URL]` (nb: `-o` for output)

**Information**
- `file <filename>` : gives filetype
- `whereis <command>` : shows path to an executable
- `which [command]` => path to executable

**Users/groups**
- `whoami`: gives current user
- `id`: information about specified user and its groups
- `groups`: lists all groups one is a member of

**File manipulation**
- `mv -v <origin folder>/* <destination folder>` : move all files and folders from a folder to another
- `rm -r <directory> <destination folder>`
- `cp -r [directory]` (recursive)
- write contents of variable to a file: `echo "$my_var" > file.log`
- copy contents of a file to the clipboard (“pasteboard”): `cat file.txt | pbcopy`
- Calculate and store value of numerical expressions in a variable : `var=$((expression))`
- make directories ex00->ex08: `mkdir ex0{0..8}`

**Settings**
- make prompt shorter: `PROMPT=“%~ “`

## Vim

## Git
