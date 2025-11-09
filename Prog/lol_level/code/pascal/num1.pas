program num1;

procedure GetNumber(var success: boolean; var result: longint);
var
	c: char;
	res: longint;
	pos: integer;
	neg: boolean;
begin
	res := 0;
	pos := 0;

	repeat
		read(c);
		pos := pos + 1
	until (c <> ' ') and (c <> #10);

	neg := (c = '-'); { якщо число від'ємне то neg := true}
	if neg then
	begin
		read(c);
		pos := pos + 1
	end;

	while (c <> ' ') and (c <> #10) do
	begin
		if (c < '0') or (c > '9') then
		begin
			writeln('Unexpected	"', c , '" in pos: ', pos);
			readln;
			success := false;
			exit
		end;
		res := res * 10 + ord(c) - ord('0');
		read(c);
		pos := pos + 1;
	end;
	
	if neg then
		res := res * -1;
	result := res;
	success := true;
end;

type 
	itemptr = ^item;
	item = record	
		data: integer;
		next: itemptr;
	end;

var
	num: longint;
	ok: boolean;
	first, tmp: itemptr;
begin
	first := nil;
	while not eof do
	begin
		GetNumber(ok, num);
		if ok then
		begin
			new(tmp);
			tmp^.data := num;
			tmp^.next := first;
			first := tmp
		end
	end;

	while first <> nil do
	begin
		if first^.next <> nil then
			write(first^.data, ', ')
		else
			writeln(first^.data);
		tmp := first;
		first := first^.next;
		dispose(tmp)
	end
end.
