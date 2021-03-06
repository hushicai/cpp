# @file compile cpp source files
# @author hushicai

dir_lib = lib
dir_include = include
dir_src = src 
dir_obj = obj
dir_out = out

CC = clang++
CFLAGS = -I$(dir_include)

# 目标文件源代码
libs = $(wildcard $(dir_lib)/*.cc)
# 可执行文件源代码
srcs = $(wildcard $(dir_src)/*.cc)

objs = $(patsubst %.cc, ${dir_obj}/%.o, $(notdir $(libs)))
progs = $(patsubst %.cc, ${dir_out}/%, $(notdir $(srcs)))

all: setup $(objs) $(progs)

.PHONY: clean setup
setup: 
	mkdir -p $(dir_obj) $(dir_out)

clean: 
	rm -rf $(dir_out) $(dir_obj)

# obj
$(dir_obj)/%.o: $(dir_lib)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

$(dir_out)/%: $(dir_src)/%.cc
	$(CC) $(CFLAGS) -o $@ $^

# 自动生成依赖比较麻烦
# 对于有特殊依赖的可执行文件，还是手动配置吧
$(dir_out)/FloatingAsBinary: $(dir_obj)/printBinary.o
$(dir_out)/CLib: $(dir_obj)/CLib.o
$(dir_out)/Mem: $(dir_obj)/Mem.o

# vim: set ft=make ts=4 sw=4 sts=4 tw=120 fdm=syntax: #
