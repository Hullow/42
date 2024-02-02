# Notes on tools
Theory and practice (how-to)

## VS Code
### [Debugging](https://code.visualstudio.com/docs/editor/debugging)
- **Launch** versus **Attach** configurations: two core debugging modes
  - **Launch** starts the app or process in debug mode before VS Code attaches to it
  - **Attach** connects VS Code's debugger to an app or process that's already running

### Show indentation:
- add `"editor.renderWhitespace": "all",` in settings.json (note: did so in ~/.vscode)

## Github
**Private repos and subscriptions**
Each personal account uses either GitHub Free or GitHub Pro. All personal accounts can own an unlimited number of public and private repositories, with an unlimited number of collaborators on those repositories. If you use GitHub Free, private repositories owned by your personal account have a limited feature set. You can upgrade to GitHub Pro to get a full feature set for private repositories. For more information, see "GitHub’s plans."

# How-to's (dev setups, configs, etc.)
## VS Code debugging

^2eedcc

- Watch a pointer value in debug mode: add the three expressions `ptr[i]`, `i`, and `*(char(*)[15])ptr` to follow the `while` loop `while (ptr[i] \= '\0')` to the *Watch* pane so you can see what is being read from memory exactly at a given step
- Inline variable values: go to Settings and set `Debug:inline` to `true`
- Open `settings.json`: Go to `Settings` and click on the document icon top-right to switch to `.json` view
- 