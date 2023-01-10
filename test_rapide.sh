#!/bin/bash

while true; do
	random_number100=$(python number_100.py)
	res=$(./push_swap "$random_number100" | wc -l)
	result=$( ./push_swap $random_number100 | ./checker_linux $random_number100 )
	 echo "ARG[1][100]:    $result | $res"
 	if [[ $result != "OK" ]]; then
		echo "$random_number_100"
		break
	fi
 	if [[ $res > 700 ]]; then
		echo "$random_number_100"
		break
	fi
done
