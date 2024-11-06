class Person():
	def is_major(self):
		return self.age>=18
toto = Person()
toto.age = 20
titi = Person()
titi.age = 15
nana = Person()
nana.age = 56
nono = Person()
nono.age = 42


a = 1
b = 1
c = 0
d = 0

f = not(a and (not b) and (a or b)) or (not a and b) and not(a or (not b) or (not c))
g = not((c or d) and a and not(c) and d and ((not a) and c or (not d)))

s1 = a and (a or b)
s2 = (a or b) and ((not a) or b)
s3 = (a and (not b) or c) and (a or (not b))
s4 = (a  and b) or c and (not a) or (b and c) and (not b)
s5 = (a or b or c) and (not a or b or c) or (a and b) or c and d
s6 = a or b or (not c) and b or (a or not c) or not ((not a) or b or ((not a) and c))
# on peut faire le parallele avec : je ne suis pas un buveau de café et de coca, équivaut à "je ne suis pas un buveur de café ou de coca"
# priorité en 1  () et les AND  en 2 
# se referer au tableai de la loi de morgan
#S1 = 1 and (1 ou 1)
#S1 = 1 and 1
#S1 = 1

#S2 = 1 ou 1 and not 0 ou 0

#S3 = 

print(s1)
print(s2)
print(s3)
print(s4)
print(s5)
print(s6)
