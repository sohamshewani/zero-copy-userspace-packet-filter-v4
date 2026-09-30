# Makefile for zero-copy-userspace-packet-filter project

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
TEST_SRCS = $(wildcard tests/*.c)
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_RUNNER_OBJS = tests/test_runner.o
TEST_RUNNER = tests/test_runner

all: $(OBJS)

clean:
	$(RM) $(OBJS) $(TEST_OBJS) $(TEST_RUNNER)

tests: $(TEST_OBJS) $(TEST_RUNNER)
	./$(TEST_RUNNER)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_RUNNER): $(TEST_RUNNER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^