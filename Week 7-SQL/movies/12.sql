SELECT movies.title
FROM movies
JOIN stars AS stars_bradley ON movies.id = stars_bradley.movie_id
JOIN stars AS stars_jennifer ON movies.id = stars_jennifer.movie_id
JOIN people AS person_bradley ON stars_bradley.person_id = person_bradley.id
JOIN people AS person_jennifer ON stars_jennifer.person_id = person_jennifer.id
WHERE person_bradley.name = 'Bradley Cooper'
  AND person_jennifer.name = 'Jennifer Lawrence';
