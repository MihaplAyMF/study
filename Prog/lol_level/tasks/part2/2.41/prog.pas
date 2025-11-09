
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
	num, max: longint;

procedure AddToList(num: longint);
var
	node, search: PNode;
begin
	search := head; 
  
	// Створюємо новий вузол
	node := new(PNode);
	node^.value := num;
	node^.next := nil;

	// Шукаємо число в списку
	while search <> nil do
	begin
		if search^.value = num then
		begin
			// Копіюємо лічильник і збільшуємо його
			node^.count := search^.count;
			inc(search^.count^);
			
			// Оновлюємо максимум
			if max < search^.count^ then
				max := search^.count^;
			
			current^.next := node;
			current := node;
			exit;
		end;
		search := search^.next;
	end;

	// Якщо елемент новий, створюємо новий лічильник
	new(node^.count);
	node^.count^ := 1;

	// Оновлюємо максимальне значення лічильника, якщо це перший елемент
	if head = nil then
		max := node^.count^;

	// Додаємо новий вузол до списку
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

		if temp^.count^ <> max then
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

