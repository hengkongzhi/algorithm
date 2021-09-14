find2halfbin=../bin/704find2half
find2halfsrc=../src/704find2half.cpp

erasebin=../bin/27erase
erasesrc=../src/27erase.cpp

shortarraybin=../bin/209shortarray
shortarraysrc=../src/209shortarray.cpp

luoxuanbin=../bin/59luoxuan
luoxuansrc=../src/59luoxuan.cpp

erasenodebin=../bin/203erasenode
erasenodesrc=../src/203erasenode.cpp

devlistbin=../bin/707devlist
devlistrc=../src/707devlist.cpp

reverlistbin=../bin/206reverlist
reverlistsrc=../src/206reverlist.cpp

target : $(find2halfbin) $(erasebin) $(shortarraybin) $(luoxuanbin) $(erasenodebin) $(devlistbin) $(reverlistbin)
$(find2halfbin) : $(find2halfsrc)
	g++ -std=c++11 -o $(find2halfbin) $(find2halfsrc)

$(erasebin) : $(erasesrc)
	g++ -std=c++11 -o $(erasebin) $(erasesrc)

$(shortarraybin) : $(shortarraysrc)
	g++ -std=c++11 -o $(shortarraybin) $(shortarraysrc)

$(luoxuanbin) : $(luoxuansrc)
	g++ -std=c++11 -g -o $(luoxuanbin) $(luoxuansrc)

$(erasenodebin) : $(erasenodesrc)
	g++ -std=c++11 -g -o $(erasenodebin) $(erasenodesrc)

$(devlistbin) : $(devlistrc)
	g++ -std=c++11 -g -o $(devlistbin) $(devlistrc)

$(reverlistbin) : $(reverlistsrc)
	g++ -std=c++11 -g -o $(reverlistbin) $(reverlistsrc)