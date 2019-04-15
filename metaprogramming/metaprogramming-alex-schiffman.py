variables = {}
outputs = {True: 'true', False: 'false'}

while True:
	try:
		line = input()
	except:
		break
	if not line: break
	line = line.split()

	if line[0] == 'define':
		variables[line[2]] = int(line[1])
	elif line[0] == 'eval':
		if line[1] in variables and line[3] in variables:
			if line[2] == '<':
				print(outputs[variables[line[1]] < variables[line[3]]])
			elif line[2] == '>':
				print(outputs[variables[line[1]] > variables[line[3]]])
			if line[2] == '=':
				print(outputs[variables[line[1]] == variables[line[3]]])
		else:
			print('undefined')
	else:
		print('help!')