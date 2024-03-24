# Write your MySQL query statement below
select distinct t1.* from Stadium t1,Stadium t2,Stadium t3
where (t1.id=t2.id-1 and t2.id=t3.id-1 or 
      t2.id=t1.id-1 and t1.id=t3.id-1 or
      t3.id=t2.id-1 and t2.id=t1.id-1) and
t1.people>=100 and t2.people>=100 and t3.people>=100
order by t1.visit_date;