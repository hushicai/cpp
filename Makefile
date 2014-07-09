# @file compile cpp source files
# @author hushicai

dir_src = ./src
dir_include = ./include
dir_test = ./test

dir_obj = ./obj
dir_out = ./out

CC = clang++
CFLAGS = -Wall -I$(dir_include)

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

$(dir_obj)/%.o: $(dir_src)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

$(dir_out)/%: $(dir_test)/%.cc $(objs)
	$(CC) $(CFLAGS) $< -o $@ $(objs)

.PHONY: clean setup
setup: 
	mkdir -p $(dir_obj) $(dir_out)

clean: 
	rm -rf $(dir_out) $(dir_obj)

# vim: set ft=make ts=4 sw=4 sts=4 tw=120 fdm=syntax: #
