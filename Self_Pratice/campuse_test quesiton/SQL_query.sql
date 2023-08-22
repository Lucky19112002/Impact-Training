SELECT 
    ReportTo,
    COUNT(*) AS member_count,
    AVG(age) AS average_age
FROM 
    employees
WHERE 
    ReportTo IS NOT NULL
GROUP BY 
    ReportTo
ORDER BY 
    ReportTo ASC;
