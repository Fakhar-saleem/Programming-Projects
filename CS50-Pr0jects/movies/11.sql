SELECT movies.title
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
JOIN ratings ON movies.id = ratings.movie_id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;
