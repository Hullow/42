## Z Jump
source ~/.zplugin/zsh-z.plugin.zsh

# Nicer completion menu
zstyle ':completion:*' menu select

# Interactive Shell Customisation
export CLICOLOR=1
fpath+=~/.zfunc
autoload -Uz compinit && compinit

## Git
autoload -Uz vcs_info
precmd() { vcs_info }

# Format the vcs_info_msg_0_ variable
zstyle ':vcs_info:git:*' formats ' %F{yellow}(git:%F{red}%b%F{yellow})'
zstyle ':vcs_info:svn:*' formats ' %F{yellow}(svn:%F{red}%b%F{yellow})'

# Set up the prompt (with git branch name)
setopt PROMPT_SUBST
PROMPT='%F{cyan}%1~${vcs_info_msg_0_}%f $ '

# Search in history with up and down key
autoload -U history-search-end
zle -N history-beginning-search-backward-end history-search-end
zle -N history-beginning-search-forward-end history-search-end
bindkey "^[[A" history-beginning-search-backward-end
bindkey "^[[B" history-beginning-search-forward-end

# Created by `pipx` on 2023-04-24 22:24:32
export PATH="$PATH:/Users/francis/Library/Python/3.10/bin"

# Created by `pipx` on 2023-04-24 22:24:33
export PATH="$PATH:/Users/francis/.local/bin"

# Aliases
alias d="mkdir"
alias g="gcc -Wall -Wextra -Werror"
alias o="./a.out"
alias mini='~/mini-moulinette/mini-moul.sh'
alias l='ls -la'
