# source
TARGET = main
SRCS = main.cpp
HEDS = $(SRCS:.cpp=.h)
OBJDIR = ./build
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

# micro controller
AVR_CHIP = attiny2313
F_CPU = 1000000UL

# compiler
CC = avr-gcc
CFLAGS = -Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(AVR_CHIP)

# command
RM = rm

# generate *.hex
$(OBJDIR)/$(TARGET).hex: $(OBJDIR)/$(SRCS)
	$(CC) $(CFLAGS) $(OBJDIR)/$(SRCS) -o $(OBJDIR)/$(TARGET)
	avr-objcopy -F ihex $(OBJDIR)/$(TARGET) $(OBJDIR)/$(TARGET).hex

# generate ./out/*.o
$(OBJDIR)/%.o: %.cpp $(HEDS)
	@[ -d $(OBJDIR) ]
	$(CC) $(CFLAGS) -c $< -o $@

# write *.hex
write: $(OBJDIR)/$(TARGET).hex
	avrdude -c avrisp -P COM7 -b 19200 -p $(AVR_CHIP) -e -U flash:w:$(OBJDIR)/$(TARGET).hex

# clean ./out/*.hex ./out/*.o
.PHONY: clean
clean:
	$(RM) $(OBJDIR)/$(TARGET).o
	$(RM) $(OBJDIR)/$(TARGET) $(OBJDIR)/$(TARGET).hex
