# Write your MySQL query statement below
select t2.name as Department, t1.name as Employee, t1.salary as Salary
from Employee t1 
join Department t2
on t1.departmentId=t2.id
where (t1.Salary,t1.departmentId) in(select max(salary),departmentId from Employee group by departmentId);