off="S"
len=$1
pad=$2
while [[ $off != "E" ]]; do
  ooff=`echo $off`
  off=`./incre $len $off ./bytes.h $pad`
  clang++ -O0 ./test.cc
  echo $ooff `./a.out`
done

