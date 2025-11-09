program printZ;

procedure PrintSymb(count: integer; symb: char);
var
	i: integer;
begin
	for i := 1 to count do 
		write(symb);
end;

procedure PrintLineOfZ(line, height: integer);
begin

	if (line = 1) or (line = (height div 2 + 1)) or (line = height) then
	begin
		PrintSymb(height, '*');
		writeln
	end
	else
	begin
		PrintSymb(height-line, ' ');
		writeln('*');
	end;
end;

var
	line, height, totalHeight: integer;
begin
	repeat
		write('Enter the Z height (more than 5 and odd): ');
		readln(height);
	until (height > 5) and (height mod 2 = 1);

	for line := 1 to height do 
		PrintLineOfZ(line, height)

end.
