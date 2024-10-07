pause=0.0
if [ $1 ]; then
    pause=$1
fi

tput clear

positions=()
chars=()
j=-1
lines_cnt=0
max_width=0

while IFS= read -r line; do
    for ((i=0; i<${#line}; i++)); do
        if [ "$max_width" -lt "$i" ]; then
            max_width="$i"
        fi
        ((j++))
        positions+=("$lines_cnt $i")
        chars[j]=${line:i:1}
    done
    ((lines_cnt++))
done

((max_width++))
left_skip=$(( ($(tput cols) - max_width) / 2 ))
upper_skip=$(( ($(tput lines) - lines_cnt) / 2 ))

perm=$(shuf -i 0-$j)

for ((i=0; i<=j; i++)); do
    sleep $pause
    curr_pos=$(echo $perm | cut -d ' ' -f $((i + 1)))
    IFS=' ' read row column <<< ${positions[curr_pos]}
    tput cup $(( row + upper_skip )) $(( column + left_skip ))
    echo -n "${chars[curr_pos]}"
done

tput cup $(( lines_cnt + upper_skip )) 0
