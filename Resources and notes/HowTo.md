# How to do various things (dev setups, configs, etc.)

## VS Code debugging
- Watch a pointer value in debug mode: add the three expressions `ptr[i]`, `i`, and `*(char(*)[15])ptr` to follow the `while` loop `while (ptr[i] \= '\0')` to the *Watch* pane so you can see what is being read from memory exactly at a given step
- Inline variable values: go to Settings and set `Debug:inline` to `true`
