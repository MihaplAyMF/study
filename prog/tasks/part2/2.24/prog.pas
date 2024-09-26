program prog;

uses SysUtils;

var
	x, y: real;
	n: integer;
begin
	if ParamCount <> 3 then
		writeln('Input 3 arguments')
	else 
	begin
		x := StrToFloat(ParamStr(1));
		y := StrToFloat(ParamStr(2));
		n := StrToInt(ParamStr(3));

		writeln(FormatFloat('0.' + StringOfChar('#', n), x*y));
	end;
end.
