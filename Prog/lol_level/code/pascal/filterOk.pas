program filterOk;
var
	c: char;
begin
	while not eof do
	begin
		read(c);
		if c = #10 then
			write('Ok ');
	end;
	writeln('Good bye')
end.
