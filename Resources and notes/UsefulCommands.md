# Useful commands/shortcuts - Bash, Vim, iTerm, OS X

## OS X
- `Cmd+alt opt+<number>` to select a given window
- `cmd+ctrl+F` : enter/exit fullscreen

## iTerm2
- Duplicate tab in iterm2 : create shortcut for `CMD+Shift+T`
- scrolling down with mouse/trackpad: `settings > advanced` > chercher “`scroll`” > Mouse > Scroll wheel sends arrow keys when in alternate screen mode : `Yes` (restart app)

## VS Code
- `Shift + Alt + A` to comment and decomment a block
- `alt opt + arrow` to move a line up or down
- `shift + alt opt + arrow` to duplicate a line
- ``CTRL + ` `` to toggle between editor and terminal
- `ALT + CMD + H` to add 42 header

## Bash
- `CMD+up/down` : next/previous command
- `vim ~/.zsh_history` : see commands of current terminal session
- `reset`: fixes messed up characters for instance.
- `CTRL+A` : go to beginning of command line

**Navigation**
- go to previous directory: `cd -`
- `find . -name “<filename>” -delete` : delete all files of a certain name
						`2 > /dev/null` : don’t print out error messages (e.g. “folder not permitted”)
- `curl -o [filename] [URL]` (nb: `-o` for output): download a file

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
- `let @*=@"` copy contents from unnamed register (from yank) to clipboard

**navigation and edit mode**
gg to go to top of file
G to end of file
M to go to middle of file
O or o to insert a line above/below and go to insert mode
search: / then n or N to go to the next or previous occurrence

**modifying text**
- substitute: `:%s/old/new` => % for all lines
- delete:
	- range of lines: `:[start],[end]d`
	- beginning/rest of line up to cursor: `d0/d$`

`:[line]co [destination line]`. Or just `:co [destination line]` to  ????


**settings**

to disable a setting: `set no[command]`, e.g. `set noline`
- `:syntax enable / syntax off`
- `:set` :
	- `number` (to see line numbers)
	- `cursorline`

**File handling**
- `:saveas [newname]` : rename
