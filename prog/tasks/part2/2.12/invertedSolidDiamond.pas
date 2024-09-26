program solidDiamond;

procedure PrintSymb(count: integer; symb: char);
var
	i: integer;
begin
	for i := 1 to count do 
		write(symb);
end;

procedure PrintLineOfSymb(count: integer; symb: char);
var
	i: integer;
begin
	for i := 1 to count do 
		write(symb);
	writeln()
end;

procedure PrintLineOfDiamond(i: integer; halfHeight: integer);
begin
	PrintSymb(halfHeight-i+1, '*');
	if i = 1 then
		write(' ')
	else 
		PrintSymb(2*i-1, ' ');
	PrintSymb(halfHeight-i+1, '*');
	writeln()
end;

var
	i, height, width, halfHeight: integer;
begin
	repeat	
		write('Enter the diamond''s height(possitive odd): ');
		readln(height);
    until (height > 0) and (height mod 2 = 1);   

	width := height + 2;
    halfHeight := height div 2 + 1;
	
	PrintLineOfSymb(width, '*');
    for i:= 1 to halfHeight do
        PrintLineOfDiamond(i, halfHeight);

    for i := halfHeight-1 downto 1 do
        PrintLineOfDiamond(i, halfHeight);
	PrintLineOfSymb(width, '*')
end.
