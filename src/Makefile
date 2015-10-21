INSTALL_PATH = /usr/local/bin/sorting
SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=../obj/%.o)
TARGET = ../bin/sorting
CFLAGS = -std=c99

.PHONY: all dirs clean install uninstall

all: dirs $(TARGET)

dirs:
	@mkdir -p ../obj
	@mkdir -p ../bin

$(TARGET): $(OBJS)
	@echo Linking sorting...
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) && echo sorting successfully linked!

$(OBJS): ../obj/%.o: %.c
	@echo Compiling $<...
	@$(CC) $(CFLAGS) $< -c -o $@

clean:
	@echo Cleaning...
	@rm -f ../obj/*.o $(TARGET) && echo sorting directory successfully cleaned!

install: $(TARGET)
	@echo Installing sorting...
	@cp $(TARGET) $(INSTALL_PATH) && echo sorting successfully installed!

uninstall:
	@echo Uninstalling sorting...
	@rm -f $(INSTALL_PATH) && echo sorting successfully uninstalled!
