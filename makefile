all:
  g++ -std=c++17 src/main.cpp -o exe
clean:
  $(RM) exe
