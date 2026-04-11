USE StudentDB;

CREATE TABLE Student(
RollNo INT auto_increment PRIMARY KEY,
Name VARCHAR(50),
Class VARCHAR(50),
Marks INT
);

INSERT INTO Student(Name, Class, Marks)
VALUES('s1','c1',20),
('s2','c2',80),
('s3','c1',90),
('s4','c1',100),
('s5','c2',0);

SELECT * FROM Student;

CREATE TABLE Teachers(
EmployeeAddress INT auto_increment primary key,
Name varchar(50),
email varchar(50),
subject varchar(50)
);

insert into Teachers(Name, email, subject)
value('Teacher1','1@gmail.com','Maths'),
	 ('Teacher2','2@gmail.com','Physics'),
     ('Teacher3','3@gmail.com','Chemistry');

select * from Teachers;