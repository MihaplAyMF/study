program prog;

procedure Words2SameSymb(var message: string);
var
	i: integer;
	first, second: char;
	tmpMessage, aword: string;
	isValid: boolean;
begin
	first := ' ';
	second := ' ';
	message := message + ' ';
	tmpMessage := '';
	aword := '';
	isValid := true;

	for i := 1 to length(message) do
	begin
		if message[i] in [' ', #9, #10] then
		begin
			if (first <> ' ') and (second <> ' ') and isValid then
			tmpMessage := tmpMessage + aword + ' ';
			first := ' ';
			second := ' ';
			aword := '';
			isValid := true;
		end
		else
		begin
			if first = ' ' then
				first := message[i]
			else if (second = ' ') and (message[i] <> first) then
				second := message[i]
			else if (message[i] <> first) and (message[i] <> second) then
				isValid := false;

			aword := aword + message[i]
		end;
	end;

  message := tmpMessage;
end;


var
	message: string;
begin
	write('Write message: ');
	while not EOF do
	begin
		readln(message);
		Words2SameSymb(message);
		writeln(message);
		write('Write message: ')
	end;
end.
