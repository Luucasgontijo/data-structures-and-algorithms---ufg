## Requisitos
- Compilador C (GCC recomendado)
- Bibliotecas padrão C

## Compilação

### Usando Make (recomendado)
```bash
make
```

### Sem Make (compilação manual)
```bash
mkdir -p bin
gcc -Wall -g -I./include ./src/avl_dictionary.c ./src/main.c ./src/memory_utils.c ./src/utils.c -o ./bin/dictionary_avl
```


## Executando a Aplicação
Após a compilação, execute o programa:
```bash
./bin/dictionary_avl
```

## Adicional: executar com compile_and_run.bat

Para WindowsOS, abra o arquivo .bat no diretório raiz.

## Adicional: executar com docker

#### Passo 1: Construir a imagem Docker
No seu terminal, navegue até o diretório do projeto e execute:
```bash
docker build -t dictionary-avl .
```
Isso constrói a imagem contida no Dockerfile

### Passo 3: Executar o contêiner
```bash
docker run -it dictionary-avl
```
As flags -it garantem que você tenha uma sessão de terminal interativa, o que é necessário para o programa aceitar a entrada do usuário.