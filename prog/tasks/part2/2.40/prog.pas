program prog;

type
	PNode = ^TNode;
	PCount = ^longint;
	TNode = record
		value: longint;
		count: PCount;
		next: PNode;
	end;

var
	head, current: PNode;
	num: longint;

procedure AddToList(num: longint);
var
	node, search: PNode;
begin
	search := head; 
  
	node := new(PNode);
    node^.value := num;
	node^.next := nil;

	while search <> nil do
	begin
		if search^.value = num then
		begin
			node^.count := search^.count;
			inc(search^.count^);
			current^.next := node;
			current := node;
			exit;
		end;
		search := search^.next;
	end;

	new(node^.count);
	node^.count^ := 1;
  
	if head = nil then
		head := node
	else
		current^.next := node;
	current := node;
end;

procedure RemoveNotThreeTimes;
var
	prev, temp, next: PNode;
begin
	temp := head;
	prev := nil;
  
	while temp <> nil do
	begin
		next := temp^.next;

		if temp^.count^ <> 3 then
		begin
		// Remove element from list
			if prev = nil then
			head := temp^.next
		else
			prev^.next := temp^.next;
			dispose(temp)
		end
		else
		begin
			prev := temp;
		end;
		temp := next;
	end;
end;

procedure PrintList;
var
	temp: PNode;
begin
	temp := head;
	while temp <> nil do
	begin
		Write(temp^.value, ' ');
		temp := temp^.next;
	end;
end;

begin
	head := nil;
	current := nil;

	// Reading numbers from a I/O stream
	while not eof do
	begin
		Read(num);
		AddToList(num);
	end;

	// Remove elements from a list
	RemoveNotThreeTimes;

	// Print elements 
	PrintList;
end.

