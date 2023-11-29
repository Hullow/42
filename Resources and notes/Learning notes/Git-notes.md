# Git pull
- A `pull` is two operations in one:
	- `fetch`
	- `merge ORIGIN\$CURRENT_BRANCH`


# Git checkout vs git switch
- Both change branch, but:
	- `checkout` : more powerful, can **overwrite local changes!!**
	- `switch` : simpler, just switching branches

# Specific how-tos
## [Discard unstaged changes](https://www.baeldung.com/git-discard-unstaged-changes)
- `git clean -df` first, to remove untracked files from the working tree; n.b.: **careful with this command**, can remove untracked files you want to keep that are .gitignored.
	- `-d` to recurse into untracked directories as well
	- `-f` to force deletion of files (necessary if the config clean.requireForce is not set to false)
