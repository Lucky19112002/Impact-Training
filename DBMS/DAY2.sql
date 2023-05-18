create database lucky;
use lucky;

create table emp (
	EMPNO int primary key,
    ENAME varchar(50),
    JOB varchar(50),
    MGR int,
    HIREDATE date,
    SAL int,
    COMI int,
    DEPTNO int);
    
INSERT INTO emp (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMI, DEPTNO)
VALUES
    (7369, 'SMITH', 'CLERK', 7982, '1988-12-17', 800, NULL, 20),
    (7499, 'ALLEN', 'SALESMAN', 7698, '1981-02-20', 1680, 300, 30),
    (7521, 'WARD', 'SALESMAN', 7698, '1981-02-22', 1250, 500, 30),
    (7566, 'JONES', 'MANAGER', 7839, '1981-04-02', 2975, NULL, 20),
    (7654, 'MARTIN', 'SALESMAN', 7698, '1981-09-28', 2450, 1400, 30),
    (7698, 'BLAKE', 'MANAGER', 7839, '1981-05-01', 3000, NULL, 30),
    (7782, 'CLARK', 'MANAGER', 7839, '1981-06-09', 5000, NULL, 10),
    (7788, 'SCOTT', 'ANALYST', 7566, '1987-04-19', 1500, NULL, 20),
    (7839, 'KING', 'PRESIDENT', 0, '1981-11-17', 5000, NULL, 10),
    (7844, 'TURNER', 'SALESMAN', 7698, '1981-09-08', 1100, NULL, 20),
    (7876, 'ADAMS', 'CLERK', 7788, '1987-05-23', 950, NULL, 20),
    (7900, 'JAMES', 'CLERK', 7698, '1981-12-01', 950, NULL, 30),
    (7982, 'FORD', 'ANALYST', 7566, '1982-01-23', 3000, NULL, 20),
    (7934, 'MILLER', 'CLERK', 7782, '1982-01-23', 1300, NULL, 10);

    select * from emp;