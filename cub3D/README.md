# Cub3D
x |Mandatory Part             |  Bonus Part
:-------------------------:|:-------------------------:|:-------------------------:
Screen Capture | ![Image](https://github.com/TimourP/ReadmeFiles/blob/main/Cub3D/capture.png) | ![Image](https://github.com/TimourP/ReadmeFiles/blob/main/Cub3D/bonus_capture.png)
Screen Record |![Image](https://github.com/TimourP/ReadmeFiles/blob/main/Cub3D/record.gif) | ![Image](https://github.com/TimourP/ReadmeFiles/blob/main/Cub3D/bonus_record.gif)
Implementations | Map (file) parsing<br>Raycasting<br>Wall textures<br>Ceiling and floor colors<br>Sprites<br>Image save to bpm format | All mandatory implementations<br>Monsters that follow you<br>More than one different sprite<br>Consomable stuff<br>Life and hunger bar<br>Minimap<br>Sound and musics<br>Sky box<br>Look up/down<br>Mouse control

## Instalation
The graphic rendering of this project is generated thanks to the functions of a graphic library based on OpenGL and called MiniLibX. This library is very difficult to install by yourself because it has many different dependencies. But in case you have installed all the necessary dependencies on your machine, here is how to install and run fractol on your computer.

:warning: **Before cloning this repo, please make sure that there are no files/folders called Cursus19 or cub3D in the destination folder!!** :warning:

If you want to use this library please run:
```
git clone https://github.com/TimourP/Cursus19.git Cursus19 && cp -r Cursus19/cub3D ./ && rm -rf Cursus19
```

## Usage
**In the cub3D repo**, run ```make``` or ```make re``` (```make bonus``` or ```make rebonus``` for the bonus part), it will generate a cub3D executable file. Execute it with ```./cub3D map_path``` and enjoy!

To remove objects files, run ```make clean```

To remove objects files and the cub3D file, run ```make fclean```
