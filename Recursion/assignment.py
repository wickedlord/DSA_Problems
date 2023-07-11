import mysql.connector
mydb = mysql.connector.connect(
    host = 'localhost',
    user = 'root',
    password = '',
    database = 'assignment 2021uic3537'
)

mycursor = mydb.cursor()

mycursor.execute("select rating, min(timestampdiff(year, dob, '2023-02-18')) as minage from sailors group by rating having count(*) > 1")

for row in mycursor:
    print(row)