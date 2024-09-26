
program prog;

type
	pair = record
		a: integer;
		b: real;
	end;
	
	twoptrsPtr = ^twoptrs;
	twoptrs = record
		g, h: ^pair;
		t: ^integer;
	end;

procedure prog1(p: twoptrsPtr);
begin
	writeln(p^.g^.a);
	writeln(p^.g^.b);
	writeln(p^.h^.a);
	writeln(p^.h^.b);
	writeln(p^.t^);
end;

var
	tp2: twoptrs;
	m, n: pair;
	x: integer;
begin
	m.a := 1;
	m.b := 2.5;
	n.a := 3;
	n.b := 4.5; 
	x := 5;

	tp2.g := @m;
	tp2.h := @n;
	tp2.t := @x;

	prog1(@tp2);  // Передача вказівника на tp2

end.

