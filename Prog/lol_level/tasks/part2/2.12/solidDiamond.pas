program solidDiamond;

procedure PrintSymb(count: integer; symb: char);
var
	i: integer;
begin
	for i := 1 to count do 
		write(symb);
end;

procedure PrintLineOfDiamond(i: integer; halfHeight: integer);
begin
	PrintSymb(halfHeight-i, ' ');
	if i <> 1 then
		write('*');
	PrintSymb(2*i-3, '*');
	writeln('*')
end;

var
	i, height, halfHeight: integer;
begin
	repeat	
		write('Enter the diamond''s height(possitive odd): ');
		readln(height);
    until (height > 0) and (height mod 2 = 1);   

    halfHeight := height div 2 + 1;

    for i:= 1 to halfHeight do
        PrintLineOfDiamond(i, halfHeight);

    for i := halfHeight-1 downto 1 do
        PrintLineOfDiamond(i, halfHeight)
end.
