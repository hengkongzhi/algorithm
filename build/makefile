src=$(shell find ../src/ -type f -name "*.cpp" | xargs -i basename {} | tr "\n" " ")
rebin=$(addprefix ../bin/,$(basename $(src)))
define func
$(1):$(2)
	@g++ -std=c++11 -g $(2) -o $(1)
	@echo [COMPILE]$(notdir $(1)) SUCCESS
endef
target0 : $(rebin)
$(foreach var,$(src),$(eval $(call func,$(addprefix ../bin/,$(basename $(var))),$(addprefix ../src/,$(var)))))
