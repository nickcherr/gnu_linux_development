set $step=0

break range.c:31 if ++$step>27 && $step<36
    command 1
    echo @@@
    print {start, end, diff, i}
	continue
end

run -100 100 3 > /dev/null

quit
