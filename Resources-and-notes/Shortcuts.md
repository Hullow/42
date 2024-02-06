# Useful commands/shortcuts - Bash, Vim, iTerm, OS X

## 42-Intra
- `francinette -c` ou `paco` (a checker) pour nettoyer le cache (cclean)
- `alt + shift + F`: formattage norminette (extension VSCode 42 format)

## OS X
- `Cmd+alt opt+<number>` to select a given window
- `cmd+ctrl+F` : enter/exit fullscreen

## Chrome
- `CMD + !/-/0` to zoom in/out/default

## Firefox
- `CMD + !/-/0` to zoom in/out/default

## iTerm2
- Duplicate tab in iterm2 : create shortcut for `CMD+Shift+T`
- scrolling down with mouse/trackpad: `settings > advanced` > chercher “`scroll`” > Mouse > Scroll wheel sends arrow keys when in alternate screen mode : `Yes` (restart app)

## VS Code
- `Shift + Alt + A` to comment and decomment a block
- `alt opt + arrow` to move a line up or down
- `shift + alt opt + arrow` to duplicate a line
- ``CTRL + ` `` to toggle between editor and terminal
- `ALT + CMD + H` to add 42 header
- `CMD + +`  to zoom in

### Github Copilot
- `tab` : accept a code suggestion
- `esc` : reject all code suggestions
- `Ctrl+Enter` : open a new tab with multiple additional options, press .

## Markdown
- [title of link](#name-of-section-of-link) : to link to different section

### Obsidian
#### Editing
- `cmd + ;` anywhere / `---` at the very beginning of a file (under the title): add properties (aliases, tags, links, ...)
- `[[target-note^section|text]]` : internal link (n.b.: Obsidian, not Markdown specific)
- `Ctrl + D` : delete current line
- `Ctrl + V` : duplicate current line
- `Ctrl + ]`: indent
- `Ctrl + [` : unindent
- `Ctrl + Click` : open Note in Current Panel via Link
- `Ctrl + Shift + Click`: open Note in New Panel via Link
#### Navigation
- `Cmd + home/end`: navigate to beginning/end of note
- `Ctrl + P`: open command pallette
- `Ctrl + O`: opens Quick Switcher
- `Ctrl + E` : toggle edit/preview modes
- `Ctrl + (+Shift) + Tab`: Next (Previous) tab
## Bash
- `CMD+up/down` : next/previous command
- `vim ~/.zsh_history` : see commands of current terminal session
- `reset`: fixes messed up characters for instance.
- `CTRL+A` : go to beginning of command line

**Wildcards**
- `*` for any number of characters
- `?` for a single character (e.g. `???.c`)
- `[]` for a range or a set of characters, e.g. `[a-p0-5].c` for items containing any of the characters between a and p and 0 and 5. Or `[agkj]*.*` 

**Navigation**
- go to previous directory: `cd -`
- `find . -name “<filename>” -delete` : delete all files of a certain name
						`2 > /dev/null` : silent (don’t print out error messages (e.g. “folder not permitted”, "permission denied"))
- `curl -o [filename] [URL]` (nb: `-o` for output): download a file

**File Information**
- `file <filename>` : gives filetype
- `whereis <command>` : shows path to an executable
- `which [command]` => path to executable

**System information**
- `man 7 file-hierarchy`: explain Linux file hierarchy
- `arch`: displays machine's architecture type
- `uname -m`/`machine`: prints the machine hardware name/type

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


