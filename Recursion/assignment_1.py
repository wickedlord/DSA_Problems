import mysql.connector
mydb = mysql.connector.connect(
    host = 'localhost',
    user = 'root',
    password = '',
    database = 'assignment_1'
)

mycursor = mydb.cursor()

mycursor.execute("select distinct s.name from sailors s, reserves r, boats b where s.sid = r.sid and r.bid = b.bid and (b.color = 'red' or b.color = 'green')")

for row in mycursor:
    print(row)

#select distinct s.name from sailors s, reserves r, boats b where s.sid = r.sid and r.bid = b.bid and (b.color = 'red' or b.color = 'green') and month(r.day) = '3'