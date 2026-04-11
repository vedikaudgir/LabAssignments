SELECT
    *
FROM
    Student AS S
LEFT JOIN
    Course AS C
ON
    S.RollNo = C.RollNo
WHERE
    C.CourseID IS NULL;
