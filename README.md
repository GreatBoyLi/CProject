# CProject
C and C++ code during graduate studies

# VSCode for Windows
.code-workspace:
{
	"folders": [
		{
			"path": "."
		}
	],
	"settings": {"cmake.generator": "MinGW Makefiles"}
}

task.json:
{
	"version": "2.0.0",
	"options": {
		"cwd": "${workspaceFolder}/build/"
	},

	"tasks": [
		{
			"label": "cmake",
			"type": "shell",
			"command": "cmake",
			"args": [
				".."
			]
		},
		{
			"label": "make",
			"group":{
				"kind":"build",
				"isDefault":true
			},
			"command": "mingw32-make.exe",
			"args":[
			]
		},
		{
			"label":"Build my project",
			"dependsOn":[
				"cmake",
				"make"
			]
		}
	]
}

# program、cwd、miDebuggerPath、preLaunchTask 需要改
launch.json:
{
	// Use IntelliSense to learn about possible attributes.	
	// Hover to view descriptions of existing attributes.
	// For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
	"version": "0.2.0",
	"configurations": [
		{
			"name": "(gdb) Launch",
			"type": "cppdbg",
			"request": "launch",
			"program": "${workspaceFolder}/build/main.exe",
			"args": [],
			"stopAtEntry": false,
			"cwd": "C:/TDM-GCC-64/bin",
			"environment": [],
			"externalConsole": false,
			"MIMode": "gdb",
			"miDebuggerPath": "C:/TDM-GCC-64/bin/gdb.exe",
			"setupCommands": [
				{
					"description": "Enable pretty-printing for gdb",
					"text": "-enable-pretty-printing",
					"ignoreFailures": true
				}
			],
			"preLaunchTask": "Build my project"
		}
	]
}

# CMake
CMakelists.txt:
project(AES)
aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)
add_executable(main ${SRC_SUB} ${SRC_CUR})
include_directories(header)



# 命令行
cd build

cmake ..

# Windows 环境 获得.exe文件可运行文件
mingw32-make.exe   
chcp 65001 设置cmd为UTF-8编码

# macOS 获得可运行文件
make

# VSCode for MacOS
tasks.json:
{
	"version": "2.0.0",
	"options": {
		"cwd": "${workspaceFolder}/build/"
	},
	
	"tasks": [
		{
			"label": "cmake",
			"type": "shell",
			"command": "cmake",
			"args": [
				".."
			]
		},
		{
			"label": "make",
			"group":{
				"kind":"build",
				"isDefault":true
			},
			"command": "make",
			"args":[
			]
		},
		{
			"label":"Build my project",
			"dependsOn":[
				"cmake",
				"make"
			]
		}
	]
}

launch.json:
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(lldb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/AES_main",
            "args": [],
            "stopAtEntry": false,
            "cwd": "/usr/bin",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb",
            "preLaunchTask": "Build my project"
        }

    ]
}



# VSCode 若Debug时想看一个动态数组中的元素值，那么可使用下面方法
在WATCH中添加  **dp@2@4   这是一个名为dp的二维数组有 4行 2列    二维数组好像不行
               *dp@4     这是一个名yldp的一维数组有 4个元素	   一维数组是可以的