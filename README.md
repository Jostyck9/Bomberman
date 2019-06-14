# MarioBomber
  ![Mario Bomber](https://gunaxin.com/wp-content/uploads/2013/04/Mario-vs-Bomberman.jpg)

  A Bomberman game using the Irrlicht library

## How to compile on Linux

1. Create a **"build"** folder
2. Execute the command : "cd build && cmake .. && make && mv bomberman .. && cd .."

## How to compile on Windows

1. Create a **"build"** folder
2. Execute the command : "cd build && cmake .."
3. Open the the **"bomberman"** | Microsoft Visual Studio Solution
4. Generate **"ALL BUILD"**
5. When it's done, moved the **"bomberman.exe"** from the **"Debug"** folder at the root of the repository
6. From the root of the repository, execute the command : "cp cmake/Modules/Irrklang/IrrKlang.dll ./ && cp cmake/Modules/Irrlicht/Irrlicht.dll ./"

## How to execute

1. Make sure to be at the root of the repository
2. Execute the command : "./bomberman"
