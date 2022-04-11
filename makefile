all:
  g++ -std=c++17 src/main.cpp -o exe
  g++ -std=c++17 test/test_1.cpp -lcppunit -o test1
test:
  chmod +x exe
  ./test1
clean:
  $(RM) exe test1
