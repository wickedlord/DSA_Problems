import mysql.connector
mydb = mysql.connector.connect(
    host = 'localhost',
    user = 'root',
    password = '',
    database = 'assignment 2021uic3537'
)

mycursor = mydb.cursor()

mycursor.execute("select rating, timestampdiff(year, dob , '2023-02-17') as age from sailors where dob <= all(select dob from sailors)")

for row in mycursor:
    print(row)