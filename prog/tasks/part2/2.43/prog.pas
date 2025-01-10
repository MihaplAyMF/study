program prog;

cosnt
    MaxWords = 100;

type 
    PCharArray = array[1..MaxWords] of ^char;

var 
    userInput: string; 
    wordPointers: PCharArray;
    currentWord: string
    i: integer;
begin
    write('Input line: ');
    readln(userLine);
   
    currentWord := '';

    for i := 1 to length(userLine) do
    begin
        if userLine[i] <> ' ' then
            currentWord := currentWord + userLine;
        else
        begin
            wordPointes[] := 
        end;
    end;

    write(line);

end.
