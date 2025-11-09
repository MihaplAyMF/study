program prog;

procedure LongestWord(var message: string; var num: integer);
var
	i: integer;
begin
	num := 1;

	for i := 1 to ParamCount do
	begin
		if Length(ParamStr(num)) < Length(ParamStr(i)) then
			num := i
	end;

	message := ParamStr(num);
	num := Length(message)
end;


procedure NotSameSymb(var message: string);
var
	i, j, k: integer;
	isSame: boolean;
	tmpMessage: string;
begin
	message := '';
	
	for i := 1 to ParamCount do
	begin
		isSame := false;
		tmpMessage := ParamStr(i);

		for j := 1 to Length(tmpMessage) do
			for k := j + 1 to Length(tmpMessage) do
				if tmpMessage[j] = tmpMessage[k] then
					isSame := true;
		
		if not isSame then
			message := message + tmpMessage + ' '
	end;		
end;

procedure IsValidMessage(var message: string);
var
	i, j: integer;
	num: integer;
	isDot: boolean;
	tmpMessage: string;
begin
	message := '';

	for i := 1 to ParamCount do
	begin
		num := 0;
		isDot := false;
		tmpMessage := ParamStr(i);

		for j := 1 to Length(tmpMessage) do
		begin
			if tmpMessage[j] = '@' then
				num := num + 1;
			if tmpMessage[j] = '.' then
				isDot := true;
		end;
	
		if isDot and (num = 1) then
			message := message + tmpMessage + ' ';
	end;
end;

procedure isDigit(var message: string);
var
	i, j: integer;
	isDigit: boolean;
	tmpMessage: string;
begin
	message := '';
	
	for i := 1 to ParamCount do
	begin
		isDigit := true;		
		tmpMessage := ParamStr(i);

		for j := 1 to Length(tmpMessage) do
			if not (tmpMessage[j] in ['0'..'9']) then
				isDigit := false;

		if isDigit then
			message := message + tmpMessage + ' ';
	end;
end;

procedure SameSymb(var message: string);
var
	i, j: integer;
	symb: char;
	sameSymb: boolean;
	tmpMessage: string;
begin
	message := '';

	for i := 1 to ParamCount do
	begin
		sameSymb := true;
		tmpMessage := ParamStr(i);
		symb := tmpMessage[1];	

		for j := 1 to Length(tmpMessage) do
			if symb <> tmpMessage[j] then
				sameSymb := false;

		if sameSymb then
			message := message + tmpMessage + ' ';
	end;
end;

procedure IsLatinSymb(var message: string);
var
	i, j: integer;
	isLatine: boolean;
	tmpMessage: string;
begin
	message := '';
	for i := 1 to ParamCount do
	begin
		isLatine := false;
		tmpMessage := ParamStr(i);

		for j := 1 to Length(tmpMessage) do
			if tmpMessage[j] in ['A'..'Z', 'a'..'z'] then
				isLatine := true;

		if isLatine then
			message := message + tmpMessage + ' ';
	end;
end;

procedure IsSymbFirstWord(var message: string);
var
	i, j, k: integer;
	tmpMessage, firstMessage: string;
	isSymbFirstWord: boolean;
begin
	message := '';
	firstMessage := ParamStr(1);
	for i := 2 to ParamCount do
	begin
		isSymbFirstWord := false;
		tmpMessage := ParamStr(i);

		for j := 1 to Length(firstMessage) do
			for k := 1 to Length(tmpMessage) do
				if firstMessage[j] = tmpMessage[k] then
					isSymbFirstWord := true;

		if isSymbFirstWord then
			message := message + tmpMessage + ' ';		
	end;
end;

var
	i: integer;
	message: string;
	num: integer;
begin
	
	if ParamCount = 0 then
	begin
		writeln('You not input arguments');
		halt
	end;
	
	LongestWord(message, num);
	writeln('a) ', message);
	writeln('a) ', num);
	
	NotSameSymb(message);
	writeln('b) ', message);

	IsValidMessage(message);
	writeln('c) ', message);
	
	IsDigit(message);
	writeln('d) ', message);

	sameSymb(message);
	writeln('e) ', message);
	
	IsLatinSymb(message);
	writeln('f) ', message);

	IsSymbFirstWord(message);
	writeln('g) ', message);

end.
