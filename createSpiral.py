from PIL import Image
import sys
width = int(sys.argv[1])

im= Image.new('RGB', (width, width), "white")
pixels = im.load()
width, height = im.size

rowCtr = 0
colCtr = 0

with open('output.txt', 'r') as output:
    for line in output:
        for letter in line:
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
