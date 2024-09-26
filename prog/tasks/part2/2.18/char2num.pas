{ char2num.pas }

function CharToValue(var c: char): integer;
begin
  if c in ['0'..'9'] then
    CharToValue := Ord(c) - Ord('0')
  else if c in ['A'..'Z'] then
    CharToValue := Ord(c) - Ord('A') + 10
  else if c in ['a'..'z'] then
    CharToValue := Ord(c) - Ord('a') + 10
  else
    CharToValue := -1;  
end;

procedure ReadLongint(var success: boolean; var result: longint; notation: integer);
var
	c: char;
	res: longint;
	pos: integer;
begin
	res := 0;
	pos := 0;
	
	repeat
		read(c);
		pos := pos + 1
	until (c <> ' ') and (c <> #10);

	while (c <> ' ') and (c <> #10) do
	begin
		if (CharToValue(c) = -1) or (CharToValue(c) > notation-1) then
		begin
			writeln('Unexpected	"', c , '" in pos: ', pos);
			readln;
			success := false;
			exit
		end;
		res := res * notation + CharToValue(c);
		read(c);
		pos := pos + 1
	end;
	result := res;
	success := true
end;

var
	num, notation: longint;
	ok: boolean;
begin
	repeat
		write('Enther the number system (more 2 but less 36): ');
		readln(notation);
	until (notation >= 2) and (notation <= 36);

	ReadLongint(ok, num, notation);
	writeln(num)
end.
