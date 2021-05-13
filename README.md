# miniRT
The beautiful world of Raytracing.

When it comes to rendering 3 dimensional computer generated images there are 2 possible approaches: “Rasterization”, which is used by almost all graphic engines because of it’s efficiency and “Ray Tracing.”

The “Ray Tracing” method, developed for the first time in 1968 (but improved upon since) is even today more expensive in computation than the “Rasterization” method.

As a result it is not well adapted to real time usecases but it produces a much higher degree of visual realism.

This project done for MAC's and Linux ...

Compiling the program :

$ make

Executing the program :

./miniRT scenes/<files.rt>

Create BMP image :

./miniRT scenes/<files.rt> --save

- <a href="https://github.com/42Paris/minilibx-linux">42paris</a>

- <a href="https://harm-smits.github.io/42docs/libs/minilibx">Tutorial</a>

- <a href="https://raytracing.github.io/books/RayTracingInOneWeekend.html">RT in one week by Peter Shirley</a>

<h2>Just simples example of Raytring</h2>

<img scenes="all_objs.bmp">

