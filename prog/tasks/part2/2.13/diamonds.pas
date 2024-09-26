program diamond;

procedure PrintSpaces(count: integer);
var 
    i: integer;
begin
    for i := 1 to count do
        write(' ');
end;
    
procedure PrintLineOfDiamond(k, halfHeight, count: integer);
var 
	i: integer;
begin
	for i := 1 to count do
	begin	
		PrintSpaces(halfHeight-k);
		if k <> 1 then
			write('*');
		PrintSpaces(2*k-3);
		write('*');
		PrintSpaces(halfHeight-k+1);
	end;
	writeln
end;

var
    i, height, halfHeight, diamondCount: integer;
begin
    repeat
        write('Enter the diamond''s height (possitive odd): ');
        readln(height);
    until (height > 0) and (height mod 2 = 1);   

	repeat
        write('Enter the diamond''s count: ');
        readln(diamondCount);
    until (diamondCount > 0);   

    halfHeight := height div 2 + 1;

    for i:= 1 to halfHeight do
        PrintLineOfDiamond(i, halfHeight, diamondCount);

    for i := halfHeight-1 downto 1 do
        PrintLineOfDiamond(i, halfHeight, diamondCount)
end.

