# Interactive Shell Customisation
export CLICOLOR=1
fpath+=~/.zfunc
autoload -Uz compinit && compinit

## Git
autoload -Uz vcs_info
precmd() { vcs_info }

# Set up the prompt (with git branch name)
setopt PROMPT_SUBST
PROMPT='%F{cyan}%1~${vcs_info_msg_0_}%f $ '

# Aliases
alias d="mkdir"
alias g="gcc -Wall -Wextra -Werror"
alias o="./a.out"
alias mini='~/mini-moulinette/mini-moul.sh'
alias l='ls -la'
alias n="norminette"

alias francinette="/Users/francis/francinette/tester.sh -in"
alias paco="/Users/francis/francinette/tester.sh -in"
alias gl="gcc -Wall -Wextra -Werror -L. -lft"