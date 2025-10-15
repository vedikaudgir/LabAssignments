CREATE TABLE library (
    BookID INT PRIMARY KEY,
    BookName VARCHAR(100) NOT NULL,
    Author VARCHAR(50),
    Price DECIMAL(6,2) CHECK (Price > 0),
    RollNo INT,
    FOREIGN KEY (RollNo) REFERENCES Student(RollNo)
);