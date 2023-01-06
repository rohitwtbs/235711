# write crud operations 
# for postgresql using ORM
# and also write without orm

import psycopg2

connection = psycopg2.connect(host='localhost',database='***',user='***',password='****')

cursor = connection.cursor()

cursor.execute("select * from users")
# how would you define a cursor
# explain the cursor object here
for query in cursor:
    print(str(query))