program prog;
uses crt;

type
	rect = record
		top, left, height, width: integer;
	end;

procedure HideRect(var r: rect);
var
	i, j: integer;
begin
	for i := r.left to (r.left + r.width - 1) do
		for j := r.top to (r.top + r.height - 1) do
		begin
			GotoXY(i, j);
			write(' ') 
		end;
	GotoXY(1, 1)	
end;


procedure ShowRect(var r: rect);
var
	i, j: integer;
begin
	for i := r.left to (r.left + r.width - 1) do
		for j := r.top to (r.top + r.height - 1) do
		begin
			GotoXY(i, j);
			write('*') 
		end;
	GotoXY(1, 1)	
end;

var
	r: rect;
	ch: char;
begin
 	clrscr;
	
	r.height := 3;
	r.width := 3;
	r.top := (ScreenHeight div 2) - (r.height div 2);
	r.left := (ScreenWidth div 2) - (r.width div 2);
	ShowRect(r);
	
	while true do
	begin
		if KeyPressed then
		begin	
			HideRect(r);
			ch := readkey;
			case ch of
				#27:  
					break;
				#72: {up}
					begin
						if r.height < (ScreenHeight div 2) then
						begin
							r.top:= r.top - 1;
							r.height := r.height + 2;
						end;
					end;
				#75: {left}
					begin
						if r.left <> (ScreenWidth div 2) then
						begin
							r.left := r.left + 1;
							r.width := r.width - 2;
						end;
					end;
				#77: {right}
					begin
						if r.width < (ScreenWidth div 2) then
						begin
							r.left := r.left - 1;
							r.width := r.width + 2;
						end;
					end;
				#80: {down}
					begin
						if r.top <> (ScreenHeight div 2) then
						begin
							r.top:= r.top + 1;
							r.height := r.height - 2;
						end
					end;
			end;
			ShowRect(r);
		end;
	end;
	clrscr
end.
