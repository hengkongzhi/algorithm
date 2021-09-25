src=704find2half.cpp 27erase.cpp 209shortarray.cpp 59luoxuan.cpp 203erasenode.cpp 707devlist.cpp 206reverlist.cpp \
19eraserevern.cpp 142circlelist.cpp 242strsame.cpp 349arrand.cpp 202happynum.cpp 1arrtwonumand.cpp 454num4sum.cpp \
383canconstruct.cpp 15threenumsadd.cpp 18foursum.cpp
rebin=$(addprefix ../bin/,$(basename $(src)))
define func
$(1):$(2)
	@g++ -std=c++11 -g $(2) -o $(1)
	@echo [COMPILE]$(notdir $(1)) SUCCESS
endef
target0 : $(rebin)
$(foreach var,$(src),$(eval $(call func,$(addprefix ../bin/,$(basename $(var))),$(addprefix ../src/,$(var)))))
