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

procedure MoveStar(var s: star; var passage: integer);
begin
	HideStar(s);
	s.CurX := s.CurX + s.dx;
	s.CurY := s.CurY + s.dy;
	if s.CurX > ScreenWidth-2 then
	begin
		s.dx := -1;
		passage := passage + 1
	end;
	if s.CurX < 1 then 
	begin
		s.dx := 1;
		passage := passage + 1
	end;
	ShowStar(s);
end;

procedure SetDirection(var s: star; dx, dy: integer);
begin
	s.dx := dx;
	s.dy := dy;
end;

var 
	s: star;
	passage: integer;
begin
	clrscr;
	s.CurX := 1;
	s.CurY := ScreenHeight div 2;
	s.dx := 1;
	s.dy := 0;
	passage := 0;
	while true do
	begin
		MoveStar(s, passage);
		delay(delayDuration);
		if passage = 6 then
			break
	end;
	clrscr
end.
