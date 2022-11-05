# Actividad 4.1
##### José Pablo Naime García - A01367610
##### Andrés Alejandro Guzmán González - A01633819
### Antes de empezar
Este programa requiere de la libreria [SLD2](https://www.libsdl.org/) para su funcionamiento (esta libreria nos 
ayuda a integrar [opengl](https://www.opengl.org/) de una 
forma más sencilla, para asi poder crear ventanas y dibujar en ellas).

Los archivos de la libreria ya se encuentran en el mismo proyecto dentro de la carpeta ```/include``` y ```/lib```, 
por lo que no es necesario descargarlos.

> En este caso, ya se cuenta con un ejecutable tanto para Windows como para Linux, por lo que no es necesario 
> realizar el proceso de compilacion (solo realizar en caso de modificar el codigo).

### Compilación
Para compilar el programa se debe ejecutar el siguiente comando en la terminal:

En caso de contar con make instalado:
```bash
make build
```
En caso de NO contar con make instalado:
```bash
g++ -std=c++11 main.cpp -o exec -I include -L lib -l SDL2-2.0.0
```

Generara un archivo ejecutable llamado ```exec```.

### Ejecución
Para ejecutar el programa se debe ejecutar el siguiente comando en la terminal:
```bash
./exec < [archivo de entrada]
```

Para probar con nuestro archivos de entrada, se puede ejecutar el siguiente comando:

En caso de contar con make instalado:
```bash
make run_test-1
```
En caso de NO contar con make instalado:
```bash
./exec < ./inputs/test_1.txt
```



