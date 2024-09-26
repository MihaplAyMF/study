program printZ;

uses SysUtils;

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

	if ParamCount <> 1 then
	begin
		writeln('input 1 arguments');
		halt
	end;
	
	height := StrToInt(ParamStr(1));
	if (height < 5) or (height mod 2 = 0) then
	begin
		writeln('height should be more than 5 and odd!');
		halt
	end;

	for line := 1 to height do 
		PrintLineOfZ(line, height)

end.
