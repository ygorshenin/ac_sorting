BINDIR=bin
OBJDIR=obj
SRCDIR=src
OBJS=$(addprefix $(OBJDIR)/,sort.o insertion_sort.o merge_sort.o \
	quick_sort.o std_qsort.o io.o)
PROGRAM=$(addprefix $(BINDIR)/,sort)

G++=g++
GCC=gcc
CFLAGS=-O2 -Wall -I$(SRCDIR)

all: bin_dir obj_dir $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(GCC) -o $@ $(OBJS)

bin_dir:
	mkdir -p $(BINDIR)

obj_dir:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(GCC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BINDIR) $(OBJDIR)
