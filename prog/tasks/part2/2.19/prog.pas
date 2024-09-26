program prog;

procedure CountWords(message: string; var num: integer);
var
	i: integer;
	isSpace: boolean;
begin
	num := 0;
	isSpace := true;
	for i:= 1 to length(message) do
	begin
		if message[i] = ' ' then
			isSpace := true;
	    if message[i] in ['!'..'~'] then
		begin
			if isSpace then
			begin
				num := num + 1;
				isSpace := false
			end;
		end;
	end;
end;

procedure WordsLength(message: string; var num1, num2: integer);
var
	i, n: integer;
begin
	n := 0;
	num1 := 0;
	num2 := 0;
	message := message + ' '; 
	for i:= 1 to length(message) do
	begin
		if message[i] in [' ', #9] then
		begin
			if n <> 0 then
			begin
				if (n mod 2) <> 1 then
					num1 := num1 + 1 
				else 
					num2 := num2 + 1
			end;
			n := 0;
		end;
		if message[i] in ['!'..'~'] then
		   n := n + 1;
	end;
end; 

procedure WordsValid(message: string; var num1, num2: integer);
var 
	i, n: integer;
begin
	n := 0;
	num1 := 0;
	num2 := 0;
	message := message + ' ';
	for i:= 1 to length(message) do
	begin
		if message[i] in [' ', #9] then
		begin
			if (n >= 0) and (n < 2) then
				num1 := num1 + 1;
			if n > 7 then
				num2 := num2 + 1;
			n := 0		
		end
		else
		   n := n + 1;	
	end;
end;

procedure WordsAZ(message: string; var num: integer);
var 
	i: integer;
	isSpace: boolean;
	first, last: char;
begin
	isSpace := true;
	num := 0;
	first := ' ';
	last := ' ';
	message := message + ' ';
	for i:= 1 to length(message) do
	begin
		if message[i] in [' ', #9] then
		begin
			if (first in ['A', 'a']) and (last in ['Z', 'z']) then
				num := num + 1;
			isSpace := true
		end
		else
		begin
			if isSpace then
				first := message[i]
			else 
				last := message[i];
			isSpace := false
		end;
	end;
end;

procedure MinMaxWordsLength(message: string; var num1, num2: integer);
var
	i, n: integer;
begin
	n := 0;
	num1 := maxint;
	num2 := 0;
	message := message + ' '; 
	for i:= 1 to length(message) do
	begin
		if message[i] in [' ', #9] then
		begin
			if n <> 0 then
			begin
				if num1 > n then
					num1 := n; 
				if num2 < n then
					num2 := n
			end;
			n := 0;
		end;
		if message[i] in ['!'..'~'] then
		   n := n + 1;
	end;
end; 

procedure MaxSpaces(message: string; var num: integer);
var
	i, n: integer;
begin
	n := 0;
	num := 0;
	for i:= 1 to length(message) do
	begin
		if message[i] = ' ' then
		begin
			n := n + 1;
			if num < n then
				num := n;
		end
		else 
			n := 0
	end;
end;

procedure BalanceBrackets(message: string);
var
	i: integer;
	brackets: integer;
begin
	brackets := 0;
	for i := 1 to length(message) do
	begin
		if message[i] = '(' then
		begin
			brackets := brackets + 1;
		end
		else if message[i] = ')' then
		begin
			brackets := brackets - 1;
			if brackets < 0 then
				break
		end;
	end;
	if brackets = 0 then
		writeln('Balance brackets: YES')
	else 
		writeln('Balance brackets: NO')
end;

procedure CountBrackets(message: string; var num: integer);
var
	i: integer;
begin
	num := 0;
	message := message + ' ';
	for i := 1 to length(message) do
	begin
		if (message[i] = '(') and (message[i+1] = ')') then
		begin
			num := num + 1
		end;
	end;
end;

var
	message: string;
	num1, num2: integer;
begin
	write('Write message: ');
	while not EOF do
	begin
		readln(message);
		CountWords(message, num1);
		writeln('Count words: ', num1);
		WordsLength(message, num1, num2);
		writeln('Count of even: ', num1);
		writeln('Count of odd: ', num2);
		WordsValid(message, num1, num2);
		writeln('Words more 2: ', num1);
		writeln('Words less 7: ', num2);
		WordsAZ(message, num1);
		writeln('Words a..z: ', num1);
		MinMaxWordsLength(message, num1, num2);
		writeln('Min word: ', num1); 
		writeln('Max word: ', num2);
		MaxSpaces(message, num1);
		writeln('Max space: ', num1);
		BalanceBrackets(message);
		CountBrackets(message, num1);
		writeln('Brackest: ', num1);
		writeln('=========================');
		write('Write message: ')
	end;
end.
