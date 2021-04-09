off="S"
len=$1
pad=$2
while [[ $off != "E" ]]; do
  ooff=`echo $off`
  off=`./incre $len $off ./bytes.h $pad`
  clang++ -O0 ./test.cc
  res=`./a.out 2>&1`
  echo $ooff $res
  rres=`echo $res | grep -v ok | wc -l`
  if (( $rres == 0 )); then
    cat ./bytes.h >> bytesall.h
  fi
done

