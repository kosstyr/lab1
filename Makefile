# Компилятор и флаги компиляции
CC = gcc
CFLAGS = -Wall -I./src

# Директории
SRC_DIR = src
BIN_DIR = bin

# Имя исполняемого файла
TARGET = $(BIN_DIR)/lab1

# Исходные и объектные файлы
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

# Цель по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Сборка объектных файлов
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Создание директории bin, если её нет
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Фиктивные цели
clean:
	rm -f $(BIN_DIR)/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
