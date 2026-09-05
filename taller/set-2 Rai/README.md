# Talleres 2026-2: Set de práctica 2

## Instrucciones

Puedes encontrar el enunciado de este set en la raíz de este repositorio como `enunciado.pdf`. Abajo dejamos
un resumen con comandos útiles. Mucho éxito!

## Comandos

Para compilar el programa:
```bash
make
```

Para limpiar el output de compilación (ejecutable, archivos object, etc):
```bash
make clean
```

Para correr un test:
```bash
./set-2 INPUT_PATH OUTPUT_PATH
```
donde `INPUT_PATH` es la ruta al archivo de input del test, y `OUTPUT_PATH` es la ruta al archivo para el output del programa con dicho
test. Por ejemplo: `./set-2 tests/easy-1/input.txt output.txt`

Para revisar si un test pasó:
```bash
diff PROGRAM_OUTPUT_PATH EXPECTED_OUTPUT_PATH
```
donde `EXPECTED_OUTPUT_PATH` es la ruta al archivo de output esperado del test, y `PROGRAM_OUTPUT_PATH` es la ruta al archivo de output que el programa generó para dicho test. Por ejemplo: `diff output.txt tests/easy-1/output.txt`. El comando `diff` sirve para ver la diferencia entre dos archivos, con lo que:

1) Si los archivos son iguales (el test pasa): No se mostrará ningún output en consola (no hay diferencia)

2) Si los archivos **no** son iguales (el test falla): Se mostrará la diferencia entre el output esperado y el output generado.

Ya que se entrega el archivo generado por el programa primero, si hay diferencias, `diff` mostrará primero en rojo lo que está en el archivo generado y luego en verde lo que está en el archivo de output esperado.

Para revisar leaks/errores de memoria:
```bash
valgrind ./set-2 INPUT_PATH OUTPUT_PATH
```

Para correr todos los tests:
```bash
make test
```
