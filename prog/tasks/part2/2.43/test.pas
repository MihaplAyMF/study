
program SplitIntoWordsWithPointers;

uses SysUtils;

const
  MaxWords = 10; // Максимальна кількість слів

type
  PCharArray = array[1..MaxWords] of ^Char; // Масив вказівників на символи

var
  userInput: string;      // Вхідний рядок від користувача
  wordPointers: PCharArray; // Масив вказівників на слова
  wordCount: integer;     // Кількість слів
  i, wordStart: integer;  // Лічильники для циклів

begin
  writeln('Введіть рядок:');
  readln(userInput);

  wordCount := 0;
  wordStart := 1; // Починаємо з першого символу рядка

  for i := 1 to Length(userInput) + 1 do
  begin
    // Перевірка на пробіл або кінець рядка
    if (i > Length(userInput)) or (userInput[i] = ' ') then
    begin
      if wordStart <= i - 1 then
      begin
        Inc(wordCount); // Збільшуємо кількість слів
        wordPointers[wordCount] := @userInput[wordStart]; // Вказівник на початок слова
        userInput[i] := #0; // Завершуємо слово нульовим символом (відділяємо його від наступного)
      end;
      wordStart := i + 1; // Оновлюємо початок наступного слова
    end;
  end;

  // Виведення всіх слів через вказівники
  writeln('Слова у рядку:');
  for i := 1 to wordCount do
    writeln(wordPointers[i]^);  // Розіменовуємо вказівник і виводимо слово
end.
