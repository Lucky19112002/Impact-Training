
CREATE TABLE employe(
  eid INT,
  ename VARCHAR(255),
  esalary DECIMAL(10, 2),
  mno VARCHAR(255),
  doj date,
did int);
INSERT INTO employe 
VALUES
  (1, 'RAJU', 70000.0, '8877665544', '2016-01-01',1),
  (2, 'SUNIL', 50000.0, 9657531592, '2016-01-10',2),
  (3, 'ADIL', 50000.0, '7766554433', '2016-03-01',3),
  (4, 'SRUJAN', 90000.0, 7896541236, '2016-01-01',4),
  (5, 'KAPIL', 90000.0, '90000.0','2016-02-02',4),
  (6,'Hari',90000,123,'2016-07-14',5);
  
  
  
CREATE TABLE dept (
  deptId INT,
  dname VARCHAR(255),
  location varchar(255)
);
INSERT INTO dept (deptId, dname, location)
VALUES
  (1, 'HR', 'HYD'),
  (2, 'OPERATION', 'HYD'),
  (3, 'PLACEMENT ', 'SEC'),
  (4, 'BD', 'SEC'),
  (5, 'CONTENT DEV','HYD');


# inner joint to realte ename,esalary,dname,dloc from both the tabel employeee and depetramt
select e.ename,e.esalary,d.dname,d.location from  
employe e 
inner join 
dept d 
on e.eid = d.deptId;  
# same but use left joint
select e.ename,e.esalary,d.dname,d.location from  
employe e 
left join 
dept d 
on e.eid = d.deptId; 
# same but use right joint
select e.ename,e.esalary,d.dname,d.location from  
employe e 
right join 
dept d 
on e.eid = d.deptId; 
# same but use full joint
SELECT e.ename, e.esalary, d.dname, d.location FROM employe e LEFT JOIN dept d ON e.eid = d.deptId
UNION SELECT e.ename, e.esalary, d.dname, d.location FROM employe e RIGHT JOIN dept d ON e.eid = d.deptId;
 
SELECT e.ename, e.esalary, d.ename, d.did from employe e, employe d where e.eid<>d.eid order by e.ename;
