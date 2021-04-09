#include <iostream>
#include <fstream>
#include <vector>

const char* tbl = "0123456789abcdef";

using namespace std;

char hex(const char& x) {
  if('a' <= x && x <= 'f')
    return x - 'a' + 10;
  if('0' <= x && x <= '9')
    return x - '0';
  assert(0 && "non lowered hex");
  return - 1;
}

int main(int argc, char* argv[]) {
  assert(4 < argc);
  std::vector<uint8_t> buf;
  buf.reserve(std::atoi(argv[1]));
  if(argv[2][0] == 'S')
    buf.resize(std::atoi(argv[1]), 0);
  else {
    assert(std::strlen(argv[1]) & 1);
    for(int i = 0; i < std::atoi(argv[1]) && std::strlen(argv[2]) * 2; i ++)
      buf.emplace_back((hex(argv[2][i * 2]) << 4) | hex(argv[2][i * 2 + 1]));
  }
  ofstream output;
  output.open(argv[3]);
  if(output.is_open()) {
    output << "__asm (";
    for(int i = 0; i < buf.size(); i ++)
      output << "\".byte 0x" << tbl[(buf[i] >> 4) & 0x0f] << tbl[buf[i] & 0x0f] << ";\"" << endl;
    for(int i = 0; i < std::atoi(argv[4]); i ++)
      output << "\"nop;\"" << endl;
    output << ");" << endl;
    auto buf2(buf);
    int ii;
    for(ii = 0; ii < buf2.size(); ii ++) {
      if(buf2[ii] == 0xff) ++ buf2[ii];
      else {
        ++ buf2[ii];
        break;
      }
    }
    if(ii < buf2.size())
      for(int i = 0; i < buf2.size(); i ++)
        std::cout << tbl[(buf2[i] >> 4) & 0x0f] << tbl[buf2[i] & 0x0f];
    else
      std::cout << "E" << std::endl;
    std::cout << std::endl;
  } else
    std::cout << "error";
  return 0;
}

