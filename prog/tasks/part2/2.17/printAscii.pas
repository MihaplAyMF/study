program printAscii;

var
	i, j: integer;
	c: char;
begin
	write('  |');
	for c := '0' to '8' do
		write(' .', c);
	writeln;
	for i := 1 to 10 do
		write('---');
	writeln;
	for i := 4 to 15 do
	begin
		if i < 10 then
			write(i, ' |')
		else 
			write(i, '|');
		for j := 0 to 8 do
			write('  ', chr(i*8+j));
		writeln
	end
end.
