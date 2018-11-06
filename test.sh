make

max=0
moy=0

if [ "$#" -ne 2 ]
then
	echo "Must have 2 param : "
	echo "1. The number of iteration (int),"
	echo "2. The number of param to give to push_swap (int)."
	exit
fi

# The number of iteration
nbIteration=$(($1 + 0))

# The amount of param to give to push swap
nbParam=$(($2 + 0))

echo "Compute $nbIteration iterations of $nbParam params"

for i in `seq 1 $nbIteration`; do ARG=$(python *.py $nbParam)
	res=$(./push_swap $ARG  | wc -l | tr -d ' ')

	if [ $res -gt $max ]
	then
		max=$res
	fi

	moy=$(($moy + $res))

	echo "\033c"
	echo "Iterations : $i/$nbIteration"

done

moy=$(($moy / $i))

echo "Maximum : $max"
echo "Moyenne : $moy"