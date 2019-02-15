#!/bin/bash
echo "Compilo ejemplo.c y el programa de salida se llamará ejemplo:"
echo "gcc ejemplo.c -o ejemplo"
echo ""
gcc ejemplo1.c -o ejemplo1
ls --color
echo ""
echo "Ejecuto el programa y muestro un mensaje dependiendo de si se ejecutó bien o no:"
echo "./ejemplo1 && echo \"El programa terminó correctamente.\" || echo \"El programa experimentó un error.\""
./ejemplo1 && echo "El programa terminó correctamente." || echo "El programa experimentó un error."
echo ""
echo "Ahora prueba a cambiar el valor devuelto en ejemplo1.c y vuelve a ejecutar este comando para ver si cambia el resultado."
