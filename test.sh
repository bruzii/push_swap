#!/bin/bash

# Set up an infinite loop
while true; do
  random_number500=$(python print_number_random.py)
  random_number100=$(python number_100.py)
  random_number5=$(python number_5.py)
  res=$(./push_swap "$random_number500" | wc -l)
  result=$( ./push_swap $random_number500 | ./checker_linux $random_number500 )
	echo "ARG[mult][500]: $mychecker | $res		ARG[1][500]:	$result | $res"
  res=$(./push_swap "$random_number100" | wc -l)
  result=$( ./push_swap $random_number100 | ./checker_linux $random_number100 )
	echo "ARG[mult][100]:	$result | $res		ARG[1][100]:	$result | $res"
  res=$(./push_swap "$random_number5" | wc -l)
  result=$( ./push_swap $random_number5 | ./checker_linux $random_number5 )
	echo -e "ARG[mult][5]:	$result | $res		ARG[1][5]:	$result	| $res \n"
#	sleep 1
	if [[ $result != "OK" ]]; then 
		echo "$random_number_500"
		break
	fi
done

