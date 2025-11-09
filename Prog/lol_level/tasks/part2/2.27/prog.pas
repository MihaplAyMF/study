program prog;
uses crt;

const
	delayDuration = 10; {100;}

type
	star = record
		CurX, CurY, dx, dy: integer;
	end;

procedure ShowStar(var s: star);
begin
	GotoXY(s.CurX, s.CurY);
	write('*');
	GotoXY(1, 1)
end;

procedure HideStar(var s: star);
begin
	GotoXY(s.CurX, s.CurY);
	write(' ');
	GotoXY(1, 1)

end;

procedure MoveStar(var s: star);
begin
	HideStar(s);
	s.CurX := s.CurX + s.dx;
	s.CurY := s.CurY + s.dy;
	if s.CurX > ScreenWidth-2 then
		s.dx := -1;
	if s.CurX < 1 then 
		s.dx := 1;
	ShowStar(s)
end;

procedure SetDirection(var s: star; dx, dy: integer);
begin
	s.dx := dx;
	s.dy := dy;
end;

var 
	s: star;
	ch: char;
begin
	clrscr;
	s.CurX := 1;
	s.CurY := ScreenHeight div 2;
	s.dx := 1;
	s.dy := 0;
	while true do
	begin
		if KeyPressed then
		begin	
			ch := readkey;
			if ch = #27 then
			break
		end;
		MoveStar(s);
		delay(delayDuration)	
	end;
	clrscr
end.
