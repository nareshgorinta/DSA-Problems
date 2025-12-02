# Write your MySQL query statemen

select p.project_id,sum(e.experience_years)/count(*) as average_years from Project p left join Employee e on p.employee_id = e.employee_id group by p.project_id;