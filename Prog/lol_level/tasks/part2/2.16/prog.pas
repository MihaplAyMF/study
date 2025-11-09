program prog;

function repeatChar(message: string): string;
var
	i, j: integer;
	res: string;
	state: boolean;
begin
	res := '';
	for i := 1 to length(message) do
	begin
		state := false;
		for j := i+1 to length(message) do
		begin
			if message[i] = message[j] then
			begin
				state := true;
				message[j] := ' '
			end;
		end;
		if state and (message[i] <> ' ') then
			res := res + message[i];
	end;
	repeatChar := res;
end;


var
	message: string;
begin
	write('Input string: ');
	readln(message);
	message := repeatChar(message);
	writeln(message)
end.
