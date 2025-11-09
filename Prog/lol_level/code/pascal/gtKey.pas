program	 gtKey;
uses crt;

procedure GetKey(var code: integer);
var
	c: char;
begin
	c := ReadKey;
	if c = #0 then
	begin 
		c := ReadKey;
		code := -ord(c)
	end
	else
	begin
		code := ord(c)
	end;
	write(c, ' ')
end;

var 
	i: integer;
begin
	repeat
		GetKey(i);
		writeln(i);
	until i = ord(' ')
end.
