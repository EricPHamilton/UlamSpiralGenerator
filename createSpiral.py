from PIL import Image
import sys
width = int(sys.argv[1])

string = "";

# Load in the entire file in chunks of 4 into a string variable.
with open('output.txt', 'r') as output:
    string = output.read()

print("Read done, file closed.")

im= Image.new('RGB', (width, width), "white")

pixels = im.load()
width, height = im.size

rowCtr = 0
colCtr = 0

for letter in string:
	if letter == 'X':
		pixels[colCtr, rowCtr] = (0, 0, 0)
		colCtr += 1
	elif letter == ' ':
		colCtr += 1
	elif letter == '\n':
		rowCtr += 1
		colCtr = 0;

pixels[height/2, width/2] = (255, 0, 0)
im.save("spiral.png");

print("Complete.")
