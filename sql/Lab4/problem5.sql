CREATE TABLE course (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(50),
    RollNo INT,
    FOREIGN KEY (RollNo) REFERENCES student(RollNo)
);

INSERT INTO course (CourseID, CourseName, RollNo) VALUES
(501, 'course1', 1),
(502, 'course2', 3),
(503, 'course3', 1),
(504, 'course4', 4);
