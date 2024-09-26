program diamond;

procedure PrintSpaces(count: integer);
var 
    i: integer;
begin
    for i := 1 to count do
        write(' ');
end;
    
procedure PrintLineOfDiamond(k, n: integer);
begin
    PrintSpaces(n-k);
    if k <> 1 then
        write('*');
    PrintSpaces(2*k-3);
    writeln('*')    
end;

var
    n, k, h: integer;
begin
    repeat
        write('Enter the diamond''s height (possitive odd): ');
        readln(h);
    until (h > 0) and (h mod 2 = 1);   

    n := h div 2 + 1;

    for k:= 1 to n do
        PrintLineOfDiamond(k, n);

    for k := n-1 downto 1 do
        PrintLineOfDiamond(k, n)
end.

