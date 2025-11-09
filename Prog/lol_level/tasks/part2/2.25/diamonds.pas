program diamond;

uses SysUtils;

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

	if ParamCount <> 2 then
	begin
		writeln('input 2 arguments');
		halt
	end;
	
	height := StrToInt(ParamStr(1));
    diamondCount := StrToInt(ParamStr(2));

	if (height < 5) or (height mod 2 = 0) then
	begin
		writeln('height should be more than 5 and odd!');
		halt
	end;
	
	if diamondCount < 1 then
	begin
		writeln('diamondCount shoud be more than 0');
		halt
	end;

    halfHeight := height div 2 + 1;

    for i:= 1 to halfHeight do
        PrintLineOfDiamond(i, halfHeight, diamondCount);

    for i := halfHeight-1 downto 1 do
        PrintLineOfDiamond(i, halfHeight, diamondCount)
end.

