CC   := gcc
SRC  := $(shell dir /S /B .\src\*.c)
EXE  := ./bin/panama.exe

LIBS := 
INC  := 
DBG  := # -g
OPS  := # -O2

$(EXE): $(SRC)
	@echo Compiling...
	@$(CC) $^ -o $@ $(LIBS) $(INC) $(DBG) $(OPS)
	@echo Compiled.

.PHONY: clean
clean:
	@echo Cleaning...
	@del /S /Q .\bin\*
	@echo Cleaned.

.PHONY: run
run: $(EXE)
	@$(EXE) $(ARGS)

.PHONY: debug
debug: $(EXE)
	@gdb --args $(EXE) $(ARGS)