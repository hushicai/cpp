# @file compile cpp source files
# @author hushicai

dir_src = src
dir_include = include
dir_test = test
dir_dep = dep
dir_obj = obj
dir_out = out

CC = clang++
CFLAGS = -I$(dir_include)
LDFLAGS = 

# 目标文件源代码
srcs = $(wildcard $(dir_src)/*.cc)
# 可执行文件源代码
tests = $(wildcard $(dir_test)/*.cc)

deps = $(patsubst %.cc, ${dir_dep}/%.d, $(notdir $(tests)))
objs = $(patsubst %.cc, ${dir_obj}/%.o, $(notdir $(srcs)))
progs = $(patsubst %.cc, ${dir_out}/%, $(notdir $(tests)))

all: $(objs) $(progs)

$(objs) : | mkObj

$(progs) : | mkOut

.PHONY: clean  mkOut mkObj

mkOut:
	mkdir -p $(dir_out)

mkObj:
	mkdir -p $(dir_obj)

clean: 
	rm -rf $(dir_out) $(dir_obj) 

# obj
$(dir_obj)/%.o: $(dir_src)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

$(dir_out)/%: $(dir_test)/%.cc
	$(CC) $(CFLAGS) -o $@ $^

# 自动生成依赖
$(dir_dep)/%.d : $(dir_test)/%.cc
	@set -e; \
	rm -f $@; \
	$(CC) -MM $< > $@.$$$$ $(CFLAGS); \
	sed  -e's,\($*\)\.o[ :]*,$(dir_out)\/\1 $@: ,g' \
		 -e 's,include\/\(.*\)\.h,$(dir_obj)\/\1\.o,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(deps)

# vim: set ft=make ts=4 sw=4 sts=4 tw=120 fdm=syntax: #
