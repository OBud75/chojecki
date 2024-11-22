import random
game = [[" ", " ", " "], [" ", " ", " "], [" ", " ", " "]]

def is_a_win(player):
	row_1 = game [0]
	row_2 = game [1]
	row_3 = game [2]
	return any([
		all([cell == player for cell in row])
		for row in [
	(row_1[0], row_1[1], row_1[2]),
	(row_2[0], row_2[1], row_2[2]),
	(row_3[0], row_3[1], row_3[2]),
	(row_1[0], row_2[0], row_3[0]),
	(row_1[1], row_2[1], row_3[1]),
	(row_1[2], row_2[2], row_3[2]),
	(row_1[0], row_1[1], row_3[2]),
	(row_1[2], row_2[1], row_3[0])]])

def turn(player):
	for row in game:
		print(row)
	print()
	if is_a_win("X"):
		quit("X Won")
	if is_a_win("O"):
		exit("O Won")
	for row in range(3):
		y = random.randrange(3)
		for col in range(3):
			x = random.randrange(3)
			if game[x][y] == " ":
				game[x][y] = player
				if player == "X":
					turn("O")
				else:
					turn("X")

turn("X")
