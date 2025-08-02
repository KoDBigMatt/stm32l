CC=arm-none-eabi-gcc
CFLAGS=-Wall -g -mcpu=cortex-m4 -mthumb -std=c11 -O0
LDSCRIPT=linker_script.ld

OBJS=startup_stm32l4xx.o main.o

all: main.elf

main.elf: $(OBJS)
	$(CC) $(CFLAGS) -T$(LDSCRIPT) -Wl,-Map=output.map -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.elf *.map