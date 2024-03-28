# Commands pêle-mêle

- stop tracking a file: `git rm --cached <file> && git commit` (CAUTION)
- stage unstaged changes (but not changes to untracked files): `git add -u` 
- stage all changes (modified, deleted, and new files) to the entire repository: `git add -A`
- stages new and modified files, but not deleted ones, and only in the current directory and its subdirectories : `git add .`

## Git commit
- automatically stage files that have been modified and deleted, but new files you have not told Git about are not affected: `-a`/ `--all`

## Display information
- Show files changed by a commit: `git diff-tree --no-commit-id --name-only <commit-id> -r`
- Show changes of a commit: `git show <commit-id>`
- Show changes since last commit : `git diff`
- Show changes of multiple previous commits (incl. size of changes): `git log --stat`
- Show tracked files: `git ls-tree -r main --name-only`
- Show HEAD commit ID: `git rev-parse HEAD`
- `git log` :
	- [Find when a term existed or was introduced, by commit](https://git-scm.com/book/en/v2/Git-Tools-Searching#:~:text=Simply%20run%20git%20log%20with,%2DL%20%3Agit_deflate_bound%3Azlib.): `git log -S <term> --since=2024-01-01 --oneline
	- show the content of commits since with a certain name introducing a certain term since a certain date: `git show $(git log -S <term> --since=2024-01-01 --oneline | grep <name> | awk '{print $1}')`
- Show a file's state n commits before the last commit: `git show HEAD~n:relative/path/to/file` (e.g. `get_next_line/get_next_line.c`)
- View the whole git folder in a previous commit stage: `git checkout HEAD~n` (`git checkout main/master` to go back)

# Git pull
- A `pull` is two operations in one:
	- `fetch`
	- `merge ORIGIN\$CURRENT_BRANCH`


# Git checkout vs git switch
- Both change branch, but:
	- `checkout` : more powerful, can **overwrite local changes!!**
	- `switch` : simpler, just switching branches

## Going back on changes
- `Git restore <file>` : restore the contents of currently tracked but unstaged <files> to their state at the last commit
- `Git reset --soft` : reset to previous commit. `--soft`: "Does not touch the index file or the working tree at all (but resets the head to `<commit>`, just like all modes do). This leaves all your changed files "Changes to be committed", as `git status` would put it.""

- `Git rm --cached <file>` : removes files from tree but not local storage (CAUTION)

## [Rebasing](https://git-scm.com/book/en/v2/Git-Branching-Rebasing)

### How it works
- goes to the common ancestor of the two branches
- gets the diff introduced by each commit on the current branch
- saves those diffs to temporary files
- resets the current branch to the same commit as the branch we are rebasing to
- applies each change in turn
### Why rebase ?
To get a cleaner history (e.g. for collaboration, contribute a single branch to a remote to enable easier integration)
### Caution when collaborating
**Do not rebase commits that exist outside your repository and that people may have based work on**: “If you push commits somewhere and others pull them down and base work on them, and then you rewrite those commits with git rebase and push them up again, your collaborators will have to re-merge their work and things will get messy when you try to pull their work back into yours.”

# [.gitignore syntax](https://git-scm.com/docs/gitignore)
- `/directory` is the same as `directory`
- `directory/**`: directory and all subdirectories and files

	•	The slash / is used as the directory separator. Separators may occur at the beginning, middle or end of the .gitignore search pattern.
	•	If there is a separator at the beginning or middle (or both) of the pattern, then the pattern is relative to the directory level of the particular .gitignore file itself. Otherwise the pattern may also match at any level below the .gitignore level.
	•	If there is a separator at the end of the pattern then the pattern will only match directories, otherwise the pattern can match both files and directories.
	•	
	•	For example, a pattern doc/frotz/ matches doc/frotz directory, but not a/doc/frotz directory; however frotz/ matches frotz and a/frotz that is a directory (all paths are relative from the .gitignore file).

	•	An asterisk "*" matches anything except a slash. The character "?" matches any one character except "/"

	•	Two consecutive asterisks ("**") in patterns matched against full pathname may have special meaning:
	⁃	A leading "**" followed by a slash means match in all directories. For example, "**/foo" matches file or directory "foo" anywhere, the same as pattern "foo". "**/foo/bar" matches file or directory "bar" anywhere that is directly under directory "foo".
	⁃	A trailing "/**" matches everything inside. For example, "abc/**" matches all files inside directory "abc", relative to the location of the .gitignore file, with infinite depth.
	⁃	A slash followed by two consecutive asterisks then a slash matches zero or more directories. For example, "a/**/b" matches "a/b", "a/x/b", "a/x/y/b" and so on.

# How-tos
## [Discard unstaged changes](https://www.baeldung.com/git-discard-unstaged-changes)
- `git clean -df` first, to remove untracked files from the working tree; n.b.: **careful with this command**, can remove untracked files you want to keep that are .gitignored.
	- `-d` to recurse into untracked directories as well
	- `-f` to force deletion of files (necessary if the config clean.requireForce is not set to false)
https://www.git-tower.com/learn/git/faq/restoring-deleted-files
## [Retrieve deleted files](https://www.git-tower.com/learn/git/faq/restoring-deleted-files)
- Retrieve deletion commit: `git log -- <file>`
- If deletion committed and pushed : `git revert --no-commit <commit-id>` then select changes to commit (i.e. files to undelete), commit them, push.





***To order***:

https://theweek.com/articles/889613/tribute-pushmipullyu

Commands 
- Get the URL of the remote repository : git remote get-url origin
- Info about all remotes : git remote -v
- Change commit message of last commit. If only local: git commit --amend
-

- Stop Github from asking for your passphrase all the time (Stack Overflow): 
eval `ssh-agent -s`
`ssh-add ~/.ssh/*_rsa`
- change remote: git remote rm origin && git remote add origin <URL_in_appropriate_format_(eg_SSH)>

- 



Règles pour les rendus (école 42):
Quand on travaille a plusieurs: git pull (SEE DOC)

NB: ne pas dépasser 100MB sur le serveur +> abus de ressources, sanctionne !!

Temps de rendu: ce qui compte c’est le debut de la connection: ne pas la couper peut rendre 5min après delai si on a commence avant


Authentication: avec ticket Kerberos, qui expire. Commandes: klist (kdestroy), k init => create new one
