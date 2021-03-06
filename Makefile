P_NAME += 4.3-39

CFLAGS += -Wall

COMPIL += P:/Coder_experiments/$(P_NAME)/src/

COMPONETS += $(MY_INCLUDE)fwlist/fwlist.c

MY_INCLUDE	= P:/Coder_experiments/include/
INCLUDE		= -IP:/Coder_experiments/include/

CREATIN_B += P:/Coder_experiments/$(P_NAME)/bin/
CREATIN_D += P:/Coder_experiments/$(P_NAME)/debug/

DIR = D:/mingv/mingw64/bin/

RM = RMDIR /S /Q

all:
	if exist "bin" make clean_b
	md bin
	gcc.exe $(COMPIL)$(P_NAME).c $(COMPONETS) $(INCLUDE) -o $(CREATIN_B)$(P_NAME).exe $(CFLAGS)

clean_d:
	if exist "debug" $(RM) debug

clean_b:
	if exist "bin" $(RM) bin

clean: clean_b clean_d

.PHONY: debug

debug:
	if exist "debug" make clean_d
	md debug
	gcc.exe -ggdb $(COMPIL)$(P_NAME).c $(COMPONETS) $(INCLUDE) -o $(CREATIN_D)$(P_NAME).exe $(CFLAGS)