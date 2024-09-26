program solidDiamond;

uses SysUtils;

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

	if ParamCount <> 1 then
	begin
		writeln('input 1 arguments');
		halt
	end;
	
	height := StrToInt(ParamStr(1));
    
	if (height < 0) or (height mod 2 = 0) then
	begin
		writeln('height should be more than 0 and odd!');
		halt
	end;

	width := height + 2;
    halfHeight := height div 2 + 1;
	
	PrintLineOfSymb(width, '*');
    for i:= 1 to halfHeight do
        PrintLineOfDiamond(i, halfHeight);

    for i := halfHeight-1 downto 1 do
        PrintLineOfDiamond(i, halfHeight);
	PrintLineOfSymb(width, '*')
end.
