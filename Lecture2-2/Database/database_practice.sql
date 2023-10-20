show databases;
use university;
select * from student;
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

select * from faculty;
insert into faculty values (11111, 'choi', 'Finance');
select * from instructor;


drop view instructor_info;
select * from instructor natural join department;
create view instructor_info as
select ID, name, building from instructor natural join department;
select * from instructor_info;
insert into instructor_info values ('69987', 'white', 'Taylor'); -- X

select * from instructor where dept_name = 'Finance';
create view instructor_FC as select * from instructor where dept_name = 'Finance';
insert into instructor_FC values ('25561', 'Brown', 'Biology', '100000');
select * from instructor_FC; -- 위의 insert에 오류른 없으나 반영되지 않음 
select * from instructor where dept_name = 'Biology'; -- 하지만 original DB에는 반영됨!!

select curdate();

select * from takes;
SELECT *
FROM student
LEFT JOIN takes ON student.ID = takes.ID
LEFT JOIN course ON takes.course_id = course.course_id;
select * from instructor;

desc instructor;
select * from grade_points;
delete from instructor where ID = '43779';

select * from (takes natural join course) NATURAL LEFT JOIN grade_points;
select * from student natural join (select ID, sum(credits) from takes natural join course group by ID) as K;
select takes.ID, avg(points) as GPA from takes join grade_points using (grade) natural join student  group by ID;

select ID, credit_points / if(credit_sum = 0, null, credit_sum)
from  (
select ID, sum(if(grade is null, 0, credits)) as credit_sum,
		sum(if(grade is null, 0, credits * points)) as credit_points 
        from takes natural join course
        natural left join grade_points 
        group by ID
union
select ID, null, null from student
where ID not in (select ID from takes)) as derived_table;

select year, sum(credits)
from takes natural join course
group by year
order by year;

create view tot_credits(year, num_credits) as
select year, sum(credits)
from takes natural join course
group by year
order by year;

select * from tot_credits;

select * from takes full join takes using (ID);

select * from section;
select course_id from section as S where year= '2005' and
exists (select *
from section as T where year= '2002' and
S.course_id= T .course_id);

drop table grade_points;
select * from grade_points;
delete from grade_points;
alter table grade_points drop grade;
alter table grade_points add grade varchar(5);

select 'A' from takes;
select building from department where building like '___%';
select building from department group by building;

select count(*) from student  join instructor;

select date_format(curdate(),'%m/%d/%y') today;
create index stID on student(ID);

select * from student where stID = "1018";