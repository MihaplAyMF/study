program prog;
uses crt;

const
	ColorCount = 16;
	BGColCount = 8;

var
	AllColors: array [1..ColorCount] of word =
	(
		Black, Blue, Green, Cyan,
		Red, Magenta, Brown, LightGray,
		DarkGray, LightBlue, LightGreen, LightCyan,
		LightRed, LightMagenta, Yellow, White
	);
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
	textCol, bgCol: integer;
	r: rect;
	ch: char;
begin
 	clrscr;
	
	textCol := 1;
	bgCol := 1;

	r.height := 5;
	r.width := 10;
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
					gotoxy(1, 1);
					write(textCol);
					textCol := textCol + 1;
					if textCol > ColorCount then
						textCol := 1;
					TextColor(AllColors[textCol]);
				end;
				#75: {left} 		
				begin
					bgCol := bgCol - 1;
					if bgCol < 1 then
						bgCol := BGColCount;
					textBackground(AllColors[bgCol]);
				end;

				#77: {right}			
				begin
					bgCol := bgCol + 1;
					if bgCol > BGColCount then
						bgCol := 1;
					textBackground((AllColors[bgCol]));
				end;
				#80: {down}
				begin
					textCol := textCol - 1;
					if textCol < 1 then
						textCol := ColorCount;
					TextColor((AllColors[textCol]));
				end;
			end;
			ShowRect(r);
		end;
	end;
	write(#27'[0m');
	clrscr
end.
