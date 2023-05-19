use lucky;
select * from emp;
#1. List all the employes whos deptno is 10 and 20.
select * from emp where DEPTNO = 10 OR DEPTNO = 20; 
#2. List all the employes whos is clerk or analytic.
select * from emp where JOB in ('CLERK','ANALYST'); 
#3.List all the employes whos name start with s.
select * from emp where ENAME like 's%';
#4. List all the employes whos name second charataer is l.
select * from emp where ENAME like '_l%';
#5.List all the employes whos having execitly 5 char in there job.
select * from emp where ENAME like'_____';
#5.List all the employes whos cal is between 200 and 300
select * from emp where SAL between 200 and 300;
#6.List all the employes whos Comi is null
select * from emp where  COMI is NULL;
#7.List all the salce men in deptno 30
select * from emp where  JOB = 'SALESMAN' and DEPTNO = 30;
#8.List all the employes whos name start with s or a
select * from emp where ENAME like 's%' or ENAME like  'a%' ;
#9.List all the employes whos are not working as mamage and clserks in dept 10 ad 20 which has salary in a range of 1000 and 30000
select * from emp where  DEPTNO in (10,20) and SAL between 1000 and 3000 and JOB not in ('CLERK','MANAGER') ;
#10.List dept name the test whos dept name and location has o in them 
select * from emp where JOB like '%o%' and ENAME like '%o%' ;
#11.List all the employes by salary 
select * from emp order by SAL ;
#12.List all the employes distinct deptno. 
select distinct  DEPTNO from  emp  ;
#13.List all the employes  max sal , min sal, total sal 
select max(sal),min(sal),sum(sal) from emp ;
#14.List all the employes  sum of salary where deptid is 30
select sum(sal) from emp where DEPTNO = 30 ;
#15.List all the employes  displauay dept no with no of employs in it.
select DEPTNO,count(*)  from emp group by DEPTNO ;
#16.List all the employes  displauay dept no which are having more then 4 employes in them
select DEPTNO from emp group by DEPTNO having count(*) > 4;
# Aggergate function are used to perform mathimitical funcn on columbs
# where => row
# having => Colums
# min max avg sum & count


# sub quueries:
# select col_name from tab_name where col_name express operator(select col_name form tab_name where...);

CREATE TABLE Employees (

    ID INT,
    NAME VARCHAR(50),
    AGE INT,
    ADDRESS VARCHAR(50),
    salary int
);
CREATE TABLE Employees_tmep (
    ID INT,
    NAME VARCHAR(50),
    AGE INT,
    ADDRESS VARCHAR(50),
    salary int
);
INSERT INTO Employees VALUES (1, 'John', 20, 'US', 2008),(2, 'Stephan', 26, 'Dubai', 1500),(3, 'David', 27, 'Bangkok', 2008),(4, 'Kathrin', 34, 'Uk', 6500),(5, 'Harry', 42, 'China', 4500),(6, 'Jackson', 25, 'Mizoram', 10000),(7, 'Alina', 5, 'Banglore',8500);
insert into Employees_tmep select * from Employees where ID in (select ID from Employees); 
select * from Employees_tmep;

# update tabel set col_name = new_val where values operator (select col_name from tab_name wheer condition);
#1.get all employes whos sal is max.  
select * from emp where SAL = (select max(sal) from emp) ;
#8.List all the employes  wehre sal is> 4500
select * from emp where SAL > (select SAL from emp where SAL > 4500) ;
select * from emp where EMPNO in (select SAL from emp where SAL > 4500) ;
#8.List all the employes  
update Employees set SALARY = SALARY * 0.25 where AGE in (select age from Employees where AGE>=29);
select * from Employees;


#
CREATE TABLE company (
  DEPT_NO int,
  DNAME VARCHAR(20),
  LOC VARCHAR(20)
);


INSERT INTO company VALUES (10, 'ACCOUNTING', 'NEW YORK');
INSERT INTO company VALUES (20, 'RESEARCH', 'DALLAS');
INSERT INTO company VALUES (30, 'SALES', 'CHICAGO');
INSERT INTO company VALUES (40, 'OPERATIONS','BOSTON');
# list emply working in research dept
select * from emp where DEPTNO in (select DEPT_NO from company where DNAME = 'RESEARCH');
select * from emp;
# list emply in research and salse dept.
SELECT E_NAME FROM EMP WHERE DEPT_NO IN (SELECT DEPT_NO FROM company WHERE DNAME IN ('RESEARCH', 'SALES') );
#list dpet name which are salceman in it.

# display the emplay whoes location is having at least 1 'o' in it

SELECT ENAME FROM emp WHERE DEPTNO IN ( SELECT DEPT_NO FROM company WHERE LOC LIKE '%O%' );

#list the dept names that are having atleast 1 employ in it
select DNAME from  emp group by having count(*)>0;
# display second max salary
select max(SAL) from emp where SAL < (select max(SAL) from emp);
# display 3ed max salary
select max(SAL) from emp where SAL < (select max(SAL) from emp where SAL < (select max(SAL) from emp) );







select * from emp;
select * from company;