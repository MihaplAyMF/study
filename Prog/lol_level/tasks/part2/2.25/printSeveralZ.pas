program printZ;

uses SysUtils;

procedure PrintSymb(count: integer; symb: char);
var
	i: integer;
begin
	for i := 1 to count do 
		write(symb);
end;

procedure PrintPartOfZ(line, height: integer);
begin

	if (line = 1) or (line = (height div 2 + 1)) or (line = height) then
		PrintSymb(height, '*')
	else 
	begin
		PrintSymb(height-line, ' ');
		write('*');
		PrintSymb(line-1, ' ');
	end;
end;

procedure PrintLineOfZ(line, count, height: integer);
var
	j, space, halfHeight: integer;
	state: boolean;
begin
	halfHeight := height div 2;
	space := (((line - (Height + 1)) + halfHeight) div halfHeight);

	for j := 1 to count do 
	begin
		if space >= j then
			PrintSymb(height, ' ') 
		else if (((line-1) div halfHeight) + 1) >= j then
		begin
			if (line <= height) and (j = 1) then
				PrintPartOfZ(line, height)
			else if space+1 = j then
				PrintPartOfZ(((line-1) mod halfHeight)+halfHeight+1, height)
			else  
				PrintPartOfZ(((line-1) mod halfHeight)+1, height);
		end;
		write(' ')
	end;
	writeln
end;

var
	line, count, height, totalHeight: integer;
begin

	if ParamCount <> 2 then
	begin
		writeln('input 2 arguments');
		halt
	end;
	
	height := StrToInt(ParamStr(1));
    count := StrToInt(ParamStr(2));

	if (height < 5) or (height mod 2 = 0) then
	begin
		writeln('height should be more than 5 and odd!');
		halt
	end;
	
	if count < 1 then
	begin
		writeln('count shoud be more than 0');
		halt
	end;

	totalHeight := height + (height div 2) * (count - 1);

	for line := 1 to totalHeight do 
		PrintLineOfZ(line, count, height)

end.
