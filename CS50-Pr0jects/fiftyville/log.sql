-- Query 1: Retrieving interview transcripts for July 28
-- Description: This query fetches the transcript of interviews conducted on July 28.
SELECT transcript FROM interviews WHERE month = 7 AND day = 28;

-- Query 2: Retrieving crime scene report for Humphrey Street on July 28
-- Description: This query fetches the crime scene report for the location "Humphrey Street" on July 28.
SELECT description FROM crime_scene_reports
    WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

-- Query 3: Retrieving bakery exit logs for a specific time on July 28
-- Description: This query retrieves the activity of individuals exiting the bakery between 10:15 AM and 10:25 AM on July 28, 2021.
SELECT name FROM people
    JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
    WHERE day = "28" AND month = 7 AND year = 2021 AND hour = 10 AND minute >= 15 AND minute < 25 AND activity = 'exit';

-- Query 4: Retrieving bakery security log for 10:20 AM on July 28
-- Description: This query retrieves the activity from the bakery security logs at 10:20 AM on July 28, 2021.
SELECT activity FROM bakery_security_logs
    WHERE month = 7 AND day = 28 AND hour = 10 AND minute = 20;

-- Query 5: Retrieving ATM withdrawal transactions on Leggett Street on July 28, 2021
-- Description: This query identifies people who made ATM withdrawals on Leggett Street on July 28, 2021.
SELECT name FROM people
    JOIN bank_accounts on people.id = bank_accounts.person_id
    JOIN atm_transactions on bank_accounts.account_number = atm_transactions.account_number
    WHERE day = 28 AND year = 2021 AND month = 7 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw';

-- Query 6: Retrieving people who received phone calls lasting less than 60 seconds on July 28, 2021
-- Description: This query retrieves names of people who received phone calls lasting less than 60 seconds on July 28, 2021.
SELECT name FROM people
    JOIN phone_calls ON people.phone_number = phone_calls.receiver
    WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60;

-- Query 7: Retrieving people who made phone calls lasting less than 60 seconds on July 28, 2021
-- Description: This query retrieves names of people who made phone calls lasting less than 60 seconds on July 28, 2021.
SELECT name FROM people
    JOIN phone_calls ON people.phone_number = phone_calls.caller
    WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60;

-- Query 8: Retrieving people who received a call from Bruce on July 28, 2021, lasting less than 60 seconds
-- Description: This query identifies individuals who received calls from Bruce on July 28, 2021, lasting less than 60 seconds.
SELECT name FROM people
    JOIN phone_calls ON people.phone_number = phone_calls.receiver
    WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60 AND caller = (SELECT phone_number FROM people WHERE name = "Bruce");

-- Query 9: Retrieving the destination city of a flight
-- Description: This query retrieves the destination city of the flight with ID 36.
SELECT city FROM airports
    WHERE id = (SELECT destination_airport_id FROM flights WHERE flights.id = 36);

-- Query 10: Retrieving the first flight departure time on July 29, 2021
-- Description: This query retrieves the earliest flight departure time on July 29, 2021.
SELECT hour, minute FROM flights
    WHERE year = 2021 AND day = 29 AND month = 7 ORDER BY hour, minute LIMIT 1;

-- Query 11: Retrieving the flight ID for the flight departing at 8:20 AM
-- Description: This query retrieves the flight ID for the flight departing at 8:20 AM.
SELECT id FROM flights WHERE hour = 8 AND minute = 20;

-- Query 12: Retrieving the names of people on flight 36
-- Description: This query retrieves the names of passengers on flight 36.
SELECT name FROM people
    JOIN passengers on people.passport_number = passengers.passport_number
    JOIN flights on passengers.flight_id = flights.id
    WHERE passengers.flight_id = 36;
