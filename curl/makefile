CXX = g++
LIB = -lcurl

all:httpget httppost

httpget:./src/HttpGet.cpp
	$(CXX) $^ $(LIB) -o ./bin/$@

httppost:./src/HttpPost.cpp
	$(CXX) $^ $(LIB) -o ./bin/$@
