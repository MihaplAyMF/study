program ColorsDemo;
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

procedure MakeLine(line, fgcolor: integer);
var
    i, j, w: integer;
begin
    w := ScreenWidth div BGColCount;
    for i := 1 to BGColCount do
    begin
        GotoXY((i-1)*w + 1, line);
        TextBackground(AllColors[i]);
        for j := 1 to w do
        begin
            if j mod 2 = 0 then
                TextColor(fgcolor + blink)
            else
                TextColor(fgcolor);
            write('*')
        end
    end 
end;

procedure MakeScreen;
var
    i: integer;
begin
    clrscr;
    for i := 1 to ScreenHeight do
        MakeLine(i, AllColors[i mod ColorCount + 1]);
end;

begin
    MakeScreen;
    ReadKey;
    {TextBackground(Black);
    TextColor(DarkGray);}
    write(#27'[0m');
    clrscr
end.
