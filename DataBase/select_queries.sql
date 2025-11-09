-- Показати назву книги, постачальника і працівника, який прийняв поставку
SELECT 
    b.title AS "Назва книги",
    s.supplier_name AS "Постачальник",
    e.full_name AS "Працівник",
    d.delivery_date AS "Дата поставки",
    d.quantity AS "Кількість"
FROM deliveries d
JOIN books b ON d.book_id = b.book_id
JOIN suppliers s ON d.supplier_id = s.supplier_id
JOIN employees e ON d.employee_id = e.employee_id;

-- Показати книги певного жанру
SELECT title, author, genre FROM books WHERE genre = 'Фантастика';

-- Підрахунок кількості примірників усіх книг
SELECT SUM(copies) AS "Загальна кількість книг" FROM books;
