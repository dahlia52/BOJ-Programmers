SELECT DISTINCT B.HISTORY_ID, 
ROUND(A.DAILY_FEE*(DATEDIFF(B.END_DATE, B.START_DATE)+1)*(100-IF(DATEDIFF(B.END_DATE, B.START_DATE)+1  < 7,0, DISCOUNT_RATE))/100,0) AS FEE
FROM CAR_RENTAL_COMPANY_CAR A
JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY B ON A.CAR_ID = B.CAR_ID
LEFT JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN C ON A.CAR_TYPE = C.CAR_TYPE 
WHERE A.CAR_TYPE = '트럭' AND
((DATEDIFF(B.END_DATE, B.START_DATE)+1 > 90 AND DURATION_TYPE LIKE '90%') OR
((DATEDIFF(B.END_DATE, B.START_DATE)+1 BETWEEN 30 AND 89) AND DURATION_TYPE LIKE '30%') OR
((DATEDIFF(B.END_DATE, B.START_DATE)+1 BETWEEN 7 AND 29) AND DURATION_TYPE LIKE '7%') OR (DATEDIFF(B.END_DATE, B.START_DATE)+1  < 7))
ORDER BY FEE DESC, HISTORY_ID DESC;
