# Actividad 4.2
##### José Pablo Naime García - A01367610
##### Andrés Alejandro Guzmán González - A01633819
## Antes de empezar
Este programa requiere de la libreria [CGAL](https://www.cgal.org/), [SLD2](https://www.libsdl.org/) para su 
funcionamiento (esta libreria nos ayuda a integrar [opengl](https://www.opengl.org/) de una
forma más sencilla, para asi poder crear ventanas y dibujar en ellas). Al igual que hace uso de [CMake](https://cmake.org/) para tener un 
control de compilación más sencillo.

Los archivos de las libreria ya se encuentran en el mismo proyecto dentro de la carpeta ```/include``` y ```/lib```,
por lo que no es necesario descargarlos. 

> En este caso, ya se cuenta con un ejecutable para macOS, por lo que no es necesario realizar el proceso de compilacion (solo realizar en caso de modificar el codigo).

## Video de Ejecución
[![Video](https://img.youtube.com/vi/Hl0dBQBJbi8/0.jpg)](https://www.youtube.com/watch?v=Hl0dBQBJbi8)

## Compilación
Para compilar el programa se debe ejecutar el siguiente comando en la terminal:
````bash
cmake .
make
````

Generara un archivo ejecutable llamado ```exec```.

## Ejecución
Para ejecutar el programa se debe ejecutar el siguiente comando en la terminal:
```bash
./exec < [archivo de entrada]
```

Para probar con nuestro archivos de entrada, se puede ejecutar el siguiente comando:
```bash
./exec < ./inputs/test_1.txt
```