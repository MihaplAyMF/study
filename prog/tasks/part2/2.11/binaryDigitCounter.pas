program binaryDigitCaunter;

function CountOnes(num: longint): integer;
var
  count: integer;
begin
  count := 0;
  
  while num <> 0 do
  begin
    if (num and 1) = 1 then
      count := count + 1; // Якщо біт дорівнює 1, збільшуємо лічильник
    
    num := num shr 1;
  end;
  
  CountOnes := count;
end;

var
	num: longint;
	count: integer;
begin
	write('Input number ');
	readln(num);
	count := CountOnes(num); 
	writeln(count)
end.
