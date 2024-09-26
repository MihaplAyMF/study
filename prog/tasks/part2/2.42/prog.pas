program prog;

type
	PNode = ^TNode;
	TNode = record
		word: string;
		next: PNode;
	end;

var
	tail, current: PNode;
	line: string;
	word: string;
	i: integer;

procedure addWord(w: string);
var
	node: PNode;
begin
	new(node);
	node^.word := w;
	node^.next := tail;
	tail := node;
end;

begin 
	readln(line);

	word := '';
	for i := 1 to length(line) do
	begin
		if line[i] in [' ', '!', '.', '?', ',', ';', ':'] then
		begin
			if word <> '' then
			begin
				addWord(word);  				
				word := '';     
			end;
		end
		else			
			word := word + line[i];
	end;
  
	if word <> '' then
		addWord(word);

	current := tail;
	while current <> nil do
	begin
		writeln(current^.word);
		current := current^.next;
	end;
end.

