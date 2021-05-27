# Fractol
Fractol is a 2d representation of a mathematical object called a fractal. These objects are constructed so that they can be observed at any scale. In other words you can zoom in and out of a fractal while still discovering new details.

One of the most famous fractal set, the Julia set ( represented below with **C = 0.288 + 0.01i** ) is obtained by analyzing for each point of the screen ( the x-position representing the real part and the y-position representing the imaginary part of the complex number Z ) the behavior of the sequence Z<sub>n+1</sub> = Z² + C.

![Image](https://github.com/TimourP/ReadmeFiles/blob/main/Fractol/main_julia.png)

## Instalation
The graphic rendering of this project is generated thanks to the functions of a graphic library based on OpenGL and called MiniLibX. This library is very difficult to install by yourself because it has many different dependencies. But in case you have installed all the necessary dependencies on your machine, here is how to install and run fractol on your computer.

:warning: **Before cloning this repo, please make sure that there are no files/folders called Cursus19 or fractol in the destination folder!!** :warning:

If you want to use this library please run:
```
git clone https://github.com/TimourP/Cursus19.git Cursus19 && cp -r Cursus19/fractol ./ && rm -rf Cursus19
```
## Usage
**In the fractol repo**, run ```make``` or ```make re``` (```make bonus``` or ```make rebonus``` for the bonus part), it will generate a fractol executable file.
Execute it with ```./fractol fractal_name``` and enjoy!

To remove objects files, run ```make clean```

To remove objects files and the libftprintf.a file, run ```make fclean```
