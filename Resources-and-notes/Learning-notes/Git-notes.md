# Git pull
- A `pull` is two operations in one:
	- `fetch`
	- `merge ORIGIN\$CURRENT_BRANCH`


# Git checkout vs git switch
- Both change branch, but:
	- `checkout` : more powerful, can **overwrite local changes!!**
	- `switch` : simpler, just switching branches

## Going back on changes
- `Git reset --soft` : reset to previous commit. `--soft`: "Does not touch the index file or the working tree at all (but resets the head to `<commit>`, just like all modes do). This leaves all your changed files "Changes to be committed", as `git status` would put it.""

- `Git rm --cached <file>` : removes files from tree but not local storage (CAUTION)


# How-tos
## [Discard unstaged changes](https://www.baeldung.com/git-discard-unstaged-changes)
- `git clean -df` first, to remove untracked files from the working tree; n.b.: **careful with this command**, can remove untracked files you want to keep that are .gitignored.
	- `-d` to recurse into untracked directories as well
	- `-f` to force deletion of files (necessary if the config clean.requireForce is not set to false)

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

.gitignore:
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
	•	
