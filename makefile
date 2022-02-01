#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT= Unity

CFLAGS := -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
#CFLAGS += -Wno-misleading-indentation

TARGET_BASE=test
RELEASE_BASE=out

TARGET := $(TARGET_BASE)$(TARGET_EXTENSION)
RELEASE:= ${RELEASE_BASE}$(TARGET_EXTENSION)
SRC_FILES=$(UNITY_ROOT)/src/unity.c src/code.c test/test_code.c test/test_runners/test_code_runner.c
PROG_FILES= src/main.c src/code.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src

all: clean test

build: $(SRC_FILES) $(SRC_FILES2)
	@echo Building...
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(PROG_FILES) -o $(RELEASE)
	@- ./$(RELEASE)


test: $(SRC_FILES) $(SRC_FILES2)
	echo Testing...
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRC_FILES) -o $(TARGET)
	- ./$(TARGET)

test/test_runners/test_code_runner.c: test/test_code.c
	@ruby $(UNITY_ROOT)/auto/generate_test_runner.rb test/test_code.c test/test_runners/test_code_runner.c

clean:
	@echo cleaning...
	@$(CLEANUP) *${TARGET_EXTENSION}