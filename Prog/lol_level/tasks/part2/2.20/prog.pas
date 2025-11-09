program prog;

procedure DecorateBrackets(var message: string);
var
	i: integer;
	newMessage: string;
	isSpace: boolean;	
begin
	message := message + ' ';
	newMessage := '';
	isSpace := true;
	for i := 1 to length(message) do
	begin
		if message[i] = ' ' then
		begin
			if not isSpace then
				newMessage := newMessage + ')' + message[i]
			else 
				newMessage := newMessage + message[i];
			isSpace := true
		end
		else if message[i] in ['!'..'~'] then
		begin
			if isSpace then
				newMessage := newMessage + '(' + message[i]
			else 
				newMessage := newMessage + message[i];
			isSpace := false
		end;
	end;
	message := newMessage
end;

var
	message: string;
begin
	write('Write message: ');
	while not EOF do
	begin
		readln(message);
		DecorateBrackets(message);
		writeln(message);
		write('Write message: ')
	end;
end.
