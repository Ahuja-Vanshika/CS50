-- Keep a log of any SQL queries you execute as you solve the mystery.
-- TO GET THE DESCRIPTION OF THE CRIME SCENE REPORTS FROM THE KNOWN MONTH, DAY AND STREET
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

-- TO GET THE TRANSCRIPT OF THE WITNESSES INTERVIEWED WHO MENTIONED BAKERY
SELECT name, transcript FROM interviews WHERE month = 7 AND day = 28 AND transcript LIKE '%bakery%';

-- To find All withdraws from the specific ATM referenced in 2nd Witness Transcript
SELECT * FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street';

-- To get the license plate of the thief's car
SELECT activity, license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25;

-- To get the origin airports id
SELECT * FROM airports WHERE city = 'Fiftyville';

-- To get the earliest flight destination id of the day after the robbery
SELECT flights.id, full_name, city, flights.hour, flights.minute
  FROM airports
  JOIN flights
    ON airports.id = flights.destination_airport_id
 WHERE flights.origin_airport_id =
       (SELECT id
          FROM airports
         WHERE city = 'Fiftyville')
   AND flights.year = 2023
   AND flights.month = 7
   AND flights.day = 29
 ORDER BY flights.hour, flights.minute;

-- To find Passenger Names for the flight
SELECT people.name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON flights.origin_airport_id = airports.id WHERE airports.city = 'Fiftyville'
AND flights.year = 2023 AND flights.month = 7 AND flights.day = 29 AND flights.hour = 8 AND flights.minute = 20;

-- To find the names of the caller
SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.caller
 WHERE phone_calls.year = 2023
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
 ORDER BY phone_calls.duration;

-- To find the names of the call-receiver
SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.receiver
 WHERE phone_calls.year = 2023
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
   ORDER BY phone_calls.duration;
-- the duration of the call of Bruce and Robin is same 
