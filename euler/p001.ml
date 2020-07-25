let rec solve n sum =
	if n = 1000 then
		sum
	else if n mod 3 = 0 then
		solve (n + 1) (sum + n)
	else if n mod 5 = 0 then
		solve (n + 1) (sum + n)
	else
		solve (n + 1) sum

let _ =
	print_int (solve 0 0)

