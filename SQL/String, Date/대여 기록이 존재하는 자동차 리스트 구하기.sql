SELECT A.CAR_ID
FROM CAR_RENTAL_COMPANY_CAR A
JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY B ON A.CAR_ID = B.CAR_ID
WHERE CAR_TYPE = '세단' AND MONTH(START_DATE) = 10
GROUP BY CAR_ID
ORDER BY CAR_ID DESC;