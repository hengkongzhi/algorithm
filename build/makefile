find2halfbin=../bin/704find2half
find2halfsrc=../src/704find2half.cpp

erasebin=../bin/27erase
erasesrc=../src/27erase.cpp

target : $(find2halfbin) $(erasebin)
$(find2halfbin) : $(find2halfsrc)
	g++ -std=c++11 -o $(find2halfbin) $(find2halfsrc)

$(erasebin) : $(erasesrc)
	g++ -std=c++11 -o $(erasebin) $(erasesrc)