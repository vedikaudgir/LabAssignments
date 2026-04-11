SELECT
    N.Name,
    C.CourseName
FROM
    student AS N
INNER JOIN
    course AS C
ON
    N.RollNo = C.RollNo;
