-- Таблиця 1: Книги
CREATE TABLE books (
    book_id VARCHAR(10) PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    author VARCHAR(255) NOT NULL,
    publisher VARCHAR(255),
    publication_year INT CHECK (publication_year > 0),
    genre VARCHAR(100),
    price NUMERIC(10,2),
    copies INT DEFAULT 0 CHECK (copies >= 0)
);

-- Таблиця 2: Постачальники
CREATE TABLE suppliers (
    supplier_id VARCHAR(10) PRIMARY KEY,
    supplier_name VARCHAR(255) NOT NULL,
    supplier_address VARCHAR(255),
    supplier_phone VARCHAR(20)
);

-- Таблиця 3: Працівники
CREATE TABLE employees (
    employee_id VARCHAR(10) PRIMARY KEY,
    full_name VARCHAR(255) NOT NULL,
    position VARCHAR(100)
);

-- Таблиця 4: Зв’язок між книгами, постачальниками і працівниками
CREATE TABLE deliveries (
    book_id VARCHAR(10),
    supplier_id VARCHAR(10),
    employee_id VARCHAR(10),
    delivery_date DATE DEFAULT CURRENT_DATE,
    quantity INT CHECK (quantity > 0),

    PRIMARY KEY (book_id, supplier_id, employee_id),
    FOREIGN KEY (book_id) REFERENCES books(book_id),
    FOREIGN KEY (supplier_id) REFERENCES suppliers(supplier_id),
    FOREIGN KEY (employee_id) REFERENCES employees(employee_id)
);

-- sudo systemctl enable postgresql
-- sudo systemctl start postgresql
-- sudo -i -u postgres

-- CREATE USER miha WITH PASSWORD 'тут_твій_пароль';
-- CREATE DATABASE knuharnia OWNER miha;
-- GRANT ALL PRIVILEGES ON DATABASE knuharnia TO miha;

-- Надати право використовувати схему public
--GRANT USAGE ON SCHEMA public TO miha;

-- Дозволити створювати таблиці у схемі public
-- GRANT CREATE ON SCHEMA public TO miha;

-- (Опціонально) зробити miha власником схеми
-- ALTER SCHEMA public OWNER TO miha;
-- psql -U miha -d knuharnia
