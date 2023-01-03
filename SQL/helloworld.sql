CREATE TABLE IF NOT EXISTS Messages (message VARCHAR(12));

INSERT INTO Messages VALUES ('Hello World!');

SELECT message FROM Messages LIMIT 1;