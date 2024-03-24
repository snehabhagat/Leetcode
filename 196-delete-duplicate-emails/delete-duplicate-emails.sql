# Write your MySQL query statement below
delete t1
from Person t1,Person t2
where t2.email=t1.email and t1.id>t2.id;