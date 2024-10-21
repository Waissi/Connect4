# CONNECT 4 - A Game Classic

This game was made of out of curiosity for [Raylib](https://www.raylib.com/), and the desire to build a small game in C in the simpliest manner.  

# Build
This project uses the [Zig build system](https://ziglang.org/learn/build-system/) but alternatives are possible, see [instructions for Raylib](https://github.com/raysan5/raylib?tab=readme-ov-file#build-and-installation). 

First, init the git submodule
````
git submodule update --init --recursive
````
Then you can compile raylib using the build.zig file in the raylib folder
````
cd deps/raylib
zig build
```` 

The .vscode folder is configured for building, running and deguging the game using the Zig build system in VSCode.  

You can also manually build it with
````
zig build
````
Then run it with
````
zig-out/bin/Connect4
````

Enjoy!  
![screenshot](https://github.com/Waissi/Connect4-game-classic/blob/94ff2414398734323a024e858772bcfd20b93175/Screenshot.png)
