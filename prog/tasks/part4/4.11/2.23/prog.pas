program prog;

procedure CountWords(message: string; var num: integer);
var
	i: integer;
	isSpace: boolean;
begin
	num := 0;
	isSpace := true;
	for i:= 1 to length(message) do
	begin
		if message[i] = ' ' then
			isSpace := true;
	    if message[i] in ['!'..'~'] then
		begin
			if isSpace then
			begin
				num := num + 1;
				isSpace := false
			end;
		end;
	end;
end;

var
	num: integer;
begin
	if ParamCount <> 1 then
		writeln('input 1 argument')
	else 
	begin
		CountWords(ParamStr(1), num);
		writeln(num)
	end;
end.
