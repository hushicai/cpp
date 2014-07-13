# @file compile cpp source files
# @author hushicai

dir_src = src
dir_include = include
dir_test = test

dir_obj = obj
dir_out = out

CC = clang++
CFLAGS = -I$(dir_include)

# 目标文件源代码
srcs = $(wildcard $(dir_src)/*.cc)
# 可执行文件源代码
tests = $(wildcard $(dir_test)/*.cc)

objs = $(patsubst %.cc, ${dir_obj}/%.o, $(notdir $(srcs)))
progs = $(patsubst %.cc, ${dir_out}/%, $(notdir $(tests)))

all: $(objs) $(progs)
	@echo "done"

$(objs): | setup

$(progs): | setup

.PHONY: clean setup
setup: 
	mkdir -p $(dir_obj) $(dir_out)

clean: 
	rm -rf $(dir_out) $(dir_obj)

########## rules
$(dir_obj)/%.o: $(dir_src)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

$(dir_out)/ArrayAddress: $(dir_test)/ArrayAddress.cc
	$(CC) $(CFLAGS) $< -o $@

$(dir_out)/FunctionTable: $(dir_test)/FunctionTable.cc
	$(CC) $(CFLAGS) $< -o $@

$(dir_out)/sizeof: $(dir_test)/sizeof.cc
	$(CC) $(CFLAGS) $< -o $@

$(dir_out)/test: $(dir_test)/test.cc
	$(CC) $(CFLAGS) $< -o $@

$(dir_out)/FloatingAsBinary: $(dir_test)/FloatingAsBinary.cc $(dir_obj)/printBinary.o
	$(CC) $(CFLAGS) $< -o $@ $(dir_obj)/printBinary.o

$(dir_out)/CLib: $(dir_test)/Clib.cc $(dir_obj)/CLib.o
	$(CC) $(CFLAGS) $< -o $@ $(dir_obj)/CLib.o

# vim: set ft=make ts=4 sw=4 sts=4 tw=120 fdm=syntax: #
