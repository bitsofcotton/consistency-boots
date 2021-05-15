#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>

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
  vector<uint8_t> buf;
  buf.resize(atoi(argv[1]), 0);
  if(argv[2][0] != 'S') {
    assert(strlen(argv[1]) & 1);
    for(int i = 0; i < atoi(argv[1]) && i * 2 < strlen(argv[2]) &&
                   i < buf.size(); i ++)
      buf[i] = (hex(argv[2][i * 2]) << 4) | hex(argv[2][i * 2 + 1]);
  }
  ofstream output;
  output.open(argv[3]);
  if(output.is_open()) {
    output << "__asm (";
    for(int i = 0; i < buf.size(); i ++)
      output << "\".byte 0x" << tbl[(buf[i] >> 4) & 0x0f] << tbl[buf[i] & 0x0f] << ";\"" << endl;
    for(int i = 0; i < atoi(argv[4]); i ++)
      output << "\"nop;\"" << endl;
    output << ");" << endl;
    output.close();
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
        cout << tbl[(buf2[i] >> 4) & 0x0f] << tbl[buf2[i] & 0x0f];
    else
      cout << "E" << endl;
    cout << endl;
  } else
    cout << "error";
  return 0;
}

