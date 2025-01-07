-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Query to find crime reports for July 28, 2023, on Humphrey Street.
SELECT * FROM crime_scene_reports
WHERE year = 2023 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

-- Query to search for interviews conducted around July 28, 2023, that may mention the theft.
SELECT * FROM interviews
WHERE year = 2023 AND month = 7 AND day BETWEEN 27 AND 29;

-- Query to find ATM transactions on July 28, 2023, for any suspicious account activity.
SELECT * FROM atm_transactions
WHERE year = 2023 AND month = 7 AND day = 28;

-- Query to find flights on July 28, 2023, to other cities.
SELECT f.id, a1.city AS origin_city, a2.city AS destination_city, f.year, f.month, f.day
FROM flights f
JOIN airports a1 ON f.origin_airport_id = a1.id
JOIN airports a2 ON f.destination_airport_id = a2.id
WHERE f.year = 2023 AND f.month = 7 AND f.day = 28;

-- Query to find passengers who flew on July 28, 2023, and correlate their details with potential suspects.
SELECT p.name, f.origin_airport_id, f.destination_airport_id
FROM passengers p
JOIN flights f ON p.flight_id = f.id
WHERE f.year = 2023 AND f.month = 7 AND f.day = 28;

-- Query to find phone calls on July 28, 2023, that might involve the thief or accomplice.
SELECT * FROM phone_calls
WHERE year = 2023 AND month = 7 AND day = 28;

-- Query to find security logs for suspicious activity near the crime scene on July 28, 2023.
SELECT * FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND day = 28;

