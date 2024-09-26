program movingStar;
uses crt;
const
	DelayDuration = 100;

procedure GetKey(var code: integer);
var
	c: char;
begin
	c := ReadKey;
	if c = #0 then
	begin 
		c := ReadKey;
		code := -ord(c)
	end
	else
	begin
		code := ord(c)
	end
end;

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
			write('@') 
		end;
	GotoXY(1, 1)	
end;

procedure ShowStar(var s: star);
begin
	GotoXY(s.CurX, s.CurY);
	write('*');
	GotoXY(1, 1);
end;

procedure HideStar(var s: star);
begin
	GotoXY(s.CurX, s.CurY);
	write(' ');
	GotoXY(1, 1);
end;

procedure MoveStar(var s: star);
begin
	HideStar(s);
	
	s.CurX := s.CurX + s.dx;
	if s.CurX > ScreenWidth then
		s.CurX := 1
	else 
	if s.CurX < 1 then
		s.CurX := ScreenWidth;

	s.CurY := s.CurY + s.dy;
	if s.CurY > ScreenHeight then
		s.CurY := 1
	else 
	if s.CurY < 2 then
		s.CurY := ScreenHeight;

	ShowStar(s);
end;

procedure SetDirection(var s: star; dx, dy: integer);
begin
	s.dx := dx;
	s.dy := dy;
end;

var
	s: star;
	r: rect;
	c, i, j: integer;
	gameState: boolean;
begin
	clrscr;
	Randomize;

	c := 0;
	i := 200;
	j := 50;

	s.CurX := 1;
	s.CurY := 2;
	s.dx := 1;
	s.dy := 0;
	
	r.height := 3;
	r.width := 3;
	r.top := (ScreenHeight div 2) - (r.height div 2);
	r.left := (ScreenWidth div 2) - (r.width div 2);
	ShowRect(r);
	
	gameState := false;

	while true do
	begin		
		i := i - 1;
		GotoXY(ScreenWidth div 2, 1);
		write(i, ' ', j, '    ');

		if (s.CurX >= r.left) and (s.CurX < r.left + r.width)
			and (s.CurY >= r.top) and (s.CurY < r.top + r.height) then
		begin
			gameState := true;
			break;
		end
		else if (i = 0) or (j = 0) or (c = 27) or (c = 32) then
			break
		else if (i mod 10) = 0 then
		begin
			case c of
				-75: SetDirection(s, -1,  0);
				-77: SetDirection(s,  1,  0);
				-72: SetDirection(s,  0, -1);
				-80: SetDirection(s,  0,  1);
			end;
			c := 0;
		end;
		if not KeyPressed then
		begin
			MoveStar(s);
			delay(DelayDuration);
			if random(10) = 0 then
			begin
				case random(4) of
					0: if s.dx = 0 then SetDirection(s, -1,  0); {left}
					1: if s.dx = 0 then SetDirection(s,  1,  0); {right}
					2: if s.dy = 0 then SetDirection(s,  0, -1); {up}
					3: if s.dy = 0 then SetDirection(s,  0,  1); {down}
				end;
			end;
		end
		else
		begin
			j := j - 1;
			GetKey(c);		
		end;
	end;
	
	clrscr;
	GotoXY(ScreenWidth div 2, ScreenHeight div 2);
	if gameState then
		write('You won')
	else
		write('You lose');
	GotoXY(1, 1);
	readln;
	clrscr
end.
