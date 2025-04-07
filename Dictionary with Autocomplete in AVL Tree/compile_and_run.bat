@echo off
echo Compilando o projeto...

if not exist bin mkdir bin

gcc -Wall -g -Isrc src\avl_dictionary.c src\main.c src\utils.c src\module1.c -o bin\dictionary_avl.exe

if %ERRORLEVEL% EQU 0 (
    echo Compilação bem-sucedida! Executando o programa...
    bin\dictionary_avl.exe
) else (
    echo Falha na compilação.
)

pause