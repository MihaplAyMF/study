program prog;
uses crt;

const
	delayDuration = 100; 

type
	rect = record
		top, left, height, width: integer;
	end;
	star = record
		CurX, CurY, dx, dy: integer;
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
end;

procedure ShowStar(var s: star);
begin
	GotoXY(s.CurX, s.CurY);
	write('#');
	GotoXY(1, 1)
end;

procedure HideStar(var s: star);
begin
	GotoXY(s.CurX, s.CurY);
	write('*');
	GotoXY(1, 1)
end;

procedure SetDirection(var s: star; dx, dy: integer);
begin
	s.dx := dx;
	s.dy := dy;
end;

procedure MoveStarInRect(var s: star; var r: rect; var dr: integer; var directChange: boolean);
begin
	HideStar(s);

	s.CurX := s.CurX + s.dx;
	s.CurY := s.CurY + s.dy;

	if directChange then
	begin
		directChange := false;
        if (s.CurX > r.left) and (s.CurX < r.left + r.width - 1) then
            SetDirection(s, -s.dx, 0)
        else if (s.CurY > r.top) and (s.CurY < r.top + r.height - 1) then 
		    SetDirection(s, 0, -s.dy)
		else
            directChange := true;
	end;

	if directChange then
		dr := dr * -1;
	
	if (s.dx =  1) and (s.CurX > r.left + r.width -2) then
		SetDirection(s, 0, s.dx*dr)
	else if (s.dx = -1) and (s.CurX <= r.left) then 
		SetDirection(s, 0, s.dx*dr)
	else if (s.dy =  1) and (s.CurY > r.top + r.height -2) then
		SetDirection(s, -s.dy*dr, 0)
	else if (s.dy = -1) and(s.CurY <= r.top) then
		SetDirection(s, -s.dy*dr, 0);
	
	if directChange then	
		dr := dr * -1;
		
	ShowStar(s)
end;

var
	r: rect;
	s: star;	
	ch: char;
	speed: real;
	directInvert: integer;
	directChange: boolean;
	isSpace: boolean;
begin
 	clrscr;
	speed := 1;
	isSpace := false;
	directInvert := 1;
	directChange := false;
	
	r.height := 10;
	r.width := 20;
	r.top := (ScreenHeight div 2) - (r.height div 2);
	r.left := (ScreenWidth div 2) - (r.width div 2);
	ShowRect(r);
	
	s.CurX := r.left;
	s.CurY := r.top;
	s.dx := 1;
	s.dy := 0;
	while true do
	begin
		if KeyPressed then
		begin	
			ch := readkey;
			case ch of
				#27:  
					break;
				#77:
					speed := speed * 2;
				#75:
					speed := speed / 2;
				#32: 
				if not isSpace then
				begin
					directInvert := directInvert * -1;
					directChange := true;
					isSpace := true;
				end;
			end;
		end;
		if isSpace then
		begin 
			MoveStarInRect(s, r, directInvert, directChange);		
			delay(trunc(delayDuration * speed));	
			MoveStarInRect(s, r, directInvert, directChange);		
			delay(trunc(delayDuration * speed));
			isSpace := false
		end;
		MoveStarInRect(s, r, directInvert, directChange);		
		delay(trunc(delayDuration * speed))
	end;
	clrscr
end.
