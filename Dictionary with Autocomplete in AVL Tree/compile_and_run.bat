@echo off
echo Compilando o projeto...

if not exist bin mkdir bin

gcc -Wall -g -I./include ./src/avl_dictionary.c ./src/main.c ./src/memory_utils.c ./src/utils.c -o ./bin/dictionary_avl

if %ERRORLEVEL% EQU 0 (
    echo Compilação bem-sucedida! Executando o programa...
    bin\dictionary_avl.exe
) else (
    echo Falha na compilação.
)

pause