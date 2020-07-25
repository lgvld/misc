let rec fibonacci_sum sum a b =
	if b <= 4000000 then
		if b mod 2 = 0 then
			fibonacci_sum (sum + b) b (a + b)
		else
			fibonacci_sum sum b (a + b)
	else
		sum

(*=============================================================================
Il y a quelque chose de plus malin à faire : puisque la somme de deux
nombres impairs est un nombre pair, on sait qu’un nombre de Fibonacci est pair
une fois sur trois.
=============================================================================*)

let _ =
	print_int (fibonacci_sum 0 1 1)
