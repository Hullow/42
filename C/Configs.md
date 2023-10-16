# Configurations
To centralize various configurations regarding C programming

## VS Code
### [Debugging](https://www.youtube.com/watch?v=G9gnSGKYIg4)
- C on OS X – *Launch.json*:
`{
	"version": "0.2.0",
	"configurations": [
	{
		"name": "(lldb) Launch",
		"type": "cppdbg",
		"request": "launch",
		"program": "${workspaceFolder}/a.out",
		"args": [],
		"stopAtEntry": true,
		"cwd": "${fileDirname}",
		"environment": [],
		"externalConsole": false,
		"MIMode": "lldb"
	}
	]
}`
