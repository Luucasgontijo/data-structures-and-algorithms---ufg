FROM gcc:latest

WORKDIR /app

# Copy all project files
COPY . .

# Create necessary directories
RUN mkdir -p bin obj

# Compile the project
RUN gcc -Wall -g -I./include ./src/avl_dictionary.c ./src/main.c ./src/memory_utils.c ./src/utils.c -o ./bin/dictionary_avl

# Set the entrypoint
CMD ["./bin/dictionary_avl"]