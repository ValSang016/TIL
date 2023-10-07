show databases;
use university;
select * from instructor;
select * from teaches;
select * from instructor, teaches where instructor.ID = teaches = ID;
select * from instructor natural join teaches;
select * from instructor join teaches on instructor.ID = teaches = ID;
select * from instructor join teaches using (ID);

create view faculty as select ID, name, dept_name from instructor;
select * from faculty;
select * from faculty where dept_name = 'Biology';

create view salary_dept as select dept_name, sum(salary) from instructor group by dept_name;
select * from salary_dept;
drop view salary_dept;
create view salary_dept(dept_name, total_salary) as select dept_name, sum(salary) from instructor group by dept_name;
select * from salary_dept;

drop view FC_Fall_2009;
create view FC_Fall as
select course_id, sec_id, building from section natural join course 
where semester = 'Fall' and dept_name = 'Finance';
select * from FC_Fall;

create view FC_Fall_Lamberton as
select course_id, sec_id, building from 
(select course_id, sec_id, building from section natural join course 
where semester = 'Fall' and dept_name = 'Finance') as FC_Fall2 where building = 'Lamberton';

select * from FC_Fall2; -- X view안에서 view를 선언은 안되나 봄.