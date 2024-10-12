break range.c:31 if i % 5 == 0
	command 1
	echo @@@
	print {start, end, diff, i}
	continue
end

run 1 12 > /dev/null

quit
