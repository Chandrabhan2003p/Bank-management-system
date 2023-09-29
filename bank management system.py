import mysql.connector
con=mysql.connector.connect(host='localhost',user='root',passwd='mysql@123')

cur=con.cursor()
# create database

cur.execute("create database if not exists bank")
cur.execute('use bank')

# create Bank table

cur.execute("create table  if  not exists  Account(name varchar(50),acno varchar(12)  primary key ,dob varchar(50),address varchar(100),phone varchar(12) unique key,opening_balance int)")
	
# create Amount table

cur.execute("create table if not exists Amount(acno varchar(12),name varchar(50),balance int)")

# 1.open account in bank
print("""********** Bank Management System**********""" )

def Acopen():
	n=input("Enter customer name :")
	ac=int(input("Enter account no. :"))
	d=input("Enter date of birth :")
	a=input("Enter address ")
	p=int(input("Enter phone no :"))
	bal=int(input("Enter open balance :"))
	cur.execute("insert into Account values('{}',{},'{}','{}',{},{})".format(n,ac,d,a,p,bal))
	cur.execute("insert into Amount values({},'{}',{})".format(ac,n,bal))
	con.commit()
	print(""" Account successfully open """)
	main()
	

# 2. Amount deposit 

def  amtdepo():
	ac=int(input("enter account no. "))
	am=int(input("enter amt :"))

	a="select balance  from Amount where acno=%s"
	data=(ac,)
	cur.execute(a,data)
	myresult=cur.fetchone()
	tam=myresult[0]+am
	sql="update Amount  set balance=%s where acno=%s"
	d=(tam,ac)
	cur.execute(sql,d)
	con.commit()
	print(""" Transaction complited successfully""")
	main()
	
#3. Amount withdraw

def  amtwith():
	ac=int(input("enter account no. "))
	am=int(input("enter amt :"))
	
	a="select balance  from Amount where acno=%s"
	data=(ac,)
	cur.execute(a,data)
	myresult=cur.fetchone()
	tam=myresult[0]-am
	sql="update Amount  set balance=%s where acno=%s"
	d=(tam,ac)
	cur.execute(sql,d)
	con.commit()
	print(""" Transaction complited successfully""")
	main()
	
# 4. check balance

def bal():
	ac=int(input("enter account no. :"))
	cur.execute("select * from Amount where acno={}".format(ac))
	search=cur.fetchall()

	for i in search:
		print(i)
	
	main()
# 5. customer details

def cusdetail():
		found=0
		try:
			ac=int(input("enter account no. :"))
			cur.execute("select * from Account where acno={}".format(ac))
			search=cur.fetchall()
			for i in search:
				print(i)
				found=1
		except:
			print(" ")
		if found==0:
			print("""--------------Invalid Account Number !!!!!----------------""")
		main()
		
#6. closing account	
def  acclose():
	ac=int(input("enter account no. :"))
	cur.execute("delete from Account where acno={}".format(ac))
	cur.execute("delete from Amount where  acno={}".format(ac))
	
	con.commit()
	print(""" Account delete successfully""")
	
		
	main()
	
	
def main():
	

	print("""
	1.Open Acount in bank
	2.Amount deposit in bank
	3.Amount withdraw from bank
	4.Check balance 
	5.Show customer detail
	6.Closing account from bank""")
	ch=int(input("enter your choice :"))
	if ch==1:
		Acopen()
		
	elif ch==2:
		amtdepo()
		
	elif ch==3:
		amtwith()
		
	elif ch==4:
		bal()
		
	elif ch==5:
		cusdetail()
		
	elif ch==6:
		acclose()
		
	else:
		print("invalid choice........")
	
main()